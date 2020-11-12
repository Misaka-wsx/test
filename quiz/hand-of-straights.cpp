/*
爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

 

注意：此题目与 1296 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
输出：true
解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], W = 4
输出：false
解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<map>
using std::map;
using std::vector;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n=hand.size();
        if(n%W)
            return false;
        map<int,int> count;
        for(auto i:hand)
        {
            count[i]++;
        }
        while (count.size())
        {
            int begin=count.begin()->first;
            for(int i=begin;i<begin+W;i++)
            {
                if(!count.count(i))
                {
                    return false;
                }
                if(!--count[i])
                {
                    count.erase(i);
                }
            }
        }
        return true;
    }
};