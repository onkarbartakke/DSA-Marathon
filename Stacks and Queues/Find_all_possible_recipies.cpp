#include <bits/stdc++.h>

using namespace std;


/*

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply 
of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

*/
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {

        unordered_set<string> st;

        for (auto it : supplies)
            st.insert(it);

        int n = recipes.size();

        vector<string> ans;
        queue<int> qu;
        queue<int> dqu;
        queue<int> t;
        vector<bool> mark(n, false);

        for (int i = 0; i < n; i++)
            qu.push(i);

        bool flag = true;

        while (flag)
        {
            flag = false;

            while (!qu.empty())
            {
                int i = qu.front();
                qu.pop();

                bool make = true;

                for (int j = 0; j < ingredients[i].size(); j++)
                {
                    if (st.find(ingredients[i][j]) == st.end())
                    {
                        make = false;
                        break;
                    }
                }

                if (make && mark[i] == false)
                {
                    st.insert(recipes[i]);
                    mark[i] = true;
                    flag = true;
                    ans.push_back(recipes[i]);
                }
                else if (make == false)
                {
                    dqu.push(i);
                }
            }

            if (dqu.empty())
                flag = false;
            else
            {

                t = qu;
                qu = dqu;
                dqu = t;
            }
        }

        return ans;
    }
};