/*****************************************************************
Name    :maxProduct
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191029 Initial Version
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(0==n){
            return 0;
        }

        //dp initial
        int minP = nums[0];
        int maxP = nums[0];
        int result = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                swap(minP, maxP);
            }

            maxP = max(nums[i], nums[i]*maxP);
            minP = min(nums[i], nums[i]*minP);

            result = max(result, maxP);
        }//for

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector<int> input{2,3,-2,4};

    Solution sol;
    int answer = sol.maxProduct(input);
    cout << "Answer is :" << answer << endl;
    return 0;
}
/*==============================================================*/