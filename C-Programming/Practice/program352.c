#include<stdio.h>

#pragma pack(1)
struct node
{
    int data ;
    struct node * next;
    
};

int main()
{
    struct node obj;

    printf("%d",sizeof(obj));       // 16 Bytes
    // 4(int) + 4(padding) +8(pointer)
    
    return 0;
}