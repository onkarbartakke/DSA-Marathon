#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long int pairs,middleman,i,l;
        
       l=s.length();
       int a[26]={0};
       for(i=0;i<l;i++)
       {
           a[s[i]-'a']++;
       }
        
        
        pairs=0;
        middleman=0;
        for(i=0;i<26;i++)
        {
            if(a[i]%2==0)
            {
                pairs=pairs+(a[i]/2);
            }
            else
            {
                middleman++;
                pairs=pairs+(a[i]-1)/2;  //coz 1 gone as middleman
            }
        }
        
        if(pairs<=middleman) //if available middleman are greater than pairs
        {
            cout<<pairs;
        }
        else
        {
            long int ans;  
            //middleman are less, they will take middleman=m pairs and form palindorme that is each middleman will take one pair
            //and we are left with num of pairs=pairs-middleman. now this are PAIRS aaxxbbccaaddxxttyy in that case num of palindrome =len/3=(pairs-middleman)*2/3
            //leftpairs=pairs-midleman therefore len=leftpairs*2
            ans=middleman+((pairs-middleman)/3)*2;
            if((pairs-middleman)%3==2)  //if leftpairs%3==2, once more palindrome is formed ,spl case 
            ans++;
            cout<<ans;
            
        }
        cout<<"\n";
    }
	return 0;
}
