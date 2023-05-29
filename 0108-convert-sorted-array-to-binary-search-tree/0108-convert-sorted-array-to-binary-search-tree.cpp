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
    TreeNode* sA( vector<int>& nums, int l, int r )
    {
        //base case
        if( l > r  ) return NULL;
        // defining root value and mid value
        int mid = ( l + r)/ 2;
        TreeNode *root = new TreeNode( nums[mid] );
        
        //left and right call for root
        root->left = sA( nums, l, mid - 1 );
        root->right = sA( nums, mid + 1, r );
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sA( nums, 0, nums.size() -1 );
    }
};