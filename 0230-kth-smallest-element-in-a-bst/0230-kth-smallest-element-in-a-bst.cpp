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
    int sol = -1;
    void iOrd( TreeNode *r, int k, int &c )
    {
        if( r == NULL ) return;
        
        iOrd( r->left, k, c );
        // 
        if( c == k )
        {
            sol = r->val;
            c++;
            return;
        }
        else 
        {
            c++;
        }
        iOrd( r->right, k, c);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int c = 1;
        iOrd( root, k, c );
        return sol;
    }
};