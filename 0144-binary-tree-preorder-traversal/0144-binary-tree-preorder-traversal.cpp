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
    void help( TreeNode* r, vector<int> &sol )
    {
        if( r == NULL ) return ;
        sol.push_back(r->val);
         help(r->left,sol);
        help(r->right,sol);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> sol;
         help( root, sol );
        return sol;
    }
};