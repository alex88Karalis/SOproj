#include <ncurses.h>
#include "upscreenlib.h"

void inizializzaNcurses();

int main() {
    
    inizializzaNcurses();
    
    char exitCode;
    
    do{
    
    	coloraSchermo();
    	
    	// Mostra il risultato sullo schermo
    	refresh();
    	
    	// Attendi l'input dell'utente per uscire
    	exitCode= getch();
    	
    }while(exitCode!='q');

    // Ripristina lo stato iniziale e termina ncurses
    endwin();
    
    return 0;
}

void inizializzaNcurses(){
	// Inizializza ncurses
    initscr();
    start_color(); // inizializza colori
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
	
}


