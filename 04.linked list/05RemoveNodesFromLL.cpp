#include <bits/stdc++.h>
// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.

// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.

// Input: head = [1,1,1,1]
// Output: [1,1,1,1]
// Explanation: Every node has value 1, so no nodes are removed.
ListNode *removeNodes(ListNode *head, int maxVal = INT_MIN)
{

    if (!head)
    {
        return nullptr;
    }

    // Recursively process the rest of the list
    head->next = removeNodes(head->next, maxVal);

    // Update maxVal after processing the rest of the list
    if (head->next)
    {
        maxVal = max(maxVal, head->next->val);
    }

    // If current node's value is less than maxVal, skip this node
    return (head->val < maxVal) ? head->next : head;
}

// ListNode* removeNodes(ListNode* head) {
//     if (!head || !head->next) {
//         return head;
//     }

//     ListNode* temp = head;
//     ListNode* prev = NULL;

//     while (temp) {
//         ListNode* curr = temp->next;
//         while (curr) {
//             if (curr->val > temp->val) {
//                 if (temp == head) {
//                     head = curr;
//                     temp = head;
//                 } else {
//                     prev->next = curr;
//                     temp->next = NULL;
//                 }
//             }
//             curr = curr->next;
//         }
//         prev = temp;
//         temp = temp->next;
//     }
//     return head;
// }