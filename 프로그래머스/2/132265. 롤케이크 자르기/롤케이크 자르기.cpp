#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> toppings) {
    int answer = 0;
    unordered_map<int, int> old;
    unordered_map<int, int> young;
    
    for(int topping : toppings)
    {
        old[topping]++;
    }
    
    for(int topping : toppings)
    {
        old[topping]--;
        young[topping]++;
        
        if(old[topping] == 0) old.erase(topping);
        
        if(old.size() == young.size())
        {
            answer++;
        }
    }
    
    return answer;
}