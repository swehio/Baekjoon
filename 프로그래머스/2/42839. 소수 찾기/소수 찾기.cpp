#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
set<int> nums;

bool isPrime(int num)
{
    if(num == 1) return false;
    for(int i = 2; i*i<= num; ++i)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

void dfs(string numbers, string path, vector<bool>& used)
{
    if(!path.empty())
    {
        nums.insert(stoi(path));
    }
    
    for(int i = 0; i<numbers.size(); ++i)
    {
        if(!used[i])
        {
            used[i] = true;
            dfs(numbers, path + numbers[i], used);
            used[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<bool> used(numbers.size(), false);
    dfs(numbers, "", used);

    for(auto it = nums.begin(); it !=nums.end(); ++it)
    {
        if(*it == 0) continue;
        if(isPrime(*it))
        {
            answer++;
        }
    }
    
    return answer;
}