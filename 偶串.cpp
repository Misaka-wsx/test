//���ӣ�https://www.nowcoder.com/questionTerminal/6b210792272e4de68d8df8d232076765
//��Դ��ţ����
//
//���һ���ַ�����������ͬ�ַ������Ӷ���, �ͳ�����ַ�����ż��������"xyzxyz"��"aaaaaa"��ż��, ����"ababab"��"xyzxy"ȴ���ǡ�
//ţţ���ڸ���һ��ֻ����Сд��ĸ��ż��s, ����Դ��ַ���s��ĩβɾ��1�ͻ��߶���ַ�, ��֤ɾ��֮����ַ�������һ��ż��, ţţ��֪��ɾ��֮��õ��ż�������Ƕ��١�
//�������һ���ַ���s, �ַ�������length(2 �� length �� 200), ��֤s��һ��ż������Сд��ĸ����
//���һ������,��ʾɾ��֮���ܵõ����ż�������Ƕ��١���֤���������з����
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