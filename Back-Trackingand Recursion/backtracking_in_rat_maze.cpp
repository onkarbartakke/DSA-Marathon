#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
bool is_safe(int **arr,int x,int y,int n)
{
	if(x<n && y<n && arr[x][y]==1)
	return true;
	else
	return false;
}

bool rat_in_maze(int **arr,int **soluarr,int x,int y,int n)
{
	if(x==n-1 && y==n-1)
	{
		soluarr[x][y]=1;
		return true;
	}
	if(is_safe(arr,x,y,n))
	{
		soluarr[x][y]=1;
		if(rat_in_maze(arr,soluarr,x+1,y,n))
		{
			return true;
		}
		
		if(rat_in_maze(arr,soluarr,x,y+1,n))
		{
			return true;
		}
		soluarr[x][y]=0;  //we backtrack here as both ways are not possible
		return false;
	}
	return false;
	
}
int main()
{
	int **arr,**soluarr;
	int n,i,j;
	cout<<"Enter the size of maze\n";
	cin>>n;
	
	arr=new int*[n];
	soluarr=new int*[n];
	for(i=0;i<n;i++)
	{
		arr[i]=new int[n];
		soluarr[i]=new int[n];
	}
	cout<<"Enter ele of maze\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
			soluarr[i][j]=0;
		}
	}
	
	rat_in_maze(arr,soluarr,0,0,n);
	
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<soluarr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
