#include<bits/stdc++.h>

using namespace std;
/*
A group of two or more people wants to meet and minimize the total travel distance.
 You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
 The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
*/

int minDist(vector<vector<int>>&mat)
{
    int r,c;
    r = mat.size();
    c = mat[0].size();

    vector<int>rows , cols;

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            if(mat[i][j] == 1)
            {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }

    int rs = rows.size() , cs = cols.size();
    nth_element(rows.begin() , rows.begin()+(rs/2) , rows.end()); // Fixing the nth element i.e median element O(n) time
    nth_element(cols.begin() , cols.begin()+(cs/2) , cols.end());

    int medRow = rows[rs/2] , medCol = cols[cs/2];

    int ans = 0;

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c; j++)
        {
            if(mat[i][j] == 1)
            {
                ans += (abs(medCol - j) + abs(medRow - i));
            }
        }
    }

    return ans;


}


int main()
{

}