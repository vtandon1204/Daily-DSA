#include <bits/stdc++.h>
// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a
// denominator 1. So in this case, 2 should be converted to 2/1.

// Input: expression = "-1/2+1/2"
// Output: "0/1"

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"

// Input: expression = "1/3-1/2"
// Output: "-1/6"

// Constraints:
// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1, 10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
string fractionAddition(string expression)
{
    int n = expression.size();
    int i = 0;
    int num = 0;
    int den = 1;
    while (i < n)
    {
        int sign = 1;
        if (expression[i] == '+' || expression[i] == '-')
        {
            if (expression[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        int nn = 0;
        while (i < n && isdigit(expression[i]))
        {
            nn = nn * 10 + (expression[i] - '0');
            i++;
        }
        nn *= sign;
        i++;
        int dd = 0;
        while (i < n && isdigit(expression[i]))
        {
            dd = dd * 10 + (expression[i] - '0');
            i++;
        }
        num = num * dd + nn * den;
        den *= dd;

        int gcdVal = gcd(abs(num), den);
        num /= gcdVal;
        den /= gcdVal;
    }
    return to_string(num) + '/' + to_string(den);
}