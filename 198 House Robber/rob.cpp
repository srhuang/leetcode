/*****************************************************************
Name    :rob
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191031 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

/*==============================================================*/
//Data structure

/*==============================================================*/
//Solution

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(0==n)
            return 0;

        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        }

        return dp[n];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector<int> input{2,7,9,3,1};

    Solution sol;
    int answer = sol.rob(input);
    cout << "Answer is :" << answer <<endl;

    return 0;
}
/*==============================================================*/