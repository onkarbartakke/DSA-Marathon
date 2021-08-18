#include<iostream>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

bool valid(string s)
{
    cout<<s<<" ";
	int n=(int)stoi(s);
	
    cout<<n<<"\n";
	if(n > 255)
		return false;
	
	int l=to_string(n).length();
	
	if(s.length()==l)
		return true;
	else
		return false;
}

string join(vector<string>&curr)
{
	string s="";
	s=s+curr[0];
	s=s+".";
	s=s+curr[1];
	s=s+".";
	s=s+curr[2];
	s=s+".";
	s=s+curr[3];
	
	return s;
}
vector<string> validIPAddresses(string str) {
  // Write your code here.
	int i,j,k,l;
	vector<string>ans;
	l=str.length();
	

	for(i=1; i< min(l,4);i++)
	{
		vector<string>currstr{"","","",""};
		currstr[0]=str.substr(0,i);
		
		if(!valid(currstr[0]))
			continue;
		
		for(j=i+1; j < i+ min(l-i,4);j++)
		{
			currstr[1]=str.substr(i,j-i);
			
			if(!valid(currstr[1]))
				continue;
			
			for(k=j+1; k < j+ min(l-j,4); k++)
			{
				currstr[2]=str.substr(j,k-j);
				currstr[3]=str.substr(k);
				
				if(valid(currstr[2]) && valid(currstr[3]))
				{
					string s=join(currstr);
					ans.push_back(s);

                    cout<<"\n"<<s<<"\n";
				}
					
			}
		}
	}
  return ans;
}


int main()
{
    string s;
    cout<<"Enter the num string : ";
    cin>>s;
    cout<<"\n\n";
    vector<string>ans=validIPAddresses(s);

    cout<<"\n\n************************************\n";

    for(auto s: ans)
    {
        cout<<s<<"\n";
    }
}