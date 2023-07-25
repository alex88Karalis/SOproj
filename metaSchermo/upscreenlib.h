#include <ncurses.h>
#include <time.h>

#define MARCIAPIEDE 1
#define SFONDO 2
#define PRATO 3
#define FIUME 4
#define TANE 5
#define STRISCIA 6
#define TIME 7

#define NRPOINTS 4
#define ROWPOINTS 0

#define NRTANE 5
#define ROWTANE 4
#define GAP 3 // ogni quanto lasciare uno spazio vuoto nelle strisce autostradali

#define NRFIUME 10
#define ROWFIUME 9

#define NRPRATO 3
#define ROWPRATO 19

#define NRSTRADA 9
#define ROWSTRADA 22

#define NRSTRISCIA 1
#define ROWSTRISCIA 26

#define NRMARCIAPIEDE 3
#define ROWMARCIAPIEDE 31

#define NRVITE 1
#define ROWVITE 33

#define NRTEMPO 1
#define ROWTEMPO 35

#define COLSTART 2
#define COLEND 100

#define NUM_ROWS 37
#define NUM_COLS 104

// dichiarazione funzioni
void coloraMarciapiede();
void coloraPrato();
void coloraFiume();
void coloraStriscia();
void coloraTane();
void coloraSchermo();
void stampaTempo();

