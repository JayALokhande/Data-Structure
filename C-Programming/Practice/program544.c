#include<stdio.h>



int main()
{
    int Arr[20] ={'\0'};

    printf("Enter String \n");
    scanf("%[^'\n']s",Arr);

    printf("%s\n",Arr);

    return 0;
}