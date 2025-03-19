CFLAGS = 
OB = animal.o cat.o dog.o main.o
all: res

clean:
	$(RM) $(OB) res

res: $(OB)
	$(CC) -o $@ $(OB) $(CFLAGS)


make:	res