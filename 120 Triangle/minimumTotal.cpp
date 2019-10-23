/*****************************************************************
Name    :minimumTotal
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191022 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

/*==============================================================*/
//Data structure

/*==============================================================*/
//Solution

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();

        //initial the dp
        vector <int> dp(triangle.back());

        //bottom up
        for(int i=n-2; i>=0; i--){
            //for each node in the level
            for(int j=0; j<=i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    vector<vector<int> > triangle{
        {2},
        {3,4}, 
        {6,5,7},
        {4,1,8,3}}; 

    Solution sol;
    int answer = sol.minimumTotal(triangle);
    cout << "Answer :" << answer << endl;

    return 0;
}
/*==============================================================*/