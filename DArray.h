#ifndef DynamicArray_DynamicArray_h
#define DynamicArray_DynamicArray_h

#include"tsrc.h"


#define __TY(x) *((x*)
#define __PTY(x) ((x)
#define __AGP(A,z) (*DAgetptr(A,z)))
#define __LQ(x) (

/*
 * 
 * put
 * x*addr = (x*)malloc(sizeof(x));
 * *addr = y
 * *DAgetptr(Arr,z) = a; Or __LQ()__AGP(Arr,z);
 * 
 * get
 *
 * *(x*)(*DAgetptr(Arr,z));
 *
 * Or  __TY(x)__AGP(Arr,z); 
 *
 *Get x* type pointer with position z:
 *
 * (x*)(*DAgetptr(Arr,z));
 *
 * Or __PTY(x*)__AGP(Arr,z);
 *
 */



struct DArray{
    
    void**list;
    void**back;
    
    unsigned long size;
    unsigned long x;


    struct messPack addinfo;
    
    void***ptr;
    
};

struct DArray*DAini(unsigned long size);

void DAenlarge(struct DArray*thi);

void DAshrink(struct DArray*thi);

void**DAgetptr(struct DArray*thi,unsigned long pos);

void DAfree(struct DArray*thi);

int DAforall(struct DArray*thi,int(*iden)(void*));// if all elements in thi satisfy iden

struct DArray*DAgetA(struct DArray*thi,int(*iden)(void*));//all elements in thi satifys iden

void DAconvert(struct DArray*thi,void(*conv)(void*));

#endif
