/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur_root = root;
        while (cur_root) {
            Node* cur = cur_root;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                cur->right->next = cur->next == nullptr ? nullptr: cur->next->left;
                cur = cur->next;
            }
            cur_root = cur_root->left;
        }
        return root;
    }
};