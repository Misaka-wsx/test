
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> stone{stones.begin(),stones.end()};
        while (stone.size()>1)
        {
            int a=stone.top();
            stone.pop();
            int b=stone.top();
            stone.pop();
            if(a>b)
            {
                stone.push(a-b);
            }
        }
        return stone.empty()?0:stone.top();
    }
};