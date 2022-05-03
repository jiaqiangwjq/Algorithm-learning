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
        vector<vector<int>> ans;

        if (!root) {
            return ans;
        }
        else {
            queue<TreeNode*> Q;
            Q.push(root);

            while (!Q.empty()) {
                ans.push_back(vector<int>());
                int length = Q.size();

                for (int i = 0; i < length; ++i) {
                    TreeNode* tmp = Q.front();
                    ans.back().push_back(tmp -> val);
                    Q.pop();

                    if (tmp -> left) {
                        Q.push(tmp -> left);
                    }
                    if (tmp -> right) {
                        Q.push(tmp -> right);
                    }
                }
            }
        }

        for (int i = 1; i < ans.size(); i += 2) {
            for (int l = 0, r = ans[i].size() - 1; l < r; ++l, --r) {
                swap(ans[i][l], ans[i][r]);
            }
        }

        return ans;
    }
};