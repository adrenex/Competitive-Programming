/* Leetcode 138
    Copy List with Random Pointer
    
    A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
    Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
    where each new node has its value set to the value of its corresponding original node. 
    Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list
    and copied list represent the same list state. 
    None of the pointers in the new list should point to nodes in the original list. */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* front = head;
        Node* itr = head;
        
        //Step 1
        //We made a new copy node and place that node next to the same node in the given linked list;
        while(itr){
            front = itr->next;
            Node* copy = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr=front;
            
        }
        
        //Step 2
        //We assign random pointer to every copied node.
        //We have done this using the fact that  **itr->next->random = itr->random->next;**
        itr = head;
        while(itr){
            if(itr->random !=NULL)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        
        //Step 3
        //We created a new node which points to the copied linked list and then separate both linked list.
        Node* ans = new Node(0);
        Node* copy = ans;
        front = head;
        itr = head;
        while(itr){
            front = itr->next->next;
            copy->next = itr->next;
            copy = copy->next;
            itr->next = front;;
            itr = itr->next;
        }   
        return ans->next;
    }
};
