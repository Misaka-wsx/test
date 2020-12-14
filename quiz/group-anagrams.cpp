/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using std::string;
using std::vector;
using std::map;                                                                                                             
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> result;
        for(auto vec:strs)
        {
            string str=vec;
            std::sort(vec.begin(),vec.end());
            result[vec].push_back(str);
        }
        vector<vector<string>> val;
         for(auto vec=result.begin();vec!=result.end();vec++)
        {
            val.push_back(vec->second);
        }
        return val;
    }
};