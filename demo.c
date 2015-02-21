#include"DArray.h"
int main(){
    //insert 60000 random chars into array p with initial volume 400
    struct DArray*p = DAini(400);
    for(unsigned long i=0;i<60000;i++){
        char*add=(char*)malloc(sizeof(char));
        *add=((i+29)%7+(i*i-3)%433)%40+15;
        __LQ()__AGP(p,i)=add;
    }
    for(unsigned long i=0;i<60000;i++)
        printf("%c",__TY(char)__AGP(p,i));
    printf("\n");
    //insert 2000 pointers into array p
    struct P{
        char a;
        char b;
    };
    for(unsigned long i=0;i<2000;i++){
       struct P*add =(struct P*)malloc(sizeof(struct P));
       add->a = 'a';
       add->b = 'b';
       __LQ()__AGP(p,i+60000)=add;
    }
    for(unsigned long i=0;i<2000;i++)
        printf("%c%c\t",__PTY(struct P*)__AGP(p,60000+i)->a,__PTY(struct P*)__AGP(p,60000+i)->b);
    return 0;
}
