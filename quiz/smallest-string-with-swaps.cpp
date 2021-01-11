/*
给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。

你可以 任意多次交换 在 pairs 中任意一对索引处的字符。

返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

 

示例 1:

输入：s = "dcab", pairs = [[0,3],[1,2]]
输出："bacd"
解释： 
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"
示例 2：

输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
输出："abcd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"
示例 3：

输入：s = "cba", pairs = [[0,1],[1,2]]
输出："abc"
解释：
交换 s[0] 和 s[1], s = "bca"
交换 s[1] 和 s[2], s = "bac"
交换 s[0] 和 s[1], s = "abc"
 

提示：

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class DisJoinSetUnion
{
private:
    vector<int> f, rank;
    int n;
public:
    DisJoinSetUnion(int _n)
    {
         n=_n;
         rank.resize(n,1);
         f.resize(n);
         for(int i=0;i<n;i++)
         {
             f[i]=i;
         }
    }
    int find(int x)
    {
        return f[x]==x?x:f[x]=find(f[x]);
    }
    void unionSet(int x,int y)
    {
        int fx=find(x),fy=find(y);
        if(fx==fy)
        {
            return;
        }
        if(rank[fx]<rank[fy])
        {
            swap(fx,fy);
        }
        rank[fx]+=rank[fy];
        f[fy]=fx;
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisJoinSetUnion dsu(s.length());
        for(auto&it :pairs)
        {
            dsu.unionSet(it[0],it[1]);
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[dsu.find(i)].emplace_back(s[i]);
        }
        for (auto& vec : mp) {
            sort(vec.second.begin(), vec.second.end(), greater<int>());
        }
        for(int i=0;i<s.length();i++)
        {
            int x=dsu.find(i);
            s[i]=mp[x].back();
            mp[x].pop_back();
        }
        return s;
    }
};