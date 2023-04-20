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
        if(root==NULL)return 0;
        queue<pair<TreeNode*,int>>q;
        long long ans=0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long fro=q.back().second, bac=q.front().second;
            while(n--){
                TreeNode* f=q.front().first;
                long long ind=q.front().second;
                q.pop();
                if(f->left!=NULL){
                    q.push({f->left,2*ind+1});
                }
                if(f->right!=NULL){
                    q.push({f->right,2*ind+2});
                }
            }
            ans=max(ans,fro-bac+1);
        }
        return ans;

    }
};
