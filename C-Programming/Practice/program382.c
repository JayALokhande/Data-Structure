#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data ;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
    while (first != NULL)         //while(first != NULL)         TYPE 1 LOOp
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0 ;

    while (first != NULL)          // TYPE 1 LOOP
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)             //LL is Empty
    {
        *first = newn;
    }
    else                           //LL contains Atlist 1 Node
    {
        newn->next =*first;
        *first = newn;
    }

}

void InsertLast(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)             //LL is Empty
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while (temp->next != NULL)         //TYPE 2 LOOP
        {
            temp = temp->next;
        }
        temp->next = newn;
    
    }

}

void InsertAtPos(PPNODE first,int iNo,int iPos)
{

}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)                  // LL is Empty
    {
        return;
    }
    else if ((*first)->next == NULL)      // LL Contain 1 Node
    {
        free(*first);
        *first = NULL;
    }
    else                                // LL Contains more than 1 Node
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
    }
    
}

void DeleteLast(PPNODE first )
{
    PNODE temp = NULL;
    if(*first == NULL)                  // LL is Empty
    {
        return;
    }
    else if ((*first)->next == NULL)      // LL Contain 1 Node
    {
        free(*first);
        *first = NULL;
    }
    else                                // LL Contains more than 1 Node
    {
        temp = *first;
        while (temp->next->next != NULL )       //TYPE 3 LOOP
        {
            temp = temp ->next;
        }
        free(temp->next);
        temp ->next = NULL;
    }   

}

void DeleteAtPos(PPNODE first,int iPos)
{

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);
    
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);

    return 0 ;
}