CFLAGS= -lgraph
FILES=  menu_snake.c
all: snake

snake: menu_snake.c 
	gcc -o menu_snake  menu_snake.c $(CFLAGS)