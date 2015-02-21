#include "DArray.h"
struct DArray*DAini(unsigned long size){
    struct DArray*res=__SMAL(DArray);
    res->x=0;
    res->addinfo=mPini(0,(char)0,(char)0);
    res->size=size;
    res->list=malloc(sizeof(void*)*(size+1));
    res->ptr=malloc(sizeof(void*)*5);
    *(res->ptr)=*(res->ptr+1)=*(res->ptr+2)=*(res->ptr+3)=*(res->ptr+4)=res->list;
    res->back=(res->list+res->size);
    return res;
}

void DAenlarge(struct DArray*thi){
    *(thi->back)=malloc(sizeof(void*)*((thi->size<<thi->x)+1));
    void***tem=malloc(sizeof(void*)*5);
    for (int i=0;i<=3;i++)
        *(tem+i)=*(thi->ptr+i+1);
    *(tem+4)=*(thi->back);
    free(thi->ptr);
    thi->ptr=tem;
    thi->back=(void**)(*(thi->back))+(thi->size<<(thi->x++));
}

void DAshrink(struct DArray*thi){
    void***tem=malloc(sizeof(void*)*5);
    for (int i=0;i<=3;i++)
        *(tem+i+1)=*(thi->ptr+i);
    if(DAgetptr(thi,0)==*(tem+1))
        *(tem)=*(tem+1);
    else
        for(int j=1;j<=thi->x;j++)
            if(DAgetptr(thi,thi->size<<j)==*(tem+1)){
                *tem=DAgetptr(thi,thi->size<<(j-1));
                break;
            }
    free(*(thi->ptr+4));
    free(thi->ptr);
    thi->ptr=tem;
}
void**DAgetptr(struct DArray*thi,unsigned long pos){
    if(pos<thi->size)
        return (thi->list+pos);
    while(pos>=((thi->size)<<thi->x))
        DAenlarge(thi);
    if(pos>=(thi->size<<(thi->x-1)))
        return *(thi->ptr+4)+pos-(thi->size<<(thi->x-1));
    if(pos>=(thi->size<<(thi->x-2)))
        return *(thi->ptr+3)+pos-(thi->size<<(thi->x-2));
    if(pos>=thi->size<<(thi->x-3))
        return *(thi->ptr+2)+pos-(thi->size<<(thi->x-3));
    if(pos>=thi->size<<(thi->x-4))
        return *(thi->ptr+1)+pos-(thi->size<<(thi->x-4));
    if(pos>=thi->size<<(thi->x-5))
        return *(thi->ptr)+pos-(thi->size<<(thi->x-5));
    register int i=0;
    register void**it=*(thi->list+thi->size);
    while ((thi->size<<(i+1))<=pos)
        it = (void**)*(it+(thi->size<<(i++)));
    return it+pos-(thi->size<<(i));
}

void DAfree(struct DArray*thi){
    void***tr = (void***) malloc(sizeof(void**)*thi->x+1);
    register void**it=*(thi->list+thi->size);
    *tr=it;
    for(int i=1;i<thi->x;i++){
        it = (void**)*(it+(thi->size<<(i++)));
        *(tr+i)=it;
    }
    for(int i=0;i<thi->x;i++)
        free(*(tr+i));
    free(thi->list);
    free(thi);
    free(tr);
}

