/*****************************************************************
Name    :minCut
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191028 Initial Version
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
    int minCut(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(bool)*n*n);
        int cuts[n];

        for(int i=0; i<n; i++){
            //cout << "i=" <<i<<endl;
            cuts[i] = i; //separate each character
            for(int j=0; j<=i; j++){ //include the node j==i
                //cout << "j=" <<j<<endl;
                if(s[i] == s[j] && ( j+1>i-1 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    cuts[i] = j==0 ? 0 : min(cuts[i], cuts[j-1]+1);
                    //cout << "update cuts[" <<i<<"] = " << cuts[i] <<endl;
                }
            }//for j
        }//for i

        return cuts[n-1];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    string input("aab");

    Solution sol;
    int answer = sol.minCut(input);
    cout << "Answer is:" << answer <<endl;

    return 0;
}
/*==============================================================*/