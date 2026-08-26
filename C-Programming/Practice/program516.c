#include<stdio.h>

void Display(int iNo)
{

   if(iNo != 0 )
    {
        printf("Jay Ganesh.. %d\n",iNo);
        iNo--;
        Display(iNo);
    } 

}

int main()
{
    int iValue = 0;

    printf("Enter the Frequency :");
    scanf("%d",&iValue);

    Display(iValue);

    return 0;
}