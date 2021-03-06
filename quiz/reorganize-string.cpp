/*
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        if(S.size()<2)
        {
            return S;
        }
        vector<int> count(26,0);
        int maxCount=0;
        int length=S.size();
        for(int i=0;i<length;i++)
        {
            char c=S[i];
            count[c-'a']++;
            maxCount=max(maxCount,count[c-'a']);
        }
        if(maxCount>(length+1)/2)
        {
            return "";
        }
        auto cmp=[&](const char& letter1,const char& letter2){
            return count[letter1-'a']<count[letter2-'a'];
        };
        priority_queue<char,vector<char>,decltype(cmp)> queue{cmp};

        for(char c='a';c<='z';c++)
        {
            if(count[c-'a']>0)
            {
                queue.push(c);
            }
        }
        string sb="";
        while (queue.size()>1)
        {
            char letter1=queue.top();
            queue.pop();
            char letter2=queue.top();
            queue.pop();
            sb+=letter1;
            sb+=letter2;
            int index1=letter1-'a';
            int index2=letter2-'a';
            count[index1]--;
            count[index2]--;
            if(count[index1]>0)
            {
                queue.push(letter1);
            }
            if(count[index2]>0)
            {
                queue.push(letter2);
            }
        }
        if(queue.size()>0)
        {
            sb+=queue.top();
        }
        return sb;
    }
};