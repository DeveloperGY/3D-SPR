make: build run

build:
	g++ src/*.cpp -o bin/exe -I lib -L lib -l termDisplay -l rotmatrix -l m

run:
	./bin/exe