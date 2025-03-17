#include <string>
#include <vector>
#include <stack>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> temp;
    int prePrice;
    
    for(int i = 0; i<prices.size(); i++)
    {
        while(!temp.empty() && prices[temp.top()] > prices[i])
        {
            answer[temp.top()] = i - temp.top();  
            temp.pop();
        }
        
        temp.push(i);
    }
    
    while(!temp.empty())
    {
        answer[temp.top()] = prices.size() - temp.top() - 1;
        temp.pop();
    }
    
    return answer;
}