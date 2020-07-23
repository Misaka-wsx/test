



#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <hash_map>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
    int len = s.length();
    if(len==0) return 0;
    int maxLen = 0,left = 0;
    map<char,int> charMap;
    for(int i=0;i<len;i++)
    {
        if(charMap.find(s[i]) != charMap.end())
            left = max(left,charMap[s[i]]+1);
        maxLen = max(maxLen,i-left+1);
        charMap[s[i]] = i;
    }
    return maxLen; 
    }
};