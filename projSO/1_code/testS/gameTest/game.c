#include <ncurses.h>
#include "game.h"

void show_initial_screen() {
    // Pulisce lo schermo e imposta un colore di sfondo
    clear();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));

    // Ottiene le dimensioni dello schermo
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Calcola la posizione del centro dello schermo
    int center_y = max_y / 2;
    int center_x = max_x / 2;

    // Messaggio di benvenuto
    char message[] = "Benvenuto! Premi un tasto per iniziare il gioco.";
    mvprintw(center_y, center_x - (strlen(message) / 2), "%s", message);

    // Aggiorna lo schermo
    refresh();

    // Attende l'input dell'utente per chiudere la schermata iniziale
    getch();
}

