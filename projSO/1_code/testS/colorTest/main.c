#include <ncurses.h>

int main() {
    // Inizializza NCurses
    initscr();
    start_color();

    // Controlla se il terminale supporta i colori
    if (has_colors() == FALSE) {
        endwin();
        printf("Il tuo terminale non supporta i colori.\n");
        return 1;
    }

    // Controlla quanti colori sono supportati
    int num_colors = COLORS;
    printw("Numero di colori supportati dal terminale: %d\n", num_colors);

    // Controlla quanti colori di sfondo sono supportati
    int num_color_pairs = COLOR_PAIRS;
    printw("Numero di coppie di colori supportate dal terminale: %d\n", num_color_pairs);

    // Esempio di definizione di una coppia di colori
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Usa la coppia di colori definita per scrivere del testo colorato
    attron(COLOR_PAIR(1));
    printw("Questo testo è rosso su sfondo nero!");
    attroff(COLOR_PAIR(1));

    // Termina NCurses
    refresh();
    getch();
    endwin();

    return 0;
}

