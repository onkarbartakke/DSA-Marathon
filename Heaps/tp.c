#include<stdio.h>
int p=0;
int *g=&p;

int main()
{
   int *l=NULL;

   if(l==g)
   printf("e");
   else
   printf("ne");
}