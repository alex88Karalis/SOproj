# Nome del tuo eseguibile
TARGET = gioco

# Elenco dei file sorgente
SRCS = main.c game.c

# Comando per la compilazione
CC = gcc

# Opzioni del compilatore
CFLAGS = -Wall -Wextra -std=c11

# Librerie necessarie
LIBS = -lncurses

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

clean:
	rm -f $(TARGET)

