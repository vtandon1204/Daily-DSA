#include <bits/stdc++.h>
// Convert a non-negative integer num to its English words representation.

// Input: num = 123
// Output: "One Hundred Twenty Three"

// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
string generateString(int num)
{
    string oneDigit[] = {"Zero", "One", "Two", "Three", "Four",
                         "Five", "Six", "Seven", "Eight", "Nine"};
    string twoDigit[] = {"Ten", "Eleven", "Twelve", "Thirteen",
                         "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                         "Eighteen", "Nineteen"};
    string tenDigit[] = {"", "", "Twenty", "Thirty", "Forty",
                         "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result = "";
    if (num > 99)
    {
        result += oneDigit[num / 100] + " Hundred ";
    }
    num %= 100;
    if (num > 9 && num < 20)
    {
        result += twoDigit[num - 10] + " ";
    }
    else
    {
        if (num >= 20)
        {
            result += tenDigit[num / 10] + " ";
        }
        num %= 10;
        if (num > 0)
        {
            result += oneDigit[num] + " ";
        }
    }
    return result;
}
string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    string largeDigit[] = {"Thousand", "Million", "Billion"};
    string ans = generateString(num % 1000);
    num /= 1000;
    for (int i = 0; i < 3; ++i)
    {
        if (num > 0 && num % 1000 > 0)
        {
            ans = generateString(num % 1000) + largeDigit[i] + " " +
                  ans;
        }
        num /= 1000;
    }
    return ans.substr(0, ans.size() - 1);
}