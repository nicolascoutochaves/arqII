all: clean m2bin cache normal exec
exec: populate.o inverter.o
	./populate.o
	./inverter.o
m2bin: populate.c inverter.c
	gcc -o populate.o populate.c matrix.c -O3
	gcc -o inverter.o inverter.c matrix.c -O3
cache: cache_matrix_multiplication.c
	gcc -o cache.o cache_matrix_multiplication.c matrix.c -O3
normal: normal_matrix_multiplication.c
	gcc -o normal.o normal_matrix_multiplication.c matrix.c -O3
clean:
	rm -f ./*.o