/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void duplicateNodes(Node *head) {
        Node *p = head;
        while(p) {
            Node* new_node = new Node(p->val);
            new_node->next = p->next;
            p->next = new_node;
            p = new_node->next;
        }
    }
    
    void setDuplicateRandom(Node *head) {
        Node *p = head;
        while(p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
    }
    
    Node* seperateDuplicate(Node *head) {
        if (!head) return nullptr;
        Node *p = head;
        Node *duplicate_head = head->next;
        Node *d_p = duplicate_head;
        while(p) {
            p->next = d_p->next;
            p = p->next;
            if (p) 
                d_p->next = p->next;
            d_p = d_p->next;
        }
        return duplicate_head;
    }
    
    
    Node* copyRandomList(Node *head) {
        duplicateNodes(head);
        setDuplicateRandom(head);
        return seperateDuplicate(head);
    }
};