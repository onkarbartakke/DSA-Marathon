#include <iostream>
using namespace std;

/*long int check(long int x1,long int y1,long int x2,long int y2,long int x,long int y)
{
    return ((y2-y1)*(x2-x)-(y2-y)*(x2-x1));
}*/

int onseg(long int x1,long int y1,long int x2,long int y2,long int x,long int y)
{
    int val=0;
    int x0,y0;
    x0=0;
    y0=0;
    if((x1>=x && x>=x2) || (x2>=x && x>=x1))
    x0=1;
    
    if((y1>=y && y>=y2) || (y2>=y && y>=y1))
    y0=1;
    
    
    if(x0==1 && y0==1)
    val=1;
    
    return val;
    
}

long int check_orient(long int x1,long int y1,long int x2,long int y2,long int x,long int y)
{
    return ((x2-x1)*(y-y1)-(x-x1)*(y2-y1));
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long int x1,x2,y1,y2,x3,x4,y3,y4,p,q,r,s;
	    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	    
	    //long int a=check(x1,y1,x2,y2,x3,y3);
	    //long int b=check(x1,y1,x2,y2,x4,y4);
	    int flag=1;
	   // cout<<a<<" "<<b<<"\n\n";
	    p=check_orient(x1,y1,x2,y2,x3,y3);
	    q=check_orient(x1,y1,x2,y2,x4,y4);
	    
	    
	    r=check_orient(x3,y3,x4,y4,x1,y1);
	    s=check_orient(x3,y3,x4,y4,x2,y2);

        if( ((p>0 && q<0) || (p<0 && q>0)) && ((r>0 && s<0) || (r<0 && s>0)) )	    
	    {
	        flag=0;
	        cout<<"1\n";
	    }
	           
	   if(p==0 && flag==1)
	   {
	       int a=onseg(x1,y1,x2,y2,x3,y3);
	       if(a==1)
	       {
	           flag=0;
	           cout<<"1\n";
	       }
	   }
	   
	   if(q==0 && flag==1)
	   {
	       int a=onseg(x1,y1,x2,y2,x4,y4);
	       if(a==1)
	       {
	           flag=0;
	           cout<<"1\n";
	       }
	   }
	   
	   if(r==0 && flag==1)
	   {
	       int a=onseg(x3,y3,x4,y4,x1,y1);
	       if(a==1)
	       {
	           flag=0;
	           cout<<"1\n";
	       }
	   }
	   
	   if(s==0 && flag==1)
	   {
	       int a=onseg(x3,y3,x4,y4,x2,y2);
	       if(a==1)
	       {
	           flag=0;
	           cout<<"1\n";
	       }
	   }
	   
	   if(flag==1)
	   {
	       flag=0;
	       cout<<"0\n";
	   }
	       
	   
	   
	   //cout<<p<<"  "<<q<<"\n";
	   //cout<<r<<"  "<<s<<"\n";
	}
	return 0;
}