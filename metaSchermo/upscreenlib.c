#include "upscreenlib.h"

// colora il marciapiede
void coloraMarciapiede(){
	
	int row_end = ROWMARCIAPIEDE + NRMARCIAPIEDE;
	
  for (int row = ROWMARCIAPIEDE; row < row_end; row++) {
		mvchgat(row, COLSTART, COLEND, A_NORMAL, MARCIAPIEDE, NULL);
	}
	
	return;
}

// colora il prato
void coloraPrato(){
	
	int row_end = ROWPRATO + NRPRATO;
  
  for(int row=ROWPRATO; row<row_end; row++){
  	mvchgat(row, COLSTART, COLEND, A_NORMAL, PRATO, NULL);
  }
  
  return;
}

// colora fiume
void coloraFiume(){
	
	int row_end = ROWFIUME + NRFIUME;
	
  for(int row = ROWFIUME; row < row_end; row++){
  	mvchgat(row, COLSTART, COLEND, A_NORMAL, FIUME, NULL);
  }
  
  return;
}

// colora la striscia autostradale
void coloraStriscia(){
  
  // disegna linea stradale
  mvchgat(ROWSTRISCIA, COLSTART, COLEND, A_NORMAL, STRISCIA, NULL);
    	
  // disegna spazi in striscia stradale
  attron(COLOR_PAIR(SFONDO));
  for (int col = COLSTART; col < COLEND; col++) {
  	if(col % GAP == 0){
      mvaddch(ROWSTRISCIA, col,' ');
    }
	}
	attroff(COLOR_PAIR(SFONDO));
	
	return;
}

// colora le tane
void coloraTane(){
	
	int row_end = ROWTANE + NRFIUME;

	for(int row = ROWTANE; row < row_end; row++){
		mvchgat(row, COLSTART, COLEND, A_NORMAL, TANE, NULL);
	}
    	
  bool tana=true;
  for(int col = COLSTART; col < COLEND; col++){
  	// magic number meglio usare una macro
  	if(col % 9 == 0){
    	tana=!tana;
    }
    		
    if(!tana){
    	attron(COLOR_PAIR(FIUME));
    	
      // magic numbers da modificare, magari con delle macro
      mvaddch(6, col,' ');
      mvaddch(7,col,' ');
      mvaddch(8,col,' ' );
      
      attroff(COLOR_PAIR(FIUME));	
    }
    			
	}

	return;
}

void coloraSchermo(){

	

	// imposta la dimensione della finestra di gioco
  resize_term(NUM_ROWS, NUM_COLS); 
	
	// Imposta i colori utilizzati
  init_pair(MARCIAPIEDE, COLOR_BLACK, COLOR_WHITE);
	init_pair(SFONDO,COLOR_WHITE,COLOR_BLACK);
	init_pair(PRATO,COLOR_WHITE,COLOR_GREEN);
	init_pair(FIUME,COLOR_WHITE,COLOR_BLUE);
	init_pair(TANE,COLOR_RED,COLOR_YELLOW);
	init_pair(STRISCIA,COLOR_BLACK,COLOR_WHITE);
	init_pair(TIME,COLOR_BLACK,COLOR_GREEN);
		
	// colora marciapiede
  coloraMarciapiede();
    	
  // colora il prato
  coloraPrato();
    	
  // colora il fiume
  //coloraFiume();
    	
  // colora strisce
  coloraStriscia();
    	
  // colora tane
  //coloraTane();
  
  // stampa tempo
  stampaTempo();
  
  return;
}

void stampaTempo(){

	// Durata della barra (in secondi)
  int duration = 20;

  // Inizializza il timer
  time_t start_time = time(NULL);
	int tempo_rimanente=duration;
  while (tempo_rimanente>0) {
  	// Calcola il tempo trascorso
    time_t current_time = time(NULL);
    int delta_time = current_time - start_time;
		
    // Calcola la lunghezza della barra proporzionale al tempo rimanente
    tempo_rimanente = duration - delta_time;
    int bar_length = duration-delta_time;
        
    // sovrascrive barra con riga nera
    attron(COLOR_PAIR(SFONDO));
    for (int i = COLSTART; i < 40; ++i) {
    	mvaddch(ROWTEMPO, i, ' ');
    }
    attroff(COLOR_PAIR(SFONDO));

    // Disegna la barra verde
    attron(COLOR_PAIR(TIME));
    for (int i = COLSTART; i < bar_length; ++i) {
    	mvaddch(ROWTEMPO, i, ' ');
    }
    attroff(COLOR_PAIR(TIME));

    // Mostra il risultato sullo schermo
    refresh();

    // Aspetta 1 secondo prima di aggiornare la barra
    sleep(1);
  }
}

