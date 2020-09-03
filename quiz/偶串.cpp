//链接：https://www.nowcoder.com/questionTerminal/6b210792272e4de68d8df8d232076765
//来源：牛客网
//
//如果一个字符串由两个相同字符串连接而成, 就称这个字符串是偶串。例如"xyzxyz"和"aaaaaa"是偶串, 但是"ababab"和"xyzxy"却不是。
//牛牛现在给你一个只包含小写字母的偶串s, 你可以从字符串s的末尾删除1和或者多个字符, 保证删除之后的字符串还是一个偶串, 牛牛想知道删除之后得到最长偶串长度是多少。
//输入包括一个字符串s, 字符串长度length(2 ≤ length ≤ 200), 保证s是一个偶串且由小写字母构成
//输出一个整数,表示删除之后能得到的最长偶串长度是多少。保证测试数据有非零解
#include<iostream>
#include<string>
using namespace std;
bool judge(string& s)
{
	int n = s.length();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[i + n / 2])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string s;
	while (cin >> s)
	{
		while (s.length() > 2) {
			s = s.substr(0, s.length() - 2);
			if (judge(s))
			{
				cout << s.length() << endl;
				break;
			}
		}
	}
}