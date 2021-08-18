#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int l;
	    l=s.length();
	    
	    if(l%2==1 || s[0]==')' || s[l-1]=='(')
	    cout<<"NO\n";
	    else
	    cout<<"YES\n";
	}
	return 0;
}