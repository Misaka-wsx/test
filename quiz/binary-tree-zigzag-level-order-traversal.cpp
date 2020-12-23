/*
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
通过次数100,336提交次数177,161

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ret;
        if(!root)
        {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool is_left_to_right=true;
        while (!q.empty())
        {
            deque<int>levelList;
            int qsize=q.size();
            for(int i=1;i<=qsize;i++)
            {
                auto node=q.front();q.pop();
                if(is_left_to_right)
                {
                    levelList.push_back(node->val);
                }
                else
                {
                    levelList.push_front(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.emplace_back(vector<int>{levelList.begin(),levelList.end()});
            is_left_to_right=!is_left_to_right;
        }
        return ret;
    }
};