#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> orangeNumByType;
    
    
    for(int orange : tangerine)
    {
        ++orangeNumByType[orange];
    }
    
    vector<pair<int, int>> sortVector(orangeNumByType.begin(), orangeNumByType.end());
    
    sort(sortVector.begin(), sortVector.end(), [](const auto& a, const auto& b){ return a.second>b.second;});
    
    int TotalNum = 0;
    for(int i = 0; i<sortVector.size(); ++i)
    {
        TotalNum += sortVector[i].second;
        if(TotalNum >= k) return i+1;
    }
}