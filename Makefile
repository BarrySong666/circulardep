all:
	gcc -shared -fPIC a.c -o liba.so -ldl
	gcc -shared -fPIC b.c -o b.so  -ldl
	gcc main.c -ldl
