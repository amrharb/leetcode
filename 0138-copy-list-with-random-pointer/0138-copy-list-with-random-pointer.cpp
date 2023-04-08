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
private:
    unordered_map<Node*,Node*>cloned;
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        if(cloned.find(head)!=cloned.end())
            return cloned[head];
        Node* newNode=new Node(head->val);
        cloned[head]=newNode;
        newNode->next=copyRandomList(head->next);
        newNode->random=copyRandomList(head->random);
        return newNode;
    }
};