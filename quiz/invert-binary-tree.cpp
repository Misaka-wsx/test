/*
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
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
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr==root)
        {
            return nullptr;
        }
        //TreeNode *temp=root->left;
        //root->left=root->right;
        //root->right=temp;
        std::swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};