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
class BSTIterator {
    stack<TreeNode*> s;
public:
    void inStack( TreeNode *r )
    {
        TreeNode* t = r;
        s.push(r);
        while( t->left )
        {
            s.push(t->left);
            t = t->left;
        }
    }
    BSTIterator(TreeNode* root) {
        inStack(root);
    }
    
    int next() {
        
        TreeNode *t = s.top();
        s.pop();
        
        if( t->right ) inStack( t->right );
        return t->val;
    }
    
    bool hasNext() {
     if( !s.empty() ) return true ;
         else return false;   
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */