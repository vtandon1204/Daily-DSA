#include <bits/stdc++.h>
string reverseParentheses(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == ')')
        {
            string temp;
            while (!st.empty() && st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            for (auto revCh : temp)
            {
                st.push(revCh);
            }
        }
        else
        {
            st.push(ch);
        }
    }
    string result;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}