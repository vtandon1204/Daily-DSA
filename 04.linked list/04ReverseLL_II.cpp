#include <bits/stdc++.h>
// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Input: head = [5], left = 1, right = 1
// Output: [5]
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    // ListNode* curr=head;
    // ListNode* prev=NULL;
    // ListNode* next=NULL;
    // for(int i=1;i<=left;i++){
    //     prev=curr;
    //     curr=curr->next;
    // }
    // ListNode* first_left = prev;
    // int count = left;
    // while(count<right){
    //     next=curr->next;
    //     curr->next=prev;
    //     prev = curr;
    //     curr = next;
    //     count++;
    // }
    // if(prev->next) head->next = prev;
    // first_left->next=curr;
    // return head;

    if (!head || left == right)
        return head;

    ListNode *dummy =
        new ListNode(0); // Create a dummy node to simplify edge cases
    dummy->next = head;
    ListNode *prev = dummy;

    // Step 1: Reach the node just before the `left` position
    for (int i = 1; i < left; ++i)
    {
        prev = prev->next;
    }

    // `start` will be the first node of the sublist to be reversed
    ListNode *start = prev->next;
    // `then` will be the node that is used to reverse the sublist
    ListNode *then = start->next;

    // Step 2: Reverse the sublist from `left` to `right`
    for (int i = 0; i < right - left; ++i)
    {
        start->next =
            then->next;          // Connect the `start` node to the node after `then`
        then->next = prev->next; // Insert `then` node before `prev->next`
        prev->next = then;       // Move `prev` node to point to `then`
        then =
            start
                ->next; // Move `then` to the next node in the original list
    }

    // Step 3: Return the new head (dummy->next)
    ListNode *newHead = dummy->next;
    delete dummy; // Clean up dummy node
    return newHead;
}