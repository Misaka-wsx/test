/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxnum1=-1001;
        int maxnum2=-1001;
        int maxnum3=-1001;
        int min1=1001;
        int min2=1001;
        for(auto num:nums)
        {
            if(num<min1)
            {
                min2=min1;
                min1=num;
            }else if(num<min2)
            {
                min2=num;
            }
            if(num>maxnum1)
            {
                maxnum3=maxnum2;
                maxnum2=maxnum1;
                maxnum1=num;
            }
            else if(num>maxnum2)
            {
                maxnum3=maxnum2;
                maxnum2=num;
            }
            else if(num>maxnum3)
            {
                maxnum3=num;
            }
        }
        return max(min1*min2*maxnum1,maxnum1*maxnum2*maxnum3);
    }
};