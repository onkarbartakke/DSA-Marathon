#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
/*
  int steps(int src, int step, int D)
    {
        if(abs(src)>D)
        return INT_MAX;
        
        if(src==D)
        return step;
        
        int pos=steps(src+step+1, step+1,D);
        int neg=steps(src-step-1, step+1,D);
        
        return min(pos,neg);
    }
    */
int minSteps(int D)
{
    // code here
    // return steps(0,0,D);

    int sum = 0, step = 0;

    while (sum < D || (sum - D) % 2 != 0)
    {
        step++;
        sum += step;
    }

    return step;
}