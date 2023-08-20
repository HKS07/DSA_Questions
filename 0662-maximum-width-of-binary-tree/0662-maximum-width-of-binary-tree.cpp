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
    int widthOfBinaryTree(TreeNode* root) {
        int w = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while( !q.empty() )
        {
            int s = q.size();
            int l = q.front().second, r ;
            for( int i = 0; i < s; ++i )
            { 
                pair<TreeNode*,int> p = q.front();
                q.pop();
                if(i == s-1) r = p.second;
                
                if(p.first->left) q.push({p.first->left, (long long)2*p.second+1});
                if(p.first->right) q.push({p.first->right, (long long)2*p.second+2});
            }
            w = max(w,r-l+1);
        }
        return w;
    }
};