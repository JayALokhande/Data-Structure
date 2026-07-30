#include<stdio.h>

struct node
{
    int data ;
    struct node * next;
    
};
int main()
{
    struct node obj;

    printf("%d",sizeof(obj));       // 12 Bytes
    // 4(int) + 8(pointer)
    
    return 0;
}