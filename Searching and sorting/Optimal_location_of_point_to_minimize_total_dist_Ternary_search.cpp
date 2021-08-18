#include <iostream>
#include<math.h>
#define MAX 1e5
#define MIN -(1e5)
#define err (1e-6)
#define sq(x) ((x)*(x))
using namespace std;

/*
If we take one point on given line at infinite distance then total distance cost will be infinite, now when we move this point on line 
towards given points the total distance cost starts decreasing and after some time, it again starts increasing which reached to infinite 
on the other infinite end of line so distance cost curve looks like a U-curve and we have to find the bottom value of this U-curve. 

As U-curve is not monotonically increasing or decreasing we can’t use binary search for finding bottom most point, here we will 
use ternary search for finding bottom most point, ternary search skips one third of search space at each iteration, you can read
 more about ternary search here. 

So solution proceeds as follows, we start with low and high initialized as some smallest and largest values respectively, 
then we start iteration, in each iteration we calculate two mids, mid1 and mid2, which represent 1/3rd and 2/3rd position in search 
space, we calculate total distance of all points with mid1 and mid2 and update low or high by comparing these distance cost, this 
iteration continues untill low and high become approximately equal. 


Assume we are looking for a maximum of f(x) and that we know the maximum lies somewhere between A and B. For the algorithm to be
 applicable, 
there must be some value x such that

for all a,b with A ≤ a < b ≤ x, we have f(a) < f(b), and
for all a,b with x ≤ a < b ≤ B, we have f(a) > f(b).


Let f(x) be a unimodal function on some interval [l; r]. Take any two points m1 and m2 in this segment: l < m1 < m2 < r. Then there are 
three possibilities:

if f(m1) < f(m2), then the required maximum can not be located on the left side - [l; m1]. It means that the maximum further 
makes sense to look only in the interval [m1;r]
if f(m1) > f(m2), that the situation is similar to the previous, up to symmetry. Now, the required maximum can not be in the 
right side - [m2; r], so go to the segment [l; m2]
if f(m1) = f(m2), then the search should be conducted in [m1; m2], but this case can be attributed to any of the previous two 
(in order to simplify the code). Sooner or later the length of the segment will be a little less than a predetermined constant, and the
process can be stopped.
choice points m1 and m2:

m1 = l + (r-l)/3
m2 = r - (r-l)/3
*/

class Point
{
    public:
    double x;
    double y;

    Point(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }

};

// ax + by + c =0
class Line
{
    public:
    double a;
    double b;
    double c;


    Line(double a, double b, double c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

double Dist(Point a, Point b)
{
    return sqrt(   sq(a.x-b.x)+sq(a.y-b.y)   );
}


double Compute(Point P[], int n, Line L, double X)
{
    double Y=(-1)*(L.c+L.a*X)/(L.b);
    double res=0.0;
    Point M(X,Y);
    for(int i=0;i<n;i++)
    {
        res+=Dist(P[i], M);
    }

    return res;

}

Point Optimal_loc(Point P[], int n, Line L)
{
    double high,low,m1,m2;
    high=MAX;
    low=MIN;
    while((high-low)>err)
    {
        m1=low + (high-low)/3;
        m2= high - (high-low)/3;

        double r1=Compute(P,n,L,m1);
        double r2=Compute(P,n,L,m2);

        if(r1<r2)
        {
            high=m2;
        }
        else
        {
            low=m1;
        }
    }

    cout<<"\nOptimal cost is : "<<Compute(P,n,L,(high+low/2));

    double x=(high+low)/2;
    double y=(-1)*(L.c+L.a*x)/(L.b);

    Point opti(x,y);
    return opti;
}

int main()
{
    double a,b,c,x,y;
    

    cout<<"Enter the Constants (a,b,c) of Line Equation ax + by + c = 0 : ";
    cin>>a>>b>>c;
    Line L(a,b,c);
    int n;
    cout<<"\nEnter the num of points : ";
    cin>>n;
    Point P[n];
    cout<<"\nEnter x and y co-ordinate of each  point : \n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        cin>>y;
        Point pi(x,y);
        P[i]=pi;
    }

    Point ans=Optimal_loc(P,n,L);

    cout<<"\nOptimal point is ( "<<ans.x<<" , "<<ans.y<<" )";

}