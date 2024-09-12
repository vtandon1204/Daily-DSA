#include <bits/stdc++.h>
// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the 
// string appear in the string allowed. Return the number of consistent strings in the array words.

// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
// Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

// Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
// Output: 7
// Explanation: All strings are consistent.

// Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
// Output: 4
// Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
int countConsistentStrings(string allowed, vector<string> &words)
{
    int ans = 0;
    // unordered_map<char, int> mp;
    bitset<26> bs;
    for (auto it : allowed)
    {
        // mp[it] = 1;
        bs[it - 'a'] = 1;
    }
    for (int i = 0; i < words.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < words[i].length(); j++)
        {
            // if (mp.find(words[i][j]) == mp.end()) {
            //     flag = false;
            //     break;
            // }
            if (!bs[words[i][j] - 'a'])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}