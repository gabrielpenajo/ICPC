#include <bits/stdc++.h>

using namespace std;

bool contains(string s, vector<string> subs)
{
    for (int i = 0; i < subs.size(); i++)
    {
        if (s.find(subs[i]) != string::npos)
            return true;
    }
    return false;
}

// Function return the total palindromic subsequence 
long long countPS(string str, vector<string> substr) 
{ 
    long long n = str.size();
    map<int, long long> memo;

    //cout << "palindrome substrings:" << endl;
    for (int i = 0; i < str.size(); i++)
    {
        int botI = 0, topI = 0;
        int botP = 0, topP = 1;

        // palindromos pares
        if (i < str.size()-1)
        {
            for (int j = i; j - botP >= 0 && j + topP < str.size();)
            {
                if (str[j - botP] == str[j + topP] &&
                    !contains(str.substr(j - botP, botP + topP + 1), substr))
                {
                    if (memo.find(botP + topP + 1) != memo.end())
                        memo[botP + topP + 1]++;
                    else
                        memo[botP + topP + 1] = 1;
                    //cout << str.substr(j-botP, botP+topP+1) << endl;
                }
                else break;

                botP++;
                topP++;
            }
        }
        // palindromos impares
        for (int j = i; j-botI >= 0 && j+topI < str.size();)
        {
            if (str[j - botI] == str[j + topI] &&
                !contains(str.substr(j - botI, botI + topI + 1), substr))
            {
                if (memo.find(botI + topI + 1) != memo.end())
                    memo[botI + topI + 1]++;
                else
                    memo[botI + topI + 1] = 1;
                //cout << str.substr(j-botI, botI+topI+1) << endl;
            }
            else break;
            
            botI++;
            topI++;
        }
    }

    map<int, long long>::iterator it;
    long long ans = 0;
    for (it = memo.begin(); it != memo.end(); it++)
    {
        ans += it->second;
    }
    return ans;
}

int main()
{
    int size, nSubstr;
    while (cin >> size >> nSubstr)
    {
        string s;
        cin >> s;
        s = s.substr(0, size);
        vector<string> substrs;
        while (nSubstr--)
        {
            string aux;
            cin >> aux;
            substrs.push_back(aux);
        }
        long long palindromes = countPS(s, substrs);

        cout << palindromes << endl;
    }
}