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
    int ht( TreeNode *r )
    {
        if( r == NULL ) return 0;
        return 1 + max( ht(r->left), ht(r->right));
    }
    bool isBalanced(TreeNode* root) {
        if( root == NULL) return true;
        int lH = 0, rH = 0;
        if( root->left != NULL )
         lH = ht(root->left);
        if( root->right != NULL )
         rH = ht(root->right);
        if( abs(rH-lH) > 1 ) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};