#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
bool prime(int, int);
int gcd(int,int);

int gcd(int a, int b)
{
    int temp;
    while(b>0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

bool prime(int a, int b)
{
    return gcd(a,b)==1;
}
void main()
{
    int a;
    printf("Enter any number:");
    scanf("%d",&a);
    for(int i=5;i<=a;i++)
    {
        for(int j=4;j<i;j++)
        {
            for(int k=3;k<j;k++)
            {
                if((j*j + k*k == i*i))
                {
                    if((prime(i,j)&& prime(j,k)&& prime(i,k)))
                    {
                        printf("\n%d %d %d",k,j,i);
                    }
                }
            }
        }
    }
}
