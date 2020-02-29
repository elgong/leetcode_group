#include<bits/stdc++.h>
using namespace std;
//二分答案范围的二分
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();long long l=matrix[0][0];
        long long r=matrix[n-1][n-1]+1;
        int less_cnt=0,no_larger_cnt=0;
        long long mid=l;
        while(l<r){
            //这里改成（l+r)/2不行
            mid=l+(r-l)/2;
            less_cnt=0;no_larger_cnt=0;
            for(int i=0;i<n;i++){
                auto &v=matrix[i];
                less_cnt+=lower_bound(v.begin(),v.end(),mid)-v.begin();
                no_larger_cnt+=upper_bound(v.begin(),v.end(),mid)-v.begin();
            }
            if(less_cnt<k&&no_larger_cnt>=k) return mid;
            if(less_cnt<k) l=mid+1;
            else r=mid;
        }
        return mid;
    }
};
/*
int main(){
    Solution m;
    cout<<m.kthSmallest(vector<vector<int>>(vector<int>(-1)),1);
}
*/