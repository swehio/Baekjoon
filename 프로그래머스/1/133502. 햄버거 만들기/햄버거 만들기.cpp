#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> ingredients) {
    int answer = 0;
    vector<int> humberger;
    
    for(int i = 0; i<ingredients.size();++i)
    {
        humberger.push_back(ingredients[i]);
        if(ingredients.size() > 3 && ingredients[i] == 1)
        {
            if(humberger[humberger.size()-2] == 3 && humberger[humberger.size()-3] == 2 && humberger[humberger.size()-4] == 1)
            {
                ++answer;
                for(int j = 0; j<4; ++j)
                {
                    humberger.pop_back();
                }
            }

        }
    }
    return answer;
}