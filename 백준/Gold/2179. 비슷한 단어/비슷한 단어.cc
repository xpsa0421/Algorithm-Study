#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const int MAX = 20000 * 100 + 1;
int unused = 2;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int wordIndex = -1;
};

TrieNode* root = new TrieNode();

string prefix;
int prefixIdx = MAX;
int prefixLen;

void insert(const string& s, int wordIdx)
{
    TrieNode* cur = root;
    string tmp = "";
    int tmpPreIdx = -1;
    bool canPrefix = true;

    for (char c : s)
    {
        if (cur->children.find(c) == cur->children.end())
        {
            cur->children[c] = new TrieNode();
            cur->children[c]->wordIndex = wordIdx;
            canPrefix = false;
        }
        else if (canPrefix)
        {
            tmp += c;
            tmpPreIdx = cur->children[c]->wordIndex;
        }
        cur = cur->children[c];
    }

    int tmpLen = tmp.length();
    if (prefixLen < tmpLen)
    {
        prefix = tmp;
        prefixIdx = tmpPreIdx;
        prefixLen = tmpLen;
    }
    else if (prefixLen == tmpLen)
    {
        if (prefixIdx > tmpPreIdx)
        {
            prefix = tmp;
            prefixIdx = tmpPreIdx;
            prefixLen = tmpLen;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> words;
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        insert(s, i);
        words.push_back(s);
    }

    int foundCnt = 0;
    for (auto& s : words)
    {
        bool isMatch = true;
        for (int i = 0; i < prefixLen; i++)
        {
            if (s[i] != prefix[i])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
        {
            cout << s << '\n';
            if (++foundCnt == 2) break;
        }
    }
}
