#include<stdio.h>
int main() {
  int a,b,temp;
  printf("Enter two numbers: ");
  scanf("%d%d", &a,&b);
  temp = a;
  a = b;
  b = temp;

  printf("\nAfter swapping, first number = %d\n", a);
  printf("After swapping, second number = %d", b);
  return 0;
}
