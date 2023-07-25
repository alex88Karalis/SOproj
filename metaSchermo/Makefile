# Nome dell'eseguibile
EXECUTABLE := main

# Elenco dei file oggetto
OBJECTS := main.o upscreenlib.o

# Compilatore C
CC := gcc

# Opzioni di compilazione
CFLAGS := -Wall -Wextra

# Librerie necessarie
LDLIBS := -lncurses

# Regola di compilazione dell'eseguibile
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDLIBS)

# Regole di compilazione dei file oggetto
main.o: main.c upscreenlib.h
	$(CC) $(CFLAGS) -c main.c

upscreenlib.o: upscreenlib.c upscreenlib.h
	$(CC) $(CFLAGS) -c upscreenlib.c

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

