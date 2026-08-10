all:
	mkdir -p ./bin
	cc -Wall -Wextra -o ./bin/main main.c

run: all
	./bin/main

clean:
	rm -rf ./bin/**
