#include<stdio.h>

int Multiplication(int iNo)
{
    int iDigit = 0;
    static int iMul = 1;

    if(iNo != 0)
    {
        iDigit = iNo % 10;
        iMul = iMul * iDigit;

        Multiplication(iNo / 10);
    }
    return iMul;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter the Number :");
    scanf("%d",&iValue);

    iRet = Summation(iValue);
    printf("Multiplication is :%d\n",iRet);

    return 0;
}