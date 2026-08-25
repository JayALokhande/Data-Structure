#include<stdio.h>

void Display()
{
    auto int i = 0;         //some compilar give the error becaus auto

    for(i= 1 ; i <= 4 ; i++)
    {
        printf("Jay Ganesh... \n");
    }
}

int main()
{
    Display();

    return 0;
}