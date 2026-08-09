all:
	cc -Wall -Wextra -o ./bin/main main.c

run: all
	./hello

clean:
	rm -f hello
