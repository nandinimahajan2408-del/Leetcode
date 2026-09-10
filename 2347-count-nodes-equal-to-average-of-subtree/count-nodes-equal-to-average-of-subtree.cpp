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

 pair<int,int>findavg(TreeNode*root,int &nodes){//treenode,matchingnode
    if(root==NULL){
        return {0,0};
    }
    pair<int,int>left=findavg(root->left,nodes);
    pair<int,int>right=findavg(root->right,nodes);

    int sum=left.first+right.first+root->val;
    int currcnt=left.second+right.second+1;

    if(sum/currcnt==root->val) nodes++;

    return{sum,currcnt};
 }
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int nodes=0;
    findavg(root,nodes);//return at last 24,6
    return nodes;
    }
};