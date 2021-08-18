#include <iostream>
using namespace std;


int get_rank(int a[][3])
{
    int i,j;
    int x,y,z,p,q,r,s,det;
    /*
    x=a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]);
    y=a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
    z=a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    
    det=x + (-1)*y + z;
    */
        x = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]);
	    y = a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
	    z = a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
	    det = x - y + z;
        cout<<"\n";
        cout<<"x : "<<x<<"\n";
        cout<<"y : "<<y<<"\n";
        cout<<"z : "<<z<<"\n";
        cout<<"\nDet Val is : "<<det<<"\n";


    if(det!=0)
    return 3;
    
            p = a[0][0]*a[1][1] - a[0][1]*a[1][0];
	        q = a[0][1]*a[1][2] - a[0][2]*a[1][1];
	        r = a[1][0]*a[2][1] - a[1][1]*a[2][0];
	        s = a[1][1]*a[2][2] - a[2][2]*a[2][1];
	        
	        if(p!=0 || q!=0 || r!=0 || s!=0)
	        return 2;
	        else
	        return 1;
}

int main() {
	//code
	int t;
    
	while(t--)
	{
	    int i,j,k,count;
	    int a[3][3];
	    count=0;
	    
	    for(i=0;i<3;i++)
	    {
	        for(j=0;j<3;j++)
	        {
	            cin>>a[i][j];
	            
	            if(a[i][j]==0)
	            count++;
	        }
	    }
	    
	    if(count==9)
	    cout<<"0\n";
	    else
	    {
	        cout<<get_rank(a)<<"\n";
	    }
	}
	return 0;
}