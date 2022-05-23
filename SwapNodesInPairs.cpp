*/ Leetcode 24
	Swap Nodes in Pairs

	Given a linked list, swap every two adjacent nodes and return its head. 
	You must solve the problem without modifying the values in the list's nodes. */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *a, *b, *p;

        if (head && head->next) {
            a = head;
            head = b = a->next;
            a->next = b->next;
            p = b->next = a;
        }
        while (p && p->next && p->next->next) {
            a = p->next;
            p->next = b = a->next;
            a->next = b->next;
            p = b->next = a;
        }

        return head;
    }
};