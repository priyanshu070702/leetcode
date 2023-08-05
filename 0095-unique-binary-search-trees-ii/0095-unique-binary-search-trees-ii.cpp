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

    vector<TreeNode*> f(int start, int end, map<pair<int, int>, vector<TreeNode*>> &memo) {
        vector<TreeNode*> v;
        if(start > end) {
            v.push_back(NULL);
            return v;
        }
        if(memo.find({start, end}) != memo.end()) {
            return memo[{start, end}];
        }
        for(int i = start ; i <= end ; i++) {
            vector<TreeNode*> left = f(start, i-1, memo);
            vector<TreeNode*> right = f(i+1, end, memo);

            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i, l, r);
                    v.push_back(root);
                }
            }
        }
        
        return memo[{start, end}] = v;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return f(1, n, memo);
    }
};