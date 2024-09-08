#include <bits/stdc++.h>
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts 
// being null. The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than 
// or equal to parts occurring later. Return an array of the k parts.

// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].

// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
int len(ListNode *head)
{
    ListNode *curr = head;
    int len = 0;
    while (curr)
    {
        curr = curr->next;
        len++;
    }
    return len;
}
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> ans(k);
    ListNode *curr = head;
    int length = len(head);
    cout << length << endl;
    if (length < k)
    {
        int i = 0;
        while (curr)
        {
            ListNode *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            ans[i++] = temp;
        }
        return ans;
    }
    else
    {
        int split = length / k;
        int rem = length % k;
        // cout<<split;
        ListNode *temp = head;
        ListNode *next = head;
        int j = 0;
        while (next)
        {
            int i = 0;
            temp = curr;
            while (i < split - 1)
            {
                temp = temp->next;
                i++;
            }
            if (rem)
            {
                rem--;
                temp = temp->next;
            }
            next = temp->next;
            temp->next = NULL;
            ans[j++] = curr;
            curr = next;
        }
        return ans;
    }
    // int split = length / k;
    // int rem = length % k;
    // for (int i = 0; i < k && curr; i++) {
    //     ans[i] = curr;
    //     int size = split + (rem-- > 0 ? 1 : 0);
    //     for (int j = 1; j < size; j++) {
    //         curr = curr->next;
    //     }
    //     ListNode* next = curr->next;
    //     curr->next = NULL;
    //     curr = next;
    // }
    // return ans;
}