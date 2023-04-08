class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        unordered_map<Node*,Node*>cloned;
        Node* temp=head;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            cloned[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr)
               cloned[temp]->next=cloned[temp->next];
            if(temp->random!=nullptr)
                cloned[temp]->random=cloned[temp->random];
            temp=temp->next;
        }
        return cloned[head];
    }
};