#include <stdio.h> 
Void main()
{ 
char a[3]="213";
int res=0,i;
for(i=0;i<3;i++)
{
res=(res*10) + (a[i]-'0');
}
printf("%d",res);
}