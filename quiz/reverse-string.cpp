/**
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 *
 * 输入："Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 */
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string result;
        std::string temp;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]== ' ')
            {
                reverse(temp.begin(),temp.end());
                result += temp;
                result = result + " ";
                temp = "";
            }
            else
            {
                temp = temp + s[i];
                if (i==s.size()-1)
                {
                    reverse(temp.begin(), temp.end());
                    result += temp;
                }
            }

        }
        return result;
    }
};

int main()
{
    std::string s="Let's take LeetCode contest";
    Solution a;
    std::cout << a.reverseWords(s);
    return 0;
}