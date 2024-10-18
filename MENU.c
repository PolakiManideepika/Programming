#include<stdio.h>
void circle();
void rect(int);
void triangle(int,int,int);

void circle()
{
    int r;
    printf("Enter radius:");
    scanf("%d",r);
    float res=3.14*r*r;
    printf("The radius is : %f",res);
}

void rect(int len)
{
    int bre;
    printf("enter breadth:");
    scanf("%d",&bre);
    printf("The area of rectangle is :%d",len*bre);
}

void triangle(int a,int b,int c)
{
    printf("The perimeter of triangle is :%d",a+b+c);
}
void main()
{
    int a;
    printf("1.CIRCLE\n2.RECTANGLE\n3.TRIANGLE\n");
    printf("Enter your choice");
    scanf("%d",&a);
    switch(a)
    {
        case 1:circle();
               break;
        case 2:rect(20);
               break;
        case 3:triangle(30,20,10);
               break;
        default:printf("Invalid choice");

    }
}

