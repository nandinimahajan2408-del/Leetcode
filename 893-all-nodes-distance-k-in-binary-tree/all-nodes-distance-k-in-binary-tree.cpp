/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void parenttrack(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*s=q.front();
            q.pop();

            if(s->left){
                q.push(s->left);
                mpp[s->left]=s;
            }
            if(s->right){
                q.push(s->right);
                mpp[s->right]=s;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>mpp;
       parenttrack(root,mpp,target);

       queue<TreeNode*>q;
       q.push(target);
       unordered_map<TreeNode*,bool>visited;
       visited[target]=true;

       int curlevel=0;

       while(!q.empty()){
        int s=q.size();

        if(curlevel==k) break;
        curlevel++;

        for(int i=0;i<s;i++){
         TreeNode* temp=q.front();
        q.pop();
        if(temp->left&&!visited[temp->left]){
            q.push(temp->left);
            visited[temp->left]=true;
        }
        if(temp->right&&!visited[temp->right]){
            q.push(temp->right);
            visited[temp->right]=true;
        }
        if(mpp[temp]&&!visited[mpp[temp]]){
            q.push(mpp[temp]);
            visited[mpp[temp]]=true;
        }
       }
       }
       vector<int>ans;
       while(!q.empty()){
        TreeNode*cur=q.front();
        q.pop();
        ans.push_back(cur->val);
       }
       return ans;

    }
};