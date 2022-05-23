/* Leetcode 1721
  Swapping Nodes in a Linked List
    You are given the head of a linked list, and an integer k.
    Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed). */

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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *a1=NULL,*a2=NULL;
        ListNode *t = NULL;
        t=head;
        int x=0,n=0;
        while(t!=NULL)
        {
            n++;
            t=t->next;
        }
        t=head;
        while(t!=NULL)
        {
            x++;
            if(x==k)
                a1=t;
            if(x==(n-k+1))
                a2=t;
            t=t->next;
        }
        swap(a1->val, a2->val);
        return head;
    }
};
