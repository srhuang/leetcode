/*****************************************************************
Name    :wordBreak
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        if(!checkWordBreak(s, wordDict)){
            return result;
        }

        //backtracking
        backtracking(s, wordDict, 0, "", result);
        return result;
    }

    void backtracking(string s, vector<string>& wordDict, 
        int start, string sol, vector<string> &result)
    {
        int n = s.size();

        //terminal case
        if(start == n){
            result.push_back(sol);
            return;
        }

        //recursion
        for(int i=start; i<n; i++){
            //find the next word begin start
            string word = s.substr(start, i-start+1);

            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                backtracking(s, wordDict, i+1, 
                    sol+(sol.size()==0?"":" ")+word, result);
            }
        }

    }

    bool checkWordBreak(string s, vector<string>& wordDict) {
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
    string input("catsanddog");
    vector<string> dictionary{"cats", "dog", "sand", "and", "cat"};

    Solution sol;
    vector<string> answer = sol.wordBreak(input, dictionary);
    vector<string>::iterator it;
    cout << "Answer is " << endl;
    for(it=answer.begin(); it!=answer.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
/*==============================================================*/