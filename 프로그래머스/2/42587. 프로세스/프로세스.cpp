#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    unordered_map<int, int> pMap;
    queue<int> pQueue;
    
    vector<int> pSort(priorities);
    sort(pSort.begin(), pSort.end(), [](int a, int b){ return a > b;});
    int position = 0;
    
    for(int i = 0; i<priorities.size(); ++i)
    {
        pMap[i] = priorities[i];
        pQueue.push(i);
    }
    
    while(1)
    {
        if(pMap[pQueue.front()] == pSort[position])
        {
            answer++;
            if(pQueue.front() == location)
                break;
            pQueue.pop();
            ++position;
        }
        else
        {
            pQueue.push(pQueue.front());
            pQueue.pop();
        }
    }

    
    return answer;
}