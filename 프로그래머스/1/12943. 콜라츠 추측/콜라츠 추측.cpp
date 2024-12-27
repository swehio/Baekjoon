#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long editNum = num; 
    int count = 0;
    while (!(editNum == 1)){
        if(editNum % 2 == 0)
        {
            editNum = editNum / 2;
        }
        else{
            editNum = editNum * 3 + 1;
        }
        count++;
        cout << editNum<<endl;
        if(count >= 500) return -1;
    }
    return count;
}