/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    // Stores nodes in the exact preorder
    // required by the flattened tree.
    void preorder(
        TreeNode* root,
        vector<TreeNode*>& nodes
    ) {
        if (root == nullptr) {
            return;
        }

        nodes.push_back(root);

        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

public:
    // Reconnects preorder nodes into
    // one right-linked chain.
    TreeNode* flatten(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<TreeNode*> nodes;

        preorder(root, nodes);

        // Consecutive preorder nodes are linked
        // through right pointers only.
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        // The final node terminates
        // the flattened structure.
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;

        return root;
    }
};
