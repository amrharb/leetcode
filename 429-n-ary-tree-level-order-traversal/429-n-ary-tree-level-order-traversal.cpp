/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>cur;
            while(sz--){
                auto it=q.front();q.pop();
                cur.push_back(it->val);
                for(auto&el:it->children){
                    if(el!=NULL)q.push(el);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};