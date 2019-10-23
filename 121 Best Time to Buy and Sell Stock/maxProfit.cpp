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
        int max = 0;
        int n = prices.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int profit = prices[j]-prices[i];
                if(profit > max)
                    max = profit;
            }
        }

        return max;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector <int> prices{7,1,5,3,6,4};

    Solution sol;
    int answer = sol.maxProfit(prices);
    cout << "Answer is :" << answer << endl;

    return 0;
}
/*==============================================================*/