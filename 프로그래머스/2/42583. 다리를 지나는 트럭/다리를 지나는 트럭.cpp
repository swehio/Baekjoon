#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    unordered_map<int, int> truckTime;
    queue<pair<int, int>> bridge;
    queue<pair<int, int>> wait;
    int totalWeight = 0;
    
    for(int i = 0; i< truck_weights.size(); i++)
    {
        wait.push(make_pair(i, truck_weights[i]));
    }
    
    bridge.push(wait.front());
    truckTime[wait.front().first]++;
    totalWeight += wait.front().second;
    wait.pop();
    answer++;

    while(!bridge.empty())
    {
        answer++;
        for(auto& [key, value] : truckTime)
        {
            value++;
        }
        if(truckTime[bridge.front().first] > bridge_length)
        {
            totalWeight-=bridge.front().second;
            truckTime.erase(bridge.front().first);
            bridge.pop();
        }
        if(!wait.empty() && weight >= totalWeight+wait.front().second)
        {
            bridge.push(wait.front());
            truckTime[wait.front().first] = 1;
            totalWeight += wait.front().second;
            wait.pop();
        }
    }
    
    return answer;
}