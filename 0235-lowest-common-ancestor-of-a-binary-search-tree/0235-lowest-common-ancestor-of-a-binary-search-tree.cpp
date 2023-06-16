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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(p->val>root->val && q->val>root->val){
                root=root->right;
            }
            else if(p->val<root->val && q->val<root->val){
                root=root->left;
            }
            else{
                return root;
            }
        }
        return NULL;
//         if(root==NULL) return NULL;
//         if(root->val == p->val || root->val == q->val)return root;

//         if(root->val > p->val && root->val < q->val)return root;
//         else if(root->val > q->val && root->val < p->val)return root;

//         if(root->val > p->val && root->val > q->val){
//             return lowestCommonAncestor(root->left,p,q);
//         }
//         else if(root->val < p->val && root->val < q->val){
//             return lowestCommonAncestor(root->right,p,q);
//         }

//         return NULL;
        
        // if(root->val==p->val)return root;
        // if(root->val==q->val)return root;
        // while(root!=NULL){
        //     if((root->val>p->val) && (root->val<p->val) || root->val==p->val || root->val==q->val){
        //         return root;
        //     }
        //     else if((root->val>p->val) && (root->val>q->val)){
        //         root=root->right;
        //     }
        //     else if((root->val<p->val) && (root->val<q->val)){
        //         root=root->left;
        //     }
        // }
        // return root;
    }
};