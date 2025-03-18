#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    for(int move : moves)
    {
        for(vector<int>& line : board)
        {
            if(line[move-1] != 0)
            {
                if(!basket.empty()&&basket.top() == line[move-1])
                {
                    basket.pop();
                    answer+=2;
                }
                else
                {
                    
                    basket.push(line[move-1]);
                }
                line[move-1] = 0;
                break;
            }
            
        }
    }

    return answer;
}