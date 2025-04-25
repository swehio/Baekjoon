#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> profitList;
unordered_map<string, string> enrollIndex;

void distribute(int Profit, string& gainer)
{
    int recommendedProfit = Profit * 0.1;
    int myProfit = Profit - recommendedProfit;
    profitList[gainer] += (recommendedProfit < 1) ? Profit : myProfit;

    if(enrollIndex[gainer] != "-" && recommendedProfit >= 1)
    {        
        distribute(recommendedProfit, enrollIndex[gainer]);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); ++i)
    {
        profitList[enroll[i]] = 0;
        enrollIndex[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i<seller.size(); ++i)
    {
        int totalProfit = amount[i] * 100;
        distribute(totalProfit, seller[i]);
    }
    
    for(string name : enroll)
    {
        answer.push_back(profitList[name]);
    }
    
    return answer;
}