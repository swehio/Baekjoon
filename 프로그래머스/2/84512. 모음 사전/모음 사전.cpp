#include <string>
#include <vector>
#include <iostream>

using namespace std;
int num = 0;
int cnt = 0;
void dfs(string dictWord, vector<string> AlphabetList, string word)
{
    cnt++;
    
    if(dictWord == word)
    {
        num = cnt;
    }
    
    if(dictWord.size() == 5) return;

    for(int i = 0; i < AlphabetList.size(); ++i)
    {
        dfs(dictWord+AlphabetList[i], AlphabetList, word);
    }
}

int solution(string word) {
    int answer = 0;
    
    vector<string> AlphabetList = {"A", "E", "I", "O", "U"};
    string dictWord = "";
    for(int i = 0; i < AlphabetList.size(); ++i)
    {
        dfs(AlphabetList[i], AlphabetList, word);
    }

    
    return num;
}