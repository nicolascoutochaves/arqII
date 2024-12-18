all: clean cache
cache: main.c
	gcc main.c matrix.c -O3 -Wall -Wextra -Wpedantic
clean:
	rm -f ./*.o