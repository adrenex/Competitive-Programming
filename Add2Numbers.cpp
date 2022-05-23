/* Leetcode 2
  Add Two Numbers

      You are given two non-empty linked lists representing two non-negative integers. 
      The digits are stored in reverse order, and each of their nodes contains a single digit.
      Add the two numbers and return the sum as a linked list. */
     
class Solution {
public: 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* curr = new ListNode();
        ListNode* temp=curr;
        int remainder = 0, sum;
        while (l1 != NULL || l2 != NULL || remainder != 0) 
        {
            sum = remainder + (l1 == 0 ? 0 : l1->val) + (l2 == 0 ? 0: l2->val);
            remainder = sum/10;
            sum %= 10;
            curr->next = new ListNode();
            curr->next->next = NULL;
            curr->next->val = sum;
            curr = curr->next;
            l1 = (l1 == 0 ? 0 : l1->next);
            l2 = (l2 == 0 ? 0 : l2->next);
        }
        return temp->next;
    }
};
