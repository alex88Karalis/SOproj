#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define TIMEBAR 1
#define SFONDO 2

int main() {
    // Inizializza ncurses
    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    // Imposta il colore per la barra del tempo
    init_pair(TIMEBAR, COLOR_WHITE, COLOR_GREEN);
		init_pair(SFONDO,COLOR_WHITE,COLOR_BLACK);
    // Durata della barra (in secondi)
    int duration = 20;

    // Inizializza il timer
    time_t start_time = time(NULL);
		int tempo_rimanente=duration;
    while (tempo_rimanente>0) {
        // Calcola il tempo trascorso
        time_t current_time = time(NULL);
        int delta_time = current_time - start_time;
				mvprintw(7,0,"tempo rimanente: %d",tempo_rimanente);
        // Calcola la lunghezza della barra proporzionale al tempo rimanente
        tempo_rimanente = duration - delta_time;
        int bar_length = duration-delta_time;
        
        // sovrascrive barra con riga nera
        attron(COLOR_PAIR(SFONDO));
        for (int i = 0; i < 40; ++i) {
            mvaddch(6, i, ' ');
        }
        attroff(COLOR_PAIR(SFONDO));

        // Disegna la barra verde
        attron(COLOR_PAIR(TIMEBAR));
        for (int i = 0; i < bar_length; ++i) {
            mvaddch(6, i, ' ');
        }
        attroff(COLOR_PAIR(TIMEBAR));

        // Mostra il risultato sullo schermo
        refresh();

        // Aspetta 1 secondo prima di aggiornare la barra
        sleep(1);
    }

    // Attendi l'input dell'utente per uscire
    getch();

    // Ripristina lo stato iniziale e termina ncurses
    endwin();
    return 0;
}

