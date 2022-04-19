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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> res;

        if (!root) return res;

        if (root) {
            Q.push(root);
            
            while (!Q.empty()) {
                res.push_back(vector<int> ());
                int length = Q.size();
                
                for (int i = 0; i < length; ++i) {
                    auto root = Q.front();
                    Q.pop();
                    res.back().push_back(root->val);

                    if (root->left) Q.push(root->left);
                    if (root->right) Q.push(root->right);
                }
            }
        }

        return res;
    }
};