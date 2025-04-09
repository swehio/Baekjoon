#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    unordered_map<string, int> rank;
    for(int i = 0; i<players.size(); i++)
    {
        rank[players[i]] = i;
    }
    
    for(string calling : callings)
    {
        int index = rank[calling];
        string temp = "";
        temp = players[index-1];
        players[index-1] = players[index];
        players[index] = temp;
        rank[players[index]]++;
        rank[players[index-1]]--;
    }
    
    return players;
}