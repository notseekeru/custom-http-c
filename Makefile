HOST = http://localhost:8080

all:
	mkdir -p ./bin
	cc -Wall -Wextra -o ./bin/main main.c

run: all
	./bin/main

clean:
	rm -rf ./bin/**

get:
	curl --http0.9 $(HOST)
