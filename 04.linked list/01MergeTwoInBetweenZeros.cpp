#include <bits/stdc++.h>
ListNode *mergeNodes(ListNode *head)
{
    ListNode *temp = head->next;
    ListNode *ans = NULL;
    ListNode *temp_ans = NULL;
    while (temp)
    {
        int sum = 0;
        while (temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }
        ListNode *node = new ListNode(sum);
        if (ans == NULL)
        {
            ans = node;
            temp_ans = ans;
        }
        else
        {
            temp_ans->next = node;
            temp_ans = node;
        }
        temp = temp->next;
    }
    return ans;
}