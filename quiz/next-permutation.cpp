#include<vector>
#include<algorithm>
using namespace std;
 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while (i>=0&&nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            int j=nums.size()-1;
            while (j>=0&&nums[i]>=nums[j])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
int main()
{
    Solution a;
    vector<int> nums={1,5,8,4,7,6,5,3,1};
    a.nextPermutation(nums);
    return 0;
}