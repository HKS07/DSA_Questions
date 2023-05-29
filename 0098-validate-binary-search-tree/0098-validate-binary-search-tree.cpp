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
    bool vali( TreeNode *r, long long int lb, long long int ub )
    {
        if( r == NULL ) return true;
        
        if( r->val <= lb || r->val >= ub ) return false; 
        // bool l = ;
        // bool ro = ;
        
        return vali( r->left, lb, r->val )&&vali( r->right, r->val, ub );
    }
    bool isValidBST(TreeNode* root) {
        // if( root ->left == NULL && root->right == NULL ) return true;
        long long int min = -1000000000000, max = 1000000000000;
        return vali( root, min, max);
    }
};