#include<iostream>
#include <vector>

using namespace std;


vector<int>getSmaller(vector<int>&V)
{
	vector<int>smaller;
	for(int i=1;i<V.size();i++)
	{
		if(V[i]<V[0])
		{
			smaller.push_back(V[i]);
		}
	}
	
	return smaller;
}

vector<int>getBigger(vector<int>&V)
{
	vector<int>biggerEqual;
	for(int i=1;i<V.size();i++)
	{
		if(V[i]>=V[0])
		{
			biggerEqual.push_back(V[i]);
		}
	}
	
	return biggerEqual;
}


bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) 
{
  // Write your code here.
	if(arrayOne.size()!=arrayTwo.size())
		return false;
	
	if(arrayOne.size()==0 && arrayTwo.size()==0)
		return true;
	
	if(arrayOne[0]!=arrayTwo[0])
		return false;
	
	vector<int>LeftOne=getSmaller(arrayOne);
	vector<int>LeftTwo=getSmaller(arrayTwo);
	vector<int>RightOne=getBigger(arrayOne);
	vector<int>RightTwo=getBigger(arrayTwo);
  return (sameBsts(LeftOne,LeftTwo))&&(sameBsts(RightOne,RightTwo));
}

int main()
{

}