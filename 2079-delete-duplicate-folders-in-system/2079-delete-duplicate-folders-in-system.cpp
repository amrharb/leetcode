class TrieNode {
public:
    string name;
    unordered_map<string, TrieNode*> children;
    bool isDeleted = false;

    TrieNode(string name = "") : name(name) {}
};

class Solution {
public:
    TrieNode* buildTrie(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (auto& path : paths) {
            TrieNode* curr = root;
            for (auto& folder : path) {
                if (!curr->children.count(folder)) {
                    curr->children[folder] = new TrieNode(folder);
                }
                curr = curr->children[folder];
            }
        }
        return root;
    }

    string serialize(TrieNode* node, unordered_map<string, vector<TrieNode*>>& hash) {
        if (node->children.empty()) return "()";

        vector<pair<string, string>> subs;
        for (auto& [name, child] : node->children) {
            subs.push_back({name, serialize(child, hash)});
        }

        sort(subs.begin(), subs.end());
        string serial;
        for (auto& [name, ser] : subs) {
            serial += "(" + name + ser + ")";
        }

        hash[serial].push_back(node);
        return serial;
    }

    void markDuplicates(unordered_map<string, vector<TrieNode*>>& hash) {
        for (auto& [serial, nodes] : hash) {
            if (nodes.size() > 1) {
                for (auto& node : nodes) {
                    node->isDeleted = true;
                }
            }
        }
    }

    void collectPaths(TrieNode* node, vector<string>& curr, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->isDeleted) {
                curr.push_back(name);
                res.push_back(curr);
                collectPaths(child, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = buildTrie(paths);

        unordered_map<string, vector<TrieNode*>> hash;
        serialize(root, hash);

        markDuplicates(hash);

        vector<vector<string>> res;
        vector<string> curr;
        collectPaths(root, curr, res);
        return res;
    }
};