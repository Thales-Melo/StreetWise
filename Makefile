CC = gcc
CFLAGS = -Wall -Wno-unused-result -g

SRCS = main.c stdData/heap/heap.c stdData/vector/vector.c domain/dijkstra/dijkstra.c domain/graphs/graphs.c domain/path/path.c domain/node/node.c domain/route/route.c domain/problem/problem.c view/view.c utils/utils.c
OBJS = $(SRCS:.c=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main *.out

run:
	./main

val:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main