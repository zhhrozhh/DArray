#ifndef DynamicArray_DynamicArray_h
#define DynamicArray_DynamicArray_h

#include"tsrc.h"


#define __TY(x) *((x*)
#define __PTY(x) ((x)
#define __AGP(A,z) (*DAgetptr(A,z)))
#define __LQ(x) (

/*
 * 
 * To put a x type data y into array Arr in the position z:
 *
 * x*addr = (x*)malloc(sizeof(x));
 * *addr = y
 * *DAgetptr(Arr,z) = a; Or use __LQ()__AGP(Arr,z);
 * 
 * To Get a x type data from array Arr in the position z:
 *
 * *(x*)(*DAgetptr(Arr,z));
 *
 * Or use  __TY(x)__AGP(Arr,z);  directly
 *
 * To Get a x* type pointer from Arr in the position z:
 *
 * (x*)(*DAgetptr(Arr,z));
 *
 * Or use __PTY(x*)__AGP(Arr,z);
 *
 */



struct DArray{
    
    void**list;
    void**back;
    
    unsigned long size;
    unsigned long x;

    /*
     * addinfo - detail of DA
     * addinfo - cont - num of ele in DA
     * addinfo - mess1 - should be 0 or 1, to determine whether eles in DA are continuous
     * addinfo - mess2 - not used
     */
    struct messPack addinfo;
    
    //optional ptrs:
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
