#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> toRThree(int ten){
    vector<int> three;
    int mok = ten;
    
    while(!(mok == 0 || mok == 1 || mok ==2)){
        three.push_back(mok%3);
        mok /= 3;
    }
    three.push_back(mok);
    
    return three;
}

int toTen(vector<int> rThree){
    int sum = 0;
    for(int i = 0; i < rThree.size(); ++i){
        sum += rThree[rThree.size()-i-1]*pow(3, i);
    }
    return sum;
}

int solution(int n) {
    return toTen(toRThree(n));
}