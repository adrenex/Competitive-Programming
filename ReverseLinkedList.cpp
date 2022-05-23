/* Leetcode 206
    Reverse Linked List
      Given the head of a singly linked list, reverse the list, and return the reversed list. */
  
  class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nex=head;
        while(nex!=NULL)
        {
            nex=nex->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
};
