#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


searchSurroundingLetters(vector<vector<char> > board, int i, int j, string leftHalf, string rightHalf){
    if(leftHalf) char leftWord = leftHalf.back()
    else char leftWord = '0'
    if(rightHalf) char rightWord = rightHalf.front();
    else char rightWord = '0';
    
    if()
}
bool word_search(vector<vector<char> > board, string word){
    unordered_map<char, vector<int> > words;
    for(int i=0; i<word.length(); i++){
        words[word[i]].push_back(i);
    }
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(words.find(word[i][j]) != words.end()) {
                //do something
            }
        }
    }
}

int main(){
    vector<vector<char> > b = {{'A', 'B', 'C'}}

}