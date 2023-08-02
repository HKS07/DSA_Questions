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
    int sol = INT_MIN;
    int help( TreeNode* r )
    {
        if( r == NULL ) return 0;
        
        int le = help(r->left);
        int ri = help(r->right);
        
        if( le < 0 ) le = 0;
        if( ri < 0 ) ri = 0;
        sol = max( sol, le + ri + r->val);
        return max(le,ri) + r->val;
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return sol;
    }
};