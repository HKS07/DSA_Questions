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
    TreeNode* p2i( vector<int>& pOrd, int pL, int pR, vector<int>& iOrd, int iL, int iR, map<int,int> &m)
    {
        if( pL < 0 || pL > pR  && iL < 0 || iL > iR) return NULL;
        TreeNode *root = new TreeNode( pOrd[pL]);
        
        // cout<<root->val<<" ";
        int nlEle = m[pOrd[pL]] - iL;
        int iEle = m[pOrd[pL]];
        
        root->left = ( pR - pL ) == 0 ? NULL : p2i( pOrd, pL + 1, pL + nlEle,iOrd, iL,  iEle - 1, m);
        root->right = ( iR - iL ) == 0 ? NULL : p2i( pOrd, pL + nlEle + 1, pR,iOrd, iEle + 1,iR , m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for( int i = 0; i < inorder.size(); ++i )
        {
            m.insert({inorder[i],i});// {inorder value -> 0-based index}
        }
        return p2i( preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }
};