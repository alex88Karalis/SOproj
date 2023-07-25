#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ncurses.h>

// Definiamo la struttura per la cella della matrice
struct Cell {
    char character;
    int foregroundColor;
    int backgroundColor;
};

// Definiamo la struttura per i dati della rana
struct FrogData {
    int x;
    int y;
    int id;
    int type;
};

void rana(int* pipefd);
void disegnatore(int* pipefd);

int main() {
    
    // Inizializziamo la ncurses
    initscr();
    curs_set(0); // Nascondiamo il cursore

    // Creiamo la pipe per la comunicazione tra i processi
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Errore nella creazione della pipe");
        return 1;
    }

    // Creiamo il processo disegnatore
    pid_t disegnatore_pid = fork();
		
		// controllo su fork
    if (disegnatore_pid == -1) {
        perror("Errore nella creazione del processo disegnatore");
        return 1;
    } 
    else{
    	if (disegnatore_pid == 0) {
        // Processo disegnatore
				disegnatore(pipefd);
    	}
    	else {
        // Siamo nel processo padre

        // Creiamo il processo rana
        pid_t rana_pid = fork();

        if (rana_pid == -1) {
            perror("Errore nella creazione del processo rana");
            return 1;
        } 
        else{
        	if (rana_pid == 0) {
            // Processo rana
            rana(pipefd);
            // Terminiamo il processo rana
            return 0;
         	}
         	else {
            // Siamo ancora nel processo padre

            // Chiudiamo entrambi i lati della pipe, poiché non la useremo nel processo padre
            close(pipefd[0]);
            close(pipefd[1]);

            // Aspettiamo che il processo disegnatore e il processo rana terminino
            wait(NULL);
            wait(NULL);

            // Terminiamo il processo padre
            return 0;
        	}
    		}
    	}
    }

    return 0;
}



void rana(int* pipefd){
	// Chiudiamo il lato della pipe in lettura perché la rana scrive sulla pipe
  close(pipefd[0]);
						
	// inizializzazione rana
  struct FrogData frogData;
  frogData.x = 6;
  frogData.y = 6;
  frogData.id = 0;
  frogData.type = 0;
	
	// input
	char input;
	
  // Ciclo della rana per leggere l'input e scrivere sulla pipe
  do {
		// Leggiamo l'input dalla tastiera
    input = getch();

    // Leggi l'input della tastiera per muovere la rana
    switch (input) {
    	case KEY_LEFT:
      	// Freccia sinistra premuta, spostiamo la rana a sinistra
        if (frogData.x > 0) {
        	frogData.x--;
        }
        break;
			case KEY_RIGHT:
				// Freccia destra premuta, spostiamo la rana a destra
					if (frogData.x < 103) {
						frogData.x++;
					}
					break;
			case KEY_UP:
				// Freccia su premuta, spostiamo la rana verso l'alto
				if (frogData.y > 0) {
					frogData.y--;
				}
				break;
			case KEY_DOWN:
				// Freccia giù premuta, spostiamo la rana verso il basso
				if (frogData.y < 36) {
					frogData.y++;
				}
				break;
      default:
      	// Se viene premuto un altro tasto, ignoriamo l'input
        break;
    	}
        
      // si scrive in pipe la rana
      if (write(pipefd[1], &frogData, sizeof(struct FrogData)) == -1) {
      	perror("Errore nella scrittura sulla pipe");
        break;
      }
	}while(input!='q');
}


void disegnatore(int* pipefd){
	// Chiudiamo il lato della pipe in scrittura perché il disegnatore legge dalla pipe
  close(pipefd[1]);

  // Inizializziamo la matrice per lo schermo
  struct Cell screenMatrix[37][104];

  // Ciclo di inizializzazione della matrice a schermo (tutte le celle bianche)
  for (int i = 0; i < 37; i++) {
  	for (int j = 0; j < 104; j++) {
    	screenMatrix[i][j].character = ' ';
      screenMatrix[i][j].foregroundColor = COLOR_WHITE;
      screenMatrix[i][j].backgroundColor = COLOR_BLACK;
    }
  }

  // Eseguiamo il ciclo del disegnatore per leggere dalla pipe e aggiornare lo schermo
  while (1) {
  	// Leggiamo i dati dalla pipe
    struct FrogData frogData;
    if (read(pipefd[0], &frogData, sizeof(struct FrogData)) == -1) {
    	perror("Errore nella lettura dalla pipe");
    	break;
    }

    // Aggiorniamo la matrice dello schermo con i dati ricevuti dalla rana
   	screenMatrix[frogData.y][frogData.x].character = 'R';
    screenMatrix[frogData.y][frogData.x].foregroundColor = COLOR_GREEN;
    screenMatrix[frogData.y][frogData.x].backgroundColor = COLOR_BLACK;

    // Ora aggiorniamo la schermata con la matrice aggiornata
    for (int i = 0; i < 37; i++) {
    	for (int j = 0; j < 104; j++) {
      	struct Cell cell = screenMatrix[i][j];
        attron(COLOR_PAIR(cell.foregroundColor));
        mvaddch(i, j, cell.character);
        attroff(COLOR_PAIR(cell.foregroundColor));
        // Imposta il colore di sfondo dopo la stampa del carattere
        if(cell.backgroundColor != COLOR_BLACK) {
        	bkgdset(COLOR_PAIR(cell.backgroundColor));
        }
      }
    }

    // Refresh per aggiornare il display
    refresh();
  }

 	// Chiudiamo la finestra di ncurses e terminiamo il processo disegnatore
  endwin();
  return;
}




