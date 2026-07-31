#include<stdio.h>

#pragma pack(1)
struct node
{
    int data ;
    struct node * next;
    
};

typedef struct node NODE;
typedef struct node * PNODE;
int main()
{
    PNODE head = NULL;
    PNODE temp = NULL;
    NODE obj1,obj2,obj3;

    int iCount = 0;
    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    temp = head;                 //100

    //Iteration
    while (temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }
    printf("Number of Node are : %d\n",iCount);
    return 0;
}