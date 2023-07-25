#include <ncurses.h>
#include "upscreenlib.h"




void Tana(){
	for(int col=0; col<20; col++){
		
	}
	
}


void DisegnaTane(int width){
	int start_y = 3;
	
	int freqTane = NUM_COLS/NUM_TANE ; // ogni quanti char c'è una tana
	int colsTana = 9;									// larghezza tana (numero di char)
	int rowTana = 3; 							// altezza delle tane
	int rowTotal = rowTana+2; 	// altezza totale col bordo superiore
	
	
	// colora tane
    	for(int row=start_y ;row < start_y+rowTotal; row++){
    		mvchgat(row, 0, width, A_NORMAL, TANE, NULL);
    	}
    	
    	bool tana=true;
    	for(int col=0;col<width;col++){
    		if(col%(freqTane -colsTana)==0){
    			tana=!tana;
    		}
    		if(!tana){
    			attron(COLOR_PAIR(FIUME));
        	mvaddch(rowTana+2, col,' ');
        	mvaddch(rowTana+3,col,' ');
        	mvaddch(rowTana+4,col,' ' );
        	attroff(COLOR_PAIR(FIUME));
    		}
    			
    	}
}// end DisegnaTane

void DisegnaHUD(int width){
	int score = 10;
	char* widthSize = "Larghezza: %3d";
	attron(COLOR_PAIR(HUD));
	
	move(0,0); // sposta cursore a inizio riga
	clrtoeol(); // pulisce tutta la riga a destra del cursore
	
	mvprintw(0,1, widthSize, width );						// stampa larghezza della finestra
	mvprintw(0, width/2, "SCORE: %3d", score);  //stampa punteggio
}


void Tronco(int row){
	int troncoLenght=8;
	
	SpriteTronco t = {{"~ ~ ~ ~ "," ~ ~ ~ ~"}};
	
	attron(COLOR_PAIR(TRONCHI));
	//for(){}
	mvchgat(row, 0, troncoLenght, A_NORMAL, TRONCHI, NULL);
	//mvchgat(row+1, 0, troncoLenght, A_NORMAL, TRONCHI, NULL);
	for(int col=0; col<troncoLenght; col++){
		if(col%2==0){
			mvaddch(row,col,'~');
		}	
	}
	
	mvprintw(row, 15, t.sprite);
	
}





void DisegnaTronchi(int width){
	int rowFiume=10;		// grande 10 righe
	int startFiume= 9;  		//inizia alla riga 9
	int endFiume= startFiume + rowFiume; //termina alla riga 19
	
	Tronco(10);
	
	//for(int row = startFiume; row < endFiume; row++){}
}













