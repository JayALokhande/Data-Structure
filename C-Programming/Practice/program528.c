//4
//4*3*2*1 = 24

#include<stdio.h>

unsigned long int Factorial(int iNo)
{
    unsigned long int iFact = 1;

    while(iNo > 0)
    {
        iFact = iFact * iNo;
        iNo--;
    }
    return iFact;
}


int main()
{
    int iValue = 0;
    unsigned long int iRet = 0;

    printf("Enter the Frequency :");
    scanf("%lu",&iValue);

    iRet = Factorial(iValue);
    printf("Factorial is : %d\n",iRet);

    return 0;
}