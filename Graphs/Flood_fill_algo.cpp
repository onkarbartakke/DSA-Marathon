#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

void colour(int x, int y, int newColour, vector<vector<int>> &image, int src)
{
    int n = image.size();
    int m = image[0].size();

    if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != src)
        return;

    image[x][y] = newColour;
    colour(x + 1, y, newColour, image, src);
    colour(x - 1, y, newColour, image, src);
    colour(x, y + 1, newColour, image, src);
    colour(x, y - 1, newColour, image, src);

    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // Code here

    colour(sr, sc, newColor, image, image[sr][sc]);

    return image;
}

int main()
{
    
}