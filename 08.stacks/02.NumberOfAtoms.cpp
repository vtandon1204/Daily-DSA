#include <bits/stdc++.h>
// Given a string formula representing a chemical formula, return the count of each atom.
// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.
// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.
// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.
// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order),
// followed by its count (if that count is more than 1), followed by the second name (in sorted order),
// followed by its count (if that count is more than 1), and so on.
// The test cases are generated so that all the values in the output fit in a 32-bit integer.

// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

string countOfAtoms(string exp)
{
    map<string, int> atoms;
    string ans;
    int cnt = 0, mult = 1;
    stack<int> st;

    for (int i = size(exp) - 1; i >= 0; i--)
    {
        if (isalpha(exp[i]) and islower(exp[i]))
        {
            int len = 2;
            i--;

            while (i >= 0 and islower(exp[i]))
            {
                i--;
                len++;
            }

            string atom = exp.substr(i, len);
            atoms[atom] += max(cnt, 1) * mult;
            cnt = 0;
        }
        else if (isalpha(exp[i]) and isupper(exp[i]))
        {
            string atom(1, exp[i]);
            atoms[atom] += max(cnt, 1) * mult;
            cnt = 0;
        }
        else if (isdigit(exp[i]))
        {
            cnt = exp[i] - '0';
            int p = 10;

            while (i - 1 >= 0 and isdigit(exp[i - 1]))
            {
                cnt += p * (exp[--i] - '0');
                p *= 10;
            }
        }
        else if (exp[i] == ')')
        {
            st.push(mult);
            mult *= max(cnt, 1);
            cnt = 0;
        }
        else
        {
            mult = st.top();
            st.pop();
        }
    }

    for (auto [atom, count] : atoms)
    {
        ans += atom;

        if (count > 1)
        {
            ans += to_string(count);
        }
    }

    return ans;
}