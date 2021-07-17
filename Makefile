PROGS = snake

all: $(PROGS)

progs: main.o snake.o
	g++ -o $(PROGS) main.cpp snake.cpp