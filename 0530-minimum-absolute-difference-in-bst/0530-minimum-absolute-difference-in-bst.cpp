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
    TreeNode* prev=NULL;
    void solve(TreeNode* root, int &mn){
        if(root->left!=NULL){
            solve(root->left,mn);
        }
        if(prev!=NULL){
            mn=min(mn,abs(root->val - prev->val));
        }
        prev=root;
        if(root->right!=NULL){
            solve(root->right,mn);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int mn=INT_MAX;
        solve(root,mn);
        return mn;
        // int mn=INT_MAX;
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     int sz=q.size();
        //     while(sz--){
        //         auto p=q.front();
        //         q.pop();
        //     if(p->left!=NULL){
        //         int value=abs(p->val - p->left->val);
        //         mn=min(mn,value);
        //         q.push(p->left);
        //     }
        //     if(p->right!=NULL){
        //         int value=abs(p->val - p->right->val);
        //         mn=min(mn,value);
        //         q.push(p->right);
        //     }
        //     }
        // }
        // return mn;
        
    }
};