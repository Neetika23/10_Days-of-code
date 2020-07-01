class Solution {
public:
    TreeNode* parent_x = NULL, *parent_y = NULL;
    int depth_x = -1, depth_y = -2;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        return depth_x == depth_y && parent_x != parent_y;
    }
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth) {
        if (root == NULL) return;
        if (x == root->val) {
            parent_x = parent;
            depth_x = depth;
        } else if (y == root->val) {
            parent_y = parent;
            depth_y = depth;
        } else {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
};
