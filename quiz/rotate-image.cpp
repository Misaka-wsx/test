#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       
        int n=matrix[0].size();
        auto result=matrix;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                result[n-1-i][n-1-j]=matrix[j][i];
            }
        }
    }
};
int main()
{
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    Solution a;
    a.rotate(matrix);
    return 0;
}