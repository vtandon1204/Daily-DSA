// Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5

// Input: c = 3
// Output: false

#include <bits/stdc++.h>
bool judgeSquareSum(int c)
{
    // long low = 0;
    // long high = sqrt(c);
    // while(low<=high){
    //     // long mid = (low+high)/2;
    //     long val1 = low*low;
    //     long val2 = high*high;
    //     if(val1 + val2 == c){
    //         return true;
    //     }
    //     else if ((val1 + val2)<c){
    //         low++;
    //     }
    //     else{
    //         high--;
    //     }
    // }
    // return false;

    for (long a = 0; a * a <= c; a++)
    {
        double b = sqrt(c - a * a);
        if (b == (int)b)
        {
            return true;
        }
    }
    return false;
}