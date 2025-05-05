#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int brown, int yellow) {
    //노란색의 가로 세로 후보군들 구하기
    //노란색 가로+2 * 세로+2 - 노란색 개수 == 갈색 개수이면 
    //해당 노란색의 가로+2, 세로+2 가 답
    
    vector<int> answer;
    unordered_set<int> divisorList;
    int w = 0;
    int h = 0;
    
    for(int i = 1; i <= yellow; ++i)
    {
        if(divisorList.find(i) != divisorList.end())
            break;
        if(yellow % i == 0)
        {
            int divisor = yellow / i;
            divisorList.insert(divisor);
            
            w = divisor + 2;
            h = i + 2;
            
            if(w * h - yellow == brown) break;
        }
    }
    
    return {w, h};
}