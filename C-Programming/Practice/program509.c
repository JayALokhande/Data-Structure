#include<stdio.h>

void Display()
{
    static int  i = 1;

    i = 1;  // reset the i to 1 each time 

    if(i <= 4)
    {
        printf("Jay Ganesh... \n");
        i++;
        Display();
    }   

}

int main()
{
    Display();

    return 0;
}