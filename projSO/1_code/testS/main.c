#include <curses.h>
#include "game.h"

#define MAXX 80 	/* Numero di colonne dello schermo */
#define MAXY 24 	/* Numero di righe dello schermo */

#define FROG_COLOR    1
#define FROG2_COLOR    2
#define BACK 3

struct posizione {
	int x;		// coordinata x
	int y;		// coordinata y
	char sprite[2][3];
}; 

void stampaSprite(int x,int y, char sprite[2][3]);

int main()
{
	initscr();  			/* Inizializza lo schermo */
	noecho(); 			/* Disabilita la visualizzazione dei tasti premuti */  
	keypad(stdscr, 1); 		/* Abilita la gestione dei tasti freccia */ 
	curs_set(0); 			/* Nasconde il cursore */
	start_color();		/* Abilita l'uso dei colori*/
	
	show_initial_screen(); // shermata iniziale
	
	/* Inizializzazione colori*/
	init_pair(FROG_COLOR, COLOR_GREEN, COLOR_BLACK);	/* frog color*/
	init_pair(FROG2_COLOR, COLOR_WHITE, COLOR_BLACK);	/* frog2 color*/
	init_pair(BACK,COLOR_WHITE,COLOR_BLACK); /* colore sfondo*/
	
	bkgd(COLOR_PAIR(BACK));
	
	struct posizione oggetto = { 
		MAXX/2, MAXY/2,  
		{{'\\' , '.' , '/'},
		{'/', '-' , '\\'}}  
	};
	
	

	/* Prima visualizzazione al centro */
	stampaSprite(oggetto.x,oggetto.y,oggetto.sprite);
	refresh();

	while(true){
		int c = getch();
		switch(c) {  
			case KEY_UP:
				if(oggetto.y > 0) 
					oggetto.y -= 1; 
				break;

			case KEY_DOWN:
				if(oggetto.y < MAXY - 2) 
					oggetto.y += 1;  
				break;

			case KEY_LEFT:
				if(oggetto.x > 0) 
					oggetto.x -= 1;  
				break;

			case KEY_RIGHT:
				if(oggetto.x < MAXX - 3) 
					oggetto.x += 1;  
				break;

			case 113: /* Tasto 'q' */
				endwin();
				exit(0);
		}

		clear();
		
		stampaSprite(oggetto.x,oggetto.y,oggetto.sprite);
		refresh();
	}
}


void stampaSprite(int x,int y, char sprite[2][3]){
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			attron(COLOR_PAIR(FROG_COLOR)); /* attivazione colore frog*/
			mvaddch(y+i, x + j,sprite[i][j]);
			fflush(NULL);
		}
	}
	attroff(COLOR_PAIR(FROG_COLOR)); /* disattivazione colore frog*/
	
}
