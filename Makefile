all:
	cc -Wall -Wextra -o ./bin/main $(wildcard *.c)

run: all
	./bin/main

clean:
	rm -rf ./bin
