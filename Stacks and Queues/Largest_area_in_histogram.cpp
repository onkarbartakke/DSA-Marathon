#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int Largest_Rect(vector<int>&Hist, int n)
{
    stack<int>st;
    int i,j;
    Hist.push_back(0);
    n=Hist.size();
    int area=0;
    while(i<n)
    {
        if(st.empty() || Hist[st.top()]<=Hist[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int tp=st.top();
            st.pop();
            int h=Hist[tp];
            int w = (st.empty()) ? i : i - st.top() - 1;
            area=max(area, h*(w));
        }
    }
    
    return area;
}
int main()
{
    int n,i;
    cout<<"Enter the size of Histogram : ";
    cin>>n;
    vector<int>Hist(n);
    cout<<"\nEnter the Elements of Histogram : \n";
    for(i=0;i<n;i++)
    {
        cin>>Hist[i];
    }

    cout<<"Area of largest is : "<<Largest_Rect(Hist, n);
}