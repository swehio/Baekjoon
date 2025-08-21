#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, int> cardCnt;
int maxCnt;
vector<long long> maxCntList;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        cardCnt[num]++;
        if(cardCnt[num] > maxCnt)
        {
            maxCnt = cardCnt[num];
        }
    }
    for(auto pair :  cardCnt)
    {
        if(pair.second == maxCnt)
        {
            maxCntList.push_back(pair.first);
        }
    }
    
    sort(maxCntList.begin(), maxCntList.end());
    
    cout << maxCntList[0];
}