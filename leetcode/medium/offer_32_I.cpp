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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        
        if (!root) {
            return ret;
        }
        else {
            queue<TreeNode*> Q;
            Q.push(root);

            while (!Q.empty()) {
                TreeNode* tmp = Q.front();
                ret.push_back(tmp -> val);
                Q.pop();
                if (tmp -> left) {
                    Q.push(tmp->left);
                }
                if (tmp -> right) {
                    Q.push(tmp -> right);
                }
            }
        }

        return ret;
    }
};