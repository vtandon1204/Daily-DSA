#include <bits/stdc++.h>
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
int lengthOfLastWord(string s)
{
    bool flag = false;
    int len = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((static_cast<int>(s[i]) >= 97 && static_cast<int>(s[i]) <= 122) ||
            (static_cast<int>(s[i]) >= 65 && static_cast<int>(s[i]) <= 90))
        {
            len++;
            flag = true;
        }
        else if (flag)
        {
            break;
        }
    }
    return len;
}