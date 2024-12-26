#include <string>
#include <iostream>
#include <cmath>

#include <vector>

using namespace std;

void swap(long long& num1, long long& num2){
    long long temp;
    temp = num2;
    num2 = num1;
    num1 = temp;
}

void sort(vector<long long>& arr, int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size ; j++){
            if(arr[i]<arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
    
}

void splitToArr(long long n, vector<long long>& arr){
    while(n>0)
    {
        arr.push_back(n%10);
        n /= 10;
    }
    

}
void mergeToNum(vector<long long>& arr, long long& num){
    sort(arr, arr.size());
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    for(int i = 0; i < arr.size() ; i++){
        num+=arr[i]*pow(10, (arr.size() -1 - i));

    }

}

long long solution(long long n) {
    long long answer = 0;
    vector<long long> arr;
    
    splitToArr(n, arr);
    
    mergeToNum(arr, answer);
    
    return answer;
}