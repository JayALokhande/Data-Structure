#include<stdio.h>

int CapitalCount(char *str)
{
    int iCount = 0;

    while(*str != '\0')
    {
        if(*str >= 'A' && *str <= 'Z')
        {
            iCount++;
        }
        str++;
    }
    return iCount;
}


int main()
{
    char Arr[20] ={'\0'};
    int iRet = 0;

    printf("Enter String \n");
    scanf("%[^'\n']s",Arr);

    iRet = CapitalCount(Arr);
    printf("String length is %d\n",iRet);

    return 0;
}