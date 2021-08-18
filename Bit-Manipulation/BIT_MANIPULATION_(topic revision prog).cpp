#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void Get_bit(int x,int pos)
{
	int a=1;
	a=a<<pos;
	a=a&x;
	if(a==0)
	{
		cout<<"bit at pos "<<pos<<" is off\n";
	}
	else
	{
		cout<<"bit at pos "<<pos<<" is on\n";
	}
}

void Set_bit(int x,int pos)
{
	int a=1;
	a=a<<pos;
	a=a|x;
	cout<<"After setting bit num "<<pos<<" on, integer x="<<x<<" becomes x="<<a<<"\n";
}

void Clear_bit(int x,int pos)
{
	int a=1;
	a=a<<pos;
	a=~a;
	a=a&x;
	
	cout<<"Before clearing bit at position "<<pos<<" number was "<<x<<" and now after clearing it is "<<a;
}
int main() {
	
	int x,y;
	int z;
	x=5;      //x=000000----0000101 (total 32 bits, since  int takes 4 bytes, 1 byte=8bits)
	y=11;	  //y=00000----00001011
	
	z=x&y;		//z=000----0000001 == decimal 1
	cout<<z<<"\n";
	
	z=x|y;    //z=0000---00001111 == decimal 15
	cout<<z<<"\n";
	
	z=x^y;     //z=00000----001110 == decimal 14
	cout<<z<<"\n";
	
	z=~x;    // z=1111111----11111010 == -(2s complement of z)= -(1s complement +1)=-(0000000000---0000101 +1 )=  -6 
	cout<<z<<"\n";
	
	
	x=1; 		 //x=0000--0001
	x=x<<1;     //x=0000--00010 similar to x*pow(2,1)
	cout<<x<<"\n\n";
	x=1;
	int i;
	for(i=0;i<=10;i++)
	{
		y=x<<i;  //y=x*pow(2,i)
		cout<<y<<"  ";
	}
	cout<<"\n\n";
	
	
	x=5; //x=0101
	int position;
	//to know that a bit at certain position is on or not
	position=1;
	Get_bit(x,position);  //also know as MASKING operation 
	position=2;
	Get_bit(x,position);
	
		cout<<"\n";
		
	// to set certain bit on
	position=1;
	Set_bit(x,position); //also know as MERGING operation
	
	cout<<"\n";
	position=2;
	
	Clear_bit(x,position);   //bit at position=i is cleared i.e turned off
	return 0;
}
