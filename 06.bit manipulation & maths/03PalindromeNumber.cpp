#include <bits/stdc++.h>
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf)
    {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }
    return x == reversedHalf || x == reversedHalf / 10;
}

// bool isPalindrome(int x) {
//     bool ans = true;
//     if(x<0){
//         return false;
//     }
//     vector<int> temp;
//     while(x){
//         int digit = x%10;
//         temp.push_back(digit);
//         x /= 10;
//     }
//     reverse(temp.begin(),temp.end());
//     for(int i=0;i<temp.size();i++){
//         cout<<temp[i]<<" ";
//     }
//     cout<<endl;
//     int i=0;
//     int j=temp.size()-1;
//     while(i<=j){
//         if(temp[i]!=temp[j]){
//             ans=false;
//             break;
//         }
//         i++;
//         j--;
//     }
//     return ans;
// }