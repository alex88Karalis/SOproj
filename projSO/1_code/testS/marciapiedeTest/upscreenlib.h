// copie colori
#define MARCIAPIEDE 1
#define SFONDO 2
#define PRATO 3
#define FIUME 4
#define TANE 5
#define HUD 6
#define TRONCHI 7

// dim. schermo
#define NUM_ROWS 37
#define NUM_COLS 100	
#define NUM_TANE 5

// dim. tane

typedef struct {
	char sprite[2][8];
} SpriteTronco;





void Tronco(int row);
void DisegnaTronchi(int width);
void DisegnaTane(int width);
void DisegnaHUD(int width);
