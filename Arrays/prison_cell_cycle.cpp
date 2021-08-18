#include<iostream>
#include<vector>

using namespace std;

vector<int> After_n_days(vector<int>&cells, int n)
{
    vector< vector<int> >Table;
    vector<int>temp(8);
    int i;
    temp[0]=0;
    temp[7]=0;
    for(i=1;i<7;i++)
    {
        temp[i]=(cells[i-1]==cells[i+1])?1:0;
    }

    Table.push_back(temp);

    n--;
    if(n==0)
    return temp;

    cells=temp;
    while(n--)
    {
        for(i=1;i<7;i++)
        {
            temp[i]=(cells[i-1]==cells[i+1])?1:0;
        } 

        if(temp==Table.front())
        return Table[n%Table.size()];
        else
        Table.push_back(temp);
        cells=temp; 
    }


    return temp;

}

int main()
{
    vector<int>cells(8);
    int i,j,n;
    cout<<"Enter the inital stage of Cells : \n";
    for(i=0;i<8;i++)
    {
        cin>>cells[i];
    }

    cout<<"\nEnter num of days : ";
    cin>>n;

    vector<int>final=After_n_days(cells,n);

    cout<<"\nConfi after n days :\n";

    for(i=0;i<8;i++)
    {
        cout<<cells[i]<<" ";
    }
}