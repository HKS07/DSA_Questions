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
class BSTitr {
    private:
    stack<TreeNode*> s;
    bool reverse = false;
    public:
    BSTitr( TreeNode * r, bool isReverse )
    {
        reverse = isReverse;
        inStack( r );
    }
    void inStack( TreeNode *r )
    {
        for(; r != NULL; )
        {
            if( !reverse ) 
            {
                s.push(r); r = r->left;
            }
            else
            {
                s.push(r); r = r->right;
            }
        }
    }
    int next(  )
    {
        TreeNode *t = s.top();
        s.pop();
        if( !reverse ) inStack( t->right );
        else inStack( t->left );
        return t->val;
    }
    bool hasNext(  )
    {
        return !s.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTitr l( root, false );
        BSTitr r( root, true );
        
        int i = l.next();
        int j = r.next();
        
        while( i < j )
        {
            if( i + j == k ) return true;
            else if( i + j > k ) 
                j = r.next();
            else 
                i = l.next();
        }
        return false;
    }
};