#ifndef TSRC_H
#define TSRC_H
#include<stdio.h>
#include<stdlib.h>

#define AHe(x) printf("\tSuc i %d\n",x)

#define __SMAL(x) (struct x *)malloc(sizeof(struct x ))

#define __MAL(x) ( x *)malloc(sizeof( x ))
struct messPack{
    unsigned long cont;
    char mess1;
    char mess2;
};
struct messPack mPini(unsigned long c,char m1,char m2);
#endif
