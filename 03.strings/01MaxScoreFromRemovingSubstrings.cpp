#include <bits/stdc++.h>
// You are given a string s and two integers x and y. You can perform two types of operations any number of times.
// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
int maximumGain(string s, int x, int y)
{
    int a = 0;
    int b = 0;
    int lesser = min(x, y);
    int result = 0;

    for (char ch : s)
    {
        if (ch > 'b')
        {
            result += min(a, b) * lesser;
            a = 0;
            b = 0;
        }
        else if (ch == 'a')
        {
            if (x < y && b > 0)
            {
                b--;
                result += y;
            }
            else
            {
                a++;
            }
        }
        else
        {
            if (x > y && a > 0)
            {
                a--;
                result += x;
            }
            else
            {
                b++;
            }
        }
    }

    result += min(a, b) * lesser;
    return result;
}