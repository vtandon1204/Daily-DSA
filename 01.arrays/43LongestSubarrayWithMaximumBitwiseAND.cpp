#include <vector>
#include <string>
using namespace std;
#include<bits/stdc++.h>
string solve(int m, const vector<string>& s) {
    int ts = 0;
    for (const auto& str : s) {
        int sv = 1;
        for (char c : str) {
            // Compute mod 2 to avoid large numbers
            sv *= (static_cast<int>(pow(static_cast<int>(c), m)) % 2);
            sv %= 2;  // We only care about the parity
        }
        ts += sv;
    }
    return (ts % 2 == 0) ? "EVEN" : "ODD";
}


int main() {
    // Directly declaring and initializing variables
    int m = 2;  // Example value for m
    vector<string> s = {"azbde", "abcher","acegk"};  // Example list of strings

    // Calling the solve function
    string result = solve(m, s);

    // Output the result
    cout << "The result is: " << result << endl;

    return 0;
}






// #include <iostream>
// #include <vector>
// #include <algorithm>

// long getMinCost(std::vector<int> pods, std::vector<int> cost) {
//     long totalCost = 0;

//     // Create a vector of pairs (pods[i], cost[i]) and sort them by pods
//     std::vector<std::pair<int, int>> podCostPairs;
//     for (int i = 0; i < pods.size(); ++i) {
//         podCostPairs.push_back({pods[i], cost[i]});
//     }
    
//     // Sort based on pods values first
//     std::sort(podCostPairs.begin(), podCostPairs.end());

//     // Now iterate through the sorted podCostPairs to ensure uniqueness
//     for (int i = 1; i < podCostPairs.size(); ++i) {
//         // If current pod value is not unique (same as previous), fix it
//         if (podCostPairs[i].first <= podCostPairs[i - 1].first) {
//             // We need to increase the current pod to be greater than the previous one
//             int requiredValue = podCostPairs[i - 1].first + 1;
//             int increment = requiredValue - podCostPairs[i].first;
            
//             // Add the cost of incrementing the current pod
//             totalCost += increment * podCostPairs[i].second;
            
//             // Update the pod value to the required unique value
//             podCostPairs[i].first = requiredValue;
//         }
//     }

//     return totalCost;
// }

// int main() {
//     // Example input
//     int n = 8; // Number of microservices

//     // Pods and their corresponding increment costs
//     std::vector<int> pods = {8, 6, 8};
//     std::vector<int> cost = {9, 5, 7};

//     // Call the getMinCost function to compute the result
//     long minCost = getMinCost(pods, cost);

//     // Output the result
//     std::cout << "The minimum cost necessary: " << minCost << std::endl;

//     return 0;
// }






// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// long rearrangeStudents(vector<int> arrA, vector<int> arrB) {
//     int n = arrA.size();

//     sort(arrA.begin(), arrA.end(), greater<int>());
//     sort(arrB.begin(), arrB.end(), greater<int>());
    
//     long totalCost = 0;

//     for (int i = 0; i < n; ++i) {
//         if (arrA[i] != arrB[i]) {
//             totalCost += min(arrA[i], arrB[i]);
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         if (arrA[i] != arrB[i]) {
//             return -1;
//         }
//     }
    
//     return totalCost;
// }

// int main() {
//     vector<int> arrA = {4, 2, 2, 2};
//     vector<int> arrB = {1, 4, 1, 2};
    
//     long result = rearrangeStudents(arrA, arrB);
//     cout << result << endl;  // Output should be 1
    
//     return 0;
// }




