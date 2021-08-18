#include <iostream>
#include <vector>

using namespace std;
void heapify(vector<int> &heap, int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;

    int largest = i;

    if (left < n && heap[largest] < heap[left])
        largest = left;

    if (right < n && heap[largest] < heap[right])
        largest = right;

    if (largest != i)
    {
        int t = heap[largest];
       heap[largest]=heap[i];
        heap[i] = t;

        heapify(heap, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // your code here
    vector<int> heap(n + m);
    int i;
    for (i = 0; i < n; i++)
    {
        heap[i] = a[i];
    }
    int j = 0;
    for (; i < n + m; i++)
    {
        heap[i] = b[j];
        j++;
    }

    for (i = n; i >= 0; i--)
    {
        heapify(heap, n + m, i);
    }

    return heap;
}
int main()
{
    int n,m,i;
    cout<<"Enter the 1st heap size : ";
    cin>>n;
    vector<int>a(n);
    cout<<"\nEnter the ele\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"\nEnter the 2nd heap size : ";
    cin>>m;
    vector<int>b(m);
    cout<<"\nEnter the Ele\n";
    for(i=0;i<m;i++)
    {
        cin>>b[i];
    }

    vector<int>h=mergeHeaps(a,b,n,m);

    cout<<"\n\n";

    for(i=0;i<h.size();i++)
    cout<<h[i]<<" ";
}