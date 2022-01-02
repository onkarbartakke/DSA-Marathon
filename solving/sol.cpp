#include<iostream>


using namespace std;


int main()
{
    int a,b,c;
    a=5;
    b=4;
    c=6;

   for(c=4;c<=7;c++)
   {
       if((a&c&b) < (c-b-a))
       {
           continue;
       }

       b=(b+9)+a;
       b=a^a;
   }

   cout<<a+b;
}