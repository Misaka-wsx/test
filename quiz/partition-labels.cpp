/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> index;
        vector<int>result;
        for(int i=0;i<S.size();i++)
        {
            index[S[i]]=i;
        }
        int start=0;
        int end=0;
        for (size_t i = 0; i < S.size(); i++)
        {
            end=max(end,index[S[i]]);
            if (i==end)
            {
                result.push_back(end-start+1);
                  start=end+1;
            }
        }
        return result;
    }

};
int main()
{
    string S = "ababcbacadefegdehijhklij";
    Solution a;
    auto val=a.partitionLabels(S);
    return 0;
}