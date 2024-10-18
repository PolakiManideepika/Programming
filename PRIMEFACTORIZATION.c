#include<stdio.h>
#include<conio.h>
void prime(int);

void prime(int a)
{
    if(a==1)
        return ;
    int i=2;
    while (a%i !=0)
    {
        i++;
    }
    printf("%d",i);
    prime(a/i);
}
void main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    prime(a);
}
