// Copy List with Random Pointer

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
