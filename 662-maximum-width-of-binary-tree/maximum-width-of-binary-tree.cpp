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
public:
    int widthOfBinaryTree(TreeNode* root) {
     //enter nodes in queue
     if(root==nullptr) return 0;
     long long ans=0;
     queue<pair<TreeNode*,long long>>q;
     q.push({root,0});

     while(!q.empty()){
        int mini=q.front().second;
        
     long long first;
     long long last;
        
        int s=q.size();

        for(int i=0;i<s;i++){
            long long curr=q.front().second-mini;
            TreeNode*node=q.front().first;
            q.pop();

            if(i==0) first=curr;
            if(i==s-1) last=curr;

            if(node->left){
                q.push({node->left,curr*2+1});
            }
            if(node->right){
                q.push({node->right,curr*2+2});
            }
            ans=max(ans,last-first+1);
        }
     } 
     return ans;    
    }
};