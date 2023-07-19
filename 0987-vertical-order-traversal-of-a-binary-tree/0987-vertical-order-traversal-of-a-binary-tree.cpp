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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            TreeNode* p=f.first;
            int x=f.second.first;
            int y=f.second.second;
            mp[x][y].insert(p->val);
            if(p->left!=NULL){
                q.push({p->left,{x-1,y+1}});
            }
            if(p->right!=NULL){
                q.push({p->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>st;
            for(auto i:it.second){
                st.insert(st.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(st);
        }
        return ans;
    }
};