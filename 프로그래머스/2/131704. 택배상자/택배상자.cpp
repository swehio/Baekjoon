#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> mainCB;
    stack<int> subCB;
    
    for(int i = 1; i<=order.size(); ++i)
    {
        mainCB.push(i);
    }
    
    for(int i = 0; i<order.size();)
    {
        if(!subCB.empty() && order[i] == subCB.top())
        {
            subCB.pop();
            answer++;
            ++i;
            continue;
        }
        if(!mainCB.empty() && order[i] == mainCB.front())
        {
            mainCB.pop();
            answer++;
            ++i;
            continue;
        }
        
        if(mainCB.empty())
        {
            break;
        }
        
        while(order[i] != mainCB.front())
        {
            subCB.push(mainCB.front());
            mainCB.pop();
            if(mainCB.empty())
            {
                break;
            }
        }
    }
    
    return answer;
}