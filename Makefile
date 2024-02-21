CC = gcc
CFLAGS = -Isrc -Wall
DEPS = src/directory.h src/file.h
OBJ = src/main.o src/directory.o src/file.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

file-explorer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) file-explorer
