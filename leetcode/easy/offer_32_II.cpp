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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        if (!root) {
            return ret;
        }
        else {
            queue<TreeNode*> Q;
            Q.push(root);
            
            while (!Q.empty()) {
                ret.push_back(vector<int>());
                int length = Q.size();
                for (int i = 0; i < length; ++i) {
                    TreeNode* tmp = Q.front();
                    Q.pop();
                    ret.back().push_back(tmp -> val);
                    if (tmp -> left) {
                        Q.push(tmp -> left);
                    }
                    if (tmp -> right) {
                        Q.push(tmp -> right);
                    }
                }
                
            }
        }

        return ret;
    }
};