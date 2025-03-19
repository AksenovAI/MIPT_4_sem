CFLAGS = 
OB = model.o view.o t_view.o gview.o controller.o main.o
all: res

clean:
	$(RM) $(OB) res

res: $(OB)
	$(CC) -o $@ $(OB) $(CFLAGS)

make:	res