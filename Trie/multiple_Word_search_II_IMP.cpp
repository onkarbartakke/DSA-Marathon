#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    bool is_end;
    vector<TrieNode *> childern;

    TrieNode()
    {
        is_end = false;
        childern = vector<TrieNode *>(26, NULL);
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(vector<string> &words)
    {
        root = new TrieNode();

        for (auto s : words)
            addWord(s);
    }

    TrieNode *getRoot() { return root; }

    void addWord(string &s)
    {
        TrieNode *curr = root;

        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';

            if (curr->childern[idx] == NULL)
            {
                curr->childern[idx] = new TrieNode();
            }

            curr = curr->childern[idx];
        }

        curr->is_end = true;
    }
};

class Solution
{
public:
    void wordStarting(vector<vector<char>> &board, TrieNode *r, string word, unordered_set<string> &st, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == ' ')
            return;

        TrieNode *curr = r;

        if (curr->childern[board[i][j] - 'a'] != NULL)
        {
            char c = board[i][j];
            word += c;
            board[i][j] = ' ';

            curr = curr->childern[c - 'a'];
            if (curr->is_end)
                st.insert(word);

            wordStarting(board, curr, word, st, i + 1, j);
            wordStarting(board, curr, word, st, i - 1, j);
            wordStarting(board, curr, word, st, i, j + 1);
            wordStarting(board, curr, word, st, i, j - 1);

            board[i][j] = c;
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        Trie *T = new Trie(words);

        TrieNode *root = T->getRoot();

        unordered_set<string> st;

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                wordStarting(board, root, "", st, i, j);
            }
        }

        vector<string> ans;

        for (auto s : st)
            ans.push_back(s);

        return ans;
    }
};
