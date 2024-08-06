#include <bits/stdc++.h>
// You are given a string word containing lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
// For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", 
// and three times to type "c" . It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
// The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of 
// times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.

// Input: word = "xyzxyzxyzxyz"
// Output: 12
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> one push on key 3
// "z" -> one push on key 4
// Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
// It can be shown that no other mapping can provide a lower cost.
// Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.

// Input: word = "aabbccddeeffgghhiiiiii"
// Output: 24
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// "f" -> one push on key 7
// "g" -> one push on key 8
// "h" -> two pushes on key 9
// "i" -> one push on key 9
// Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
// It can be shown that no other mapping can provide a lower cost.
int minimumPushes(string word)
{

    // ***********************************************************
    // map<char, int> freq;
    // for (char c : word) {
    //     freq[c]++;
    // }
    // for (auto it : freq) {
    //     cout << it.first << " --> " << it.second << endl;
    // }
    // int push = 0;
    // for (auto it : freq) {
    //     push += it.second;
    //     cout << push << endl;
    // }
    // int min_freq = INT_MAX;
    // for (auto it : freq) {
    //     min_freq = min(it.second, min_freq);
    // }
    // if (freq.size() > 8) {
    //     int extra = (freq.size() - 8) * min_freq;
    //     push += extra;
    // }
    // return push;
    // ***********************************************************
    vector<int> cnt(26);
    for (char &c : word)
    {
        ++cnt[c - 'a'];
    }
    // for(int i = 0;i<cnt.size();i++){
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<endl;
    sort(cnt.rbegin(), cnt.rend());
    // for(int i = 0;i<cnt.size();i++){
    //     cout<<cnt[i]<<" ";
    // }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
    {
        ans += (i / 8 + 1) * cnt[i];
    }
    return ans;
    // ***********************************************************
    // map<int, vector<char>> keypad;
    // set<char> uniqueChars(word.begin(), word.end());
    // map<char, bool> visited;
    // for (char ch : word) {
    //     visited[ch] = false;
    // }
    // int num = 2;
    // for (int i = 0; i < word.length(); i++) {
    //     if (visited.find(word[i]) == visited.end()) {
    //         visited[word[i]] = true;
    //         keypad[num].push_back(word[i]);
    //         num++;
    //         if (num > 9) {
    //             num = 2;
    //         }
    //     } else {
    //         continue;
    //     }
    // }
    // for (auto it : keypad) {
    //     cout << it.first << " --> ";
    //     for (int i = 0; i < it.second.size(); i++) {
    //         cout << it.second[i] << ",";
    //     }
    //     cout << endl;
    // }
    // int push = 0;
    // return push;
}