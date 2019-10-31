/*****************************************************************
Name    :maxProfit
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191030 Initial Version
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit=0;

        //一次交易需要兩個價格，因此最多 n/2 次交易。
        //把握每次上升階段就是最大獲利
        if(k>=n/2){
            for(int i=1; i<n; i++){
                if(prices[i]>prices[i-1]){
                    profit += prices[i]-prices[i-1];
                }
            }//for

            return profit;
        }

        //dp[i][j] 代表最多 i 次交易，在價格 0~j 的最大利益。
        int dp[k+1][n];

        //initialize
        for(int j=0; j<n; j++){
            dp[0][j] = 0;
        }

        for(int i=0; i<=k; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=k; i++){
            int pocketBuy = -prices[0]; //在口袋中的錢，並且已買在某個價格
            for(int j=1; j<n; j++){
                //在第j個價格出現時，可以選擇 1)不作任何交易；2)賣出落袋為安。
                dp[i][j] = max(dp[i][j-1], pocketBuy+prices[j]);

                //在第j個價格出現時，可以選擇 1)不作任何交易；2)買在該價格。
                pocketBuy = max(pocketBuy, dp[i-1][j-1]-prices[j]);
            }//for j prices
        }//for i transaction

        return dp[k][n-1];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector<int> input{3,2,6,5,0,3};

    Solution sol;
    int answer = sol.maxProfit(2, input);
    cout << "Answer is :" << answer << endl;

    return 0;
}
/*==============================================================*/