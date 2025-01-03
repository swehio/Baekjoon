#include <string>
#include <vector>

using namespace std;

vector<int> findMaxMin(int n, int m){
    vector<int> temp;
    int Max = 1;
    int Min = 1;
    int divisor = 0;
    int mNum = m;
    int nNum = n;
    int low;
    int high;
    
    if(n<m)
    {
        low = n;
        high =m;
    }
    else
    {
        low =m;
        high = n;
    }

    while(divisor != 1){
        for(int i = 1; i<=low; ++i){
            if(nNum % i == 0 && mNum % i == 0){
                divisor = i;
                Min *= divisor;
                nNum /= i;
                mNum /= i;
            }
        }  
    }
    Max = nNum*mNum*Min;
    
    temp.push_back(Min);
    temp.push_back(Max);
    
    return temp;
}

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(1);
    answer = findMaxMin(n, m);
    return answer;
}