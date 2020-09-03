/*
给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string& S) {
        vector<int> res;
        int i=0;
        for(int j=i+1;j<S.size();++j){
            for(int k=j+1;k<S.size();++k){
                res.clear();
                if(backtrack(S,i,j,k,res)){
                    if(res.size()>2){
                        return res;
                    }
                }
            }
        }
        return {};
    }

    bool backtrack(string& S,int i,int j,int k,vector<int>& res){
        if((S[i]=='0'&&j-i>1)||(S[j]=='0'&&k-j>1))return false;//s[i]、s[j]为'0'，相差一位的话，满足题意
        long long a=0,b=0;
        for(int c=i;c<j;++c){
            a=a*10+S[c]-'0';
            if(a>INT_MAX)return false;
        }
        for(int c=j;c<k;++c){
            b=b*10+S[c]-'0';
            if(b>INT_MAX)return false;
        }
        if(k==S.size()){
            res.push_back(a);
            res.push_back(b);
            return true;
        }
        string sum=to_string(a+b);
        for(int c=0;c<sum.size();++c){
            if(S[c+k]!=sum[c])return false;
        }
        res.push_back(a);
        return backtrack(S,j,k,k+sum.size(),res);
    }
};