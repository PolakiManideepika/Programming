#include<stdio.h>
void main()
{
    char name[20][20];
    int a,i;
    printf("enter number of names:");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%s",name[i]);
        
    }
    printf("the names are as follows....");
    for(i=0;i<a;i++)
    {
        printf("\n Name%d %s",i+1,name[i]);
    }
}