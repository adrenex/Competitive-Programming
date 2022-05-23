/* Leetcode 2095
     Delete the Middle Node of a Linked List
       You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      
      if(head == NULL || head->next == NULL)
            return NULL;
      
       ListNode* slow = head ,*fast = head , *prev;
       
       while(fast!=NULL && fast->next!=NULL)
       {
         prev = slow;
         slow = slow->next ;
         fast = fast->next->next;
       }
      prev->next = slow->next;
      return head;
    }
};
