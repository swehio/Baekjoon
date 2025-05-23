#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> clothesByType;
    
    for(vector<string> clothe : clothes)
    {
        clothesByType[clothe[1]].push_back(clothe[0]);
    }
    
    for(auto& pair : clothesByType)
    {
        answer = answer * (clothesByType[pair.first].size()+1);
    }
    
    return answer-1;
}