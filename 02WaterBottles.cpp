#include <bits/stdc++.h>
// There are numBottles water bottles that are initially full of water. 
// You can exchange numExchange empty water bottles from the market with one full water bottle.
// The operation of drinking a full water bottle turns it into an empty bottle.
// Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

// Input: numBottles = 9, numExchange = 3
// Output: 13
// Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
// Number of water bottles you can drink: 9 + 3 + 1 = 13.

// Input: numBottles = 15, numExchange = 4
// Output: 19
// Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
// Number of water bottles you can drink: 15 + 3 + 1 = 19.

int numWaterBottles(int numBottles, int numExchange)
{
    int total = numBottles;
    int neww = numBottles / numExchange;
    int rem = numBottles % numExchange;
    while (neww)
    {
        int rem = neww % numExchange;
        int neww = neww / numExchange;
        total += neww;
        neww += rem;
    }
    return total;
    // return numBottles + (numBottles-1)/(numExchange-1);
}