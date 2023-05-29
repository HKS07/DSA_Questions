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
    TreeNode *consBST( vector<int>& pOrd, int pL, int pR, vector<int>& iOrd, int iL, int iR , map<int,int> &m)
    {
        //base case
        if( pL > pR || iL > iR ) return NULL;
        
        //creating root and idx
        TreeNode *root = new TreeNode(pOrd[pL]);
        int idx = m[pOrd[pL]];
        int nEle = idx - iL;
        
        //recursive case
        root->left = consBST( pOrd, pL + 1, pL + nEle, iOrd, iL, idx - 1, m);
        root->right = consBST( pOrd, pL + nEle +1, pR, iOrd, idx + 1, iR, m);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> iOrd;
        iOrd = preorder;
        sort( iOrd.begin(), iOrd.end());
        map<int,int> m;
        for( int i = 0; i < iOrd.size(); ++i )
            m.insert({iOrd[i],i});
        return consBST( preorder, 0, iOrd.size()-1, iOrd, 0, iOrd.size()-1,m);
    }
};