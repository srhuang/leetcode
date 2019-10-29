/*****************************************************************
Name    :wordBreak
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++){
            //check each last word
            for(int j=i-1; j>=0; j--){
                if(dp[j]){ //determine 0~j-1
                    //extract the last word j~i
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
                    {
                        dp[i] = true;
                        break; //next i
                    }
                }
            }// for j
        }//for i

        return dp[n];
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    string input("catsandog");
    vector<string> dictionary{"cats", "dog", "sand", "and", "cat"};

    Solution sol;
    int answer = sol.wordBreak(input, dictionary);
    cout << "Answer is :" << answer << endl;

    return 0;
}
/*==============================================================*/