all:
	gcc -shared -fPIC a.c -o liba.so -ldl
	gcc -shared -fPIC b.c -o b.so -L. -ldl -la
	gcc main.c -ldl
