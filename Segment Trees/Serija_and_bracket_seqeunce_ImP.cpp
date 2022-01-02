#include<bits/stdc++.h>

using namespace std;


class Info
{
    public:
    int open;
    int close;
    int full;

    Info(int o = 0, int c= 0, int f= 0)
    {
        open=o;
        close=c;
        full=f;
    }
};

Info merge(Info left, Info right)
{
    Info ret;
    ret.full = left.full + right.full + min(left.open, right.close);
    ret.open = left.open + right.open - min(left.open, right.close);
    ret.close = left.close + right.close - min(left.open, right.close);

    return ret;
}


void Build(int ind, vector<Info>&seg, string s, int low,  int high)
{
    if(low == high)
    {
        seg[ind].open = (s[low]=='(' ? 1 : 0);
        seg[ind].close = (s[low]==')' ? 1 : 0);
        seg[ind].full = 0;
        return;
    }

    int mid = (low+high)>>1;

    Build(2*ind+1,seg,s,low,mid);
    Build(2*ind+2,seg,s,mid+1,high);

    seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
}

Info query(int ind, int low, int high, vector<Info>&seg, int l, int r)
{
    if(r< low || high < l)
    return Info();

    if(low>=l && high<=r)
    return seg[ind];

    int mid = (low+high)>>1;

    Info left = query(2*ind+1, low,mid, seg, l ,r);
    Info right =query(2*ind+2,mid+1,high, seg,l,r);

    return merge(left,right);
}


int main()
{
    string s;
    cin>>s;

    int q,n,i;
    cin>>q;

    n = s.length();

    vector<Info>seg(4*n);

    Build(0,seg,s,0,n-1);

    while(q--)
    {
        int l,r;

        cin>>l>>r;

        Info ans = query(0,0,n-1,seg,l,r);
        cout<<ans.full<<"\n";
    }
}