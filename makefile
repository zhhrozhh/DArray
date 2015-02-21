All:	a
a:	demo.o	DArray.o	tsrc.o
	gcc -o a demo.o DArray.o tsrc.o
demo.o:	demo.c
	gcc -c demo.c
DArray.o:	DArray.c
	gcc -c DArray.c
tsrc.o:	tsrc.c
	gcc -c tsrc.c
