/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
// Level order traversal to turn the tree into a string.
        if(!root) return "";
        string s = "";
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

// Just one modification to level order traversal here is that if we find a null node, we still enter it into our string so that when we read it later while deserialising, we will know which is null and which is'nt.
            if(temp == NULL) s.append("#,");
            else s.append(to_string(temp->val)+',');
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
// What stringstream does is that it takes the whole string in as an input like "cin". I'll write more about it when I understand it better.
        stringstream s(data);
        string str;
// Now what getline does is that we take the s string made by stringstream, and then insert all the values before a comma into the string str. Like if we have the string 1,2,3,4,#,#,#,# then the first getline will make the root node = 1.
        getline(s, str, ',');
// Here we make it a root node
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
// Now we start the bfs traversal, since we are done with our root node, our s moves on towards the next literal before the comma, now if its a # i.e. NULL, we set the current node's left value as null, else if it contains a value then we simply just create a new node, set it as the left and then push it into the queue for further BFS traversal.
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            } else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

// As we did with the left side, since we are done with our root node, our s moves on towards the next literal before the comma, now if its a # i.e. NULL, we set the current node's right value as null, else if it contains a value then we simply just create a new node, set it as the right and then push it into the queue for further BFS traversal.
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            } else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
// We keep on doing so and in the end we will finally get our tree.
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));