#include <stdio.h>
Void main()
{
char pass[20];
printf("Enter ur password :");
scanf("%s",pass);
int len = strlen(pass); 
int l=0,u=0,d=0,s=0;
if (len>7)
{
for(int i=0;i<len;i++)
{
if(isupper(pass[i])
       u++;
else if(islower(pass[i])
       l++;
else if (isdigit(pass[i])
       d++;
else
       s++;
}     
if(u>0 && l>0 && d>0 && s>0)
{
printf("Strong password");
}
else
{
printf ("weak password");
}
}
else
printf ("weak password due to less characters");
}