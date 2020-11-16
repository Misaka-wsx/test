/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>&T1,vector<int>&T2){
            return T1[0]==T2[0]?T1[1]<T2[1]:T1[0]>T2[0];
        });
        vector<vector<int>>result;
        for(const vector<int> &p:people)
        {
            result.insert(result.begin()+p[1],p);
        }
        return result;
    }
};
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> people={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> people1={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution a;
    Solution1 a1;
    auto result=a.reconstructQueue(people);
    auto re=a1.reconstructQueue(people1);
    return 0;
}