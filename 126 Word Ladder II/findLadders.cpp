/*****************************************************************
Name    :findLadders
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191104 Initial Version
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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        vector<string> path;
        queue<vector<string>> q; //for BFS

        //initialization
        path.push_back(beginWord);
        q.push(path);
        int ladder = 1;
        int minLadder = INT_MAX;

        //to speed up, using set to store the words in the same ladder
        unordered_set<string> ladder_words;

        vector<string> next_path;

        while(!q.empty()){

            //already find min Ladder path
            if(ladder > minLadder)
                break;

            //erase the last words in the dictionary
            for(string w:ladder_words){
                dict.erase(w);
            }
            ladder_words.clear();

            //先記錄這一層(ladder)的個數
            int n = q.size();

            //handle this ladder
            for(int i=0; i<n; i++){
                //get vector from the queue
                path = q.front();
                q.pop();
                string word = path.back();

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
                            next_path = path;
                            next_path.push_back(word);
                            //check if equal to end word
                            if(word == endWord){
                                result.push_back(next_path);
                                minLadder = ladder;
                            }else{
                                q.push(next_path); //
                            }
                        }
                    }

                    word[j] = c; //回復該字元
                }//for all possible position

            }//for

            ladder++;
        }
        //means not found
        
        return result;
    }
};

/*==============================================================*/
int main(int argc, char const *argv[]){
    string beginWord("hit");
    string endWord("cog");
    vector<string> dict{"hot","dot","dog","lot","log","cog"};

    Solution sol;
    vector<vector<string>> answer = sol.findLadders(beginWord, endWord, dict);
    vector<vector<string>>::iterator it_second;
    vector<string>::iterator it_first;

    cout << "Answer is :" << endl;
    for(it_second=answer.begin(); it_second != answer.end(); it_second++)
    {
        for(it_first=(*it_second).begin(); it_first!=(*it_second).end(); it_first++)
        {
            cout << *it_first << " ";
        }
        cout << endl;
    }

    return 0;
}
/*==============================================================*/