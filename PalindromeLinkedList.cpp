/* Leetcode 234
  Palindrome Linked List
  
    Given the head of a singly linked list, return true if it is a palindrome
    ( With O(n) time complexity and O(1) space Complexity ) */
    
class Solution {
public:
    // finding middle node using Two pointer method
ListNode*middle(ListNode*head)
    {
        ListNode*temp=head;
        ListNode*fast=temp;
        ListNode*slow=temp;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
	// Reversing the linked list from the middle node
    ListNode*reverse(ListNode*head1)
    {
        ListNode*prev=NULL;
        ListNode*curr=head1;
        ListNode*nex=head1;
        while(nex!=NULL)
        {
            nex=nex->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*head1=middle(head);
        ListNode*head2=reverse(head1);
        ListNode*start=head;
		// Comparing the value part of both linked list
        while(head2!=NULL)
        {
            if(start->val!=head2->val)
                return false;
            start=start->next;
            head2=head2->next;
        }
        return true;
    }
};
