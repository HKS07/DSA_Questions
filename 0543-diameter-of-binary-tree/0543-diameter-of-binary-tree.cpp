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
    int d = 0;
    int ht( TreeNode *r )
    {
        if( !r ) return 0;
        return max(ht(r->left),ht(r->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        
        int l = ht(root->left);
        int r = ht(root->right);
        
        d = max(d,l+r);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return d;
    }
};