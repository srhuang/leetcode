/*****************************************************************
Name    :maxProfit
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191023 Initial Version
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;

        int left[n];
        int right[n];

        //Step 1
        //from left to right to find each profit
        int min_price = prices[0];
        left[0]=0;
        for(int i=1; i<n; i++){
            if(prices[i] > min_price){
                left[i] = prices[i] - min_price;
            }else{
                left[i] = 0;
                min_price = prices[i];
            }
        }

        //from right to left find each profit
        int max_price = prices[n-1];
        right[n-1]=0;
        for(int i=n-2; i>=0; i--){
            if(prices[i] < max_price){
                right[i] = max_price - prices[i];
            }else{
                right[i] = 0;
                max_price = prices[i];
            }
        }

        //Step 2
        //forward the max profit for both direction
        int cumulative = left[0];
        for(int i=1; i<n; i++){
            cumulative = max(cumulative, left[i]);
            left[i] = cumulative;
        }

        cumulative = right[n-1];
        for(int i=n-2; i>=0; i--){
            cumulative = max(cumulative, right[i]);
            right[i] = cumulative;
        }

        //Step 3
        int result=0;
        for(int i=0; i<n-1; i++){
            result = max(result, left[i]+right[i+1]);
        }

        //only one transaction
        if(left[n-1] > result) 
            result = left[n-1];

        if(right[0] > result)
            result = right[0];

        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector <int> input{3,3,5,0,0,3,1,4};

    Solution sol;
    int answer = sol.maxProfit(input);
    cout << "Answer :" << answer << endl;
    return 0;
}
/*==============================================================*/