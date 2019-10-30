/*****************************************************************
Name    :calculateMinimumHP
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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        //dp[i][j] means the min hp before enter the position(i,j).
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        //boundary case
        dp[m-1][n] = 1; //right side of the princess room
        dp[m][n-1] = 1; //bottom side of the princess room

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector<vector<int>> input{
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };

    Solution sol;
    int answer = sol.calculateMinimumHP(input);
    cout << "Answer is :" << answer <<endl;

    return 0;
}
/*==============================================================*/