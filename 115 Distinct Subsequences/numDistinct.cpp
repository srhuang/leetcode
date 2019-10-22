/*****************************************************************
Name    :numDistinct
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191022 Initial Version
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
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector< vector<long> > dp(m+1, vector<long>(n+1, 0));

        //Boundary case
        for(int j=0; j<=n; j++)
            dp[0][j] = 1;

        //General case
        for(int j=1; j<=n; j++){
            for(int i=1; i<=m; i++){
                dp[i][j] = dp[i][j-1] + (t[i-1]==s[j-1] ? dp[i-1][j-1] : 0);
            }
        }

        return dp[m][n];

    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    string s = "rabbbit";
    string t = "rabbit";

    Solution sol;
    int answer = sol.numDistinct(s, t);
    cout << "Answer is : " << answer << endl;

    return 0;
}
/*==============================================================*/