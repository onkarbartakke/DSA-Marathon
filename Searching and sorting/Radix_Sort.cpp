#include<iostream>
#include<cmath>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int d=0)
        {
            data=d;
            next=NULL;
        }
};

int NumOfDigits(int n)
{
    int count=0;
    while(n>0)
    {
        n=n/10;
        count++;
    }

    return count;
}

int getIndex(int n, int p)
{
    return (int)(n/(pow(10,p)))%10;
}

void Insert(Node **binhead, int n, int index)
{
    Node *t=new Node(n);
    if(binhead[index]==NULL)
    {
        binhead[index]=t;
    }
    else
    {
        Node *p=binhead[index];
        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=t;
    }
}

int Delete(Node **binhead, int i)
{
    Node *p=binhead[i];
    int val=p->data;
    binhead[i]=p->next;
    delete p;
    return val;
}

void RadixSort(int a[], int n)
{
    Node **binhead;
    binhead=new Node*[10];
    int i,j,k,max,pass,Numpass,index;
    for(i=0;i<10;i++)
    {
        binhead[i]=NULL;
    }

    max=-1;
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        max=a[i];
    }

    Numpass=NumOfDigits(max);

    for(pass=0;pass<Numpass;pass++)
    {
        for(i=0;i<n;i++)
        {
            index=getIndex(a[i],pass);
            Insert(binhead,a[i],index);
        }

        i=0;
        j=0;
        while(i<10)
        {
            while(binhead[i]!=NULL)
            {
                a[j++]=Delete(binhead,i);
            }
            i++;
        }


        for(i=0;i<10;i++)
        binhead[i]=NULL;
    }

    delete []binhead;

}

int main()
{
    int n,i;
    cout<<"\nEnter the num of elements : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Elemnts of Array : \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    RadixSort(a,n);
    cout<<"\nAfter Sorting \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}