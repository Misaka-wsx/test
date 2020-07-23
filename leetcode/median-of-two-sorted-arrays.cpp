/*************************************************************************
    > File Name: 3sum.cpp
    > Author: icesummer
    > Mail: wangsixiamksh@163.com 
    > Created Time: 2020-07-20
 ************************************************************************/
/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
         if(m+n==0){
            return 0;
        }
        vector<int> temp;
        int im=0;
        int in=0;
        while(im<m&&in<n){
            if(A[im]<B[in]){
                temp.push_back(A[im]);
                im++;
            }
            else{
                temp.push_back(B[in]);
                in++;
            }
        }
        while(im<m){
            temp.push_back(A[im]);
            im++;
        }
        while(in<n){
            temp.push_back(B[in]);
            in++;
        }
        if((m+n)%2==1){
            return temp[(m+n)/2];
        }
        else{
            return (double(temp[(m+n)/2]+temp[(m+n)/2-1]))/2;
        }
    }
};