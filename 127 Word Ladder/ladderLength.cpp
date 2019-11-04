/*****************************************************************
Name    :ladderLength
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191101 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

/*==============================================================*/
//Data structure

/*==============================================================*/
//Solution

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q; //for BFS

        //to speed up, using set to store the words in the same ladder
        unordered_set<string> ladder_words;

        //initialization
        q.push(beginWord);
        int ladder = 1;

        while(!q.empty()){
            //先記錄這一層(ladder)的個數
            int n = q.size();

            //erase the last words in the dictionary
            for(string w:ladder_words){
                dict.erase(w);
            }
            ladder_words.clear();

            //handle this ladder
            for(int i=0; i<n; i++){
                //get from the queue
                string word = q.front();
                q.pop();

                //check if equal to end word
                if(word == endWord){
                    return ladder;
                }

                //find the next level words in dictionary
                for(int j=0; j<word.size(); j++){
                    //記錄該位置原始的字元
                    char c = word[j];

                    //嘗試更換成26個字元
                    for(int k=0; k<26; k++){
                        word[j] = 'a'+k;
                        if(dict.find(word) != dict.end())
                        {//find the word in dictionary
                            ladder_words.insert(word);
                            q.push(word);
                        }
                    }

                    word[j] = c; //回復該字元
                }//for all possible position

            }//for

            ladder++;
        }
        //means not found
        return 0;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    string beginWord("hit");
    string endWord("cog");
    vector<string> dict{"hot","dot","dog","lot","log","cog"};

    Solution sol;
    int answer = sol.ladderLength(beginWord, endWord, dict);
    cout << "Answer is :" << answer <<endl;

    return 0;
}
/*==============================================================*/