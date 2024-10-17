#include<stdio.h>
void main()
{
char a[200];
printf("Enter sentence");
gets(a);
int len=strlen(a);
int count=0;
for(i=0;i<a;i++)
{
if(a[i]==' ' && a[i+1]!=' ' )
{
count+=1;
}
}
printf("No.of words is %d",coun+1);
}