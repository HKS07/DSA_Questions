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
        //base case
        if( root == NULL ) return NULL;
        
        int c = root->val;
        
        if( c < p->val && c < q->val ) return lowestCommonAncestor(root->right,p,q);
        if( c > p->val && c > q->val ) return lowestCommonAncestor(root->left,p,q);
        
        return root;
    }
};