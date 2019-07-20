/*************************************************************************
    > File Name: 3sum.cpp
    > Author: icesummer
    > Mail: wangsixiamksh@163.com 
    > Created Time: 2019-07-20
 ************************************************************************/
/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
	*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &num)
	{
		vector<vector<int>> result;
		int len = num.size();
		if (len < 3)
			return result;
		sort(num.begin(), num.end());
		vector<int> tmp(3);
		for (int i = 0; i < len; i++)
		{
			int left = i + 1;
			int right = len - 1;
			while (left < right)
			{
				while (left < right && num[i] + num[left] + num[right] > 0)
				{
					right--;
				}
				if (left < right && num[i] + num[left] + num[right] == 0)
				{
					tmp[0] = num[i];
					tmp[1] = num[left];
					tmp[2] = num[right];
					result.push_back(tmp);
					while (left < right && num[left] == tmp[1])
					{
						left++;
					}
				}
				else
				{
					left++;
				}
			}
		}
		return result;
	}
};
int main()
{
	vector<int> s{-1,0,1,2,-1,4};
	Solution sol;
	auto val=sol.threeSum(s);
	return 0;
}

