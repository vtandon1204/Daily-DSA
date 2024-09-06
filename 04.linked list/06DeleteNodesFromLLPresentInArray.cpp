#include <bits/stdc++.h>
// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes 
// from the linked list that have a value that exists in nums.

// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
// Remove the nodes with values 1, 2, and 3.

// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
// Remove the nodes with value 1.

// Input: nums = [5], head = [1,2,3,4]
// Output: [1,2,3,4]

// ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//     unordered_set<int> numSet(nums.begin(), nums.end());

//     ListNode* curr = head;
//     ListNode* prev = NULL;

//     while (curr) {
//         if (numSet.find(curr->val) != numSet.end())
//         {
//             if(curr==head){
//                 head = head->next;
//             }
//             else{
//                 prev->next = curr->next;
//                 // curr->next = NULL;
//             }
//         } else {
//             prev = curr;
//         }
//         curr = curr->next;
//     }
//     return head;
// }
bool binarySearch(int val, vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (nums[mid] == val)
        {
            return true;
        }
        else if (nums[mid] > val)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return false;
}
ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    sort(nums.begin(), nums.end());
    ListNode *temp = head;
    ListNode *ans = NULL;
    ListNode *curr = NULL;
    while (temp)
    {
        int val = temp->val;
        if (binarySearch(val, nums))
        {
            if (curr)
            {
                curr->next = temp->next;
            }
        }
        else
        {
            if (ans == NULL)
            {
                ans = temp;
            }
            curr = temp;
        }
        temp = temp->next;
    }
    return ans;
}