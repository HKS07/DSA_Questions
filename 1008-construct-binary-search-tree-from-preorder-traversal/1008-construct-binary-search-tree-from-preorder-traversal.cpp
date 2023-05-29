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
    TreeNode *consBST( vector<int>& pOrd, int &idx, int uB )
    {
        //base case
        if( idx == pOrd.size() || pOrd[idx] > uB ) return NULL;
        //operation
        TreeNode *root = new TreeNode( pOrd[idx++] );
        //recursive case
        root->left = consBST( pOrd, idx, root->val);
        root->right = consBST( pOrd, idx, uB);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return consBST( preorder, i, INT_MAX );
    }
};