#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int y = x;
    while(y>0){
        sum += y%10;
        y = y/10;
    }

    return x%sum == 0 ? true:false;
}