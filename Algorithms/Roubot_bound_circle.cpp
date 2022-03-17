#include <bits/stdc++.h>

using namespace std;
/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle
*/

// Algo : - https://leetcode.com/problems/robot-bounded-in-circle/discuss/1677199/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-Friendly-with-detailed-explanation-and-dry-run
class Solution
{
public:
    bool isRobotBounded(string instructions)
    {

        char dir = 'N';
        int x, y;
        int dx, dy;

        if (instructions.length() == 0)
            return true;

        x = 0;
        y = 0;

        for (int i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'G')
            {
                if (dir == 'N')
                    y++;
                else if (dir == 'S')
                    y--;
                else if (dir == 'E')
                    x++;
                else if (dir == 'W')
                    x--;
            }
            else
            {
                if (instructions[i] == 'L')
                {
                    if (dir == 'N')
                        dir = 'W';
                    else if (dir == 'W')
                        dir = 'S';
                    else if (dir == 'S')
                        dir = 'E';
                    else if (dir == 'E')
                        dir = 'N';
                }
                else if (instructions[i] == 'R')
                {
                    if (dir == 'N')
                        dir = 'E';
                    else if (dir == 'E')
                        dir = 'S';
                    else if (dir == 'S')
                        dir = 'W';
                    else if (dir == 'W')
                        dir = 'N';
                }
            }
        }

        if (x == 0 && y == 0)
            return true;

        if (dir != 'N')
            return true;

        return false;
    }
};