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
    void bfs( TreeNode* r, map<TreeNode*,TreeNode*> &par)
    {
        queue<TreeNode*> q;
        q.push(r);
        while( !q.empty() )
        {
            int s = q.size();
            
            
            for( int i = 0; i < s; ++i )
            {
                TreeNode* p = q.front();
                q.pop();
                
                if( p->left ) 
                {
                    par[p->left] = p;
                    q.push(p->left);
                }
                if( p->right ) 
                {
                   par[p->right] = p;
                    q.push(p->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        bfs(root,par);
        
        vector<int> sol;
        map<TreeNode*,bool> vis;
        vis[target] = true;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        
        while( !q.empty() )
        {
            TreeNode *cur = q.front().first;
            int dist = q.front().second; q.pop();
            if( dist == k )
            {
                sol.push_back(cur->val);
                continue;
            }
            
            //child
            if( cur->left && !vis[cur->left] )
            {
                vis[cur->left] = 1;
                q.push({cur->left,dist+1});
            }
            if( cur->right && !vis[cur->right] )
            {
                vis[cur->right] = 1;
                q.push({cur->right,dist+1});
            }
            // parent
            if( par[cur] && !vis[par[cur]] )
            {
                
                vis[par[cur]] = 1;
                q.push({par[cur],dist+1});
            }
        }
        return sol;
    }
};