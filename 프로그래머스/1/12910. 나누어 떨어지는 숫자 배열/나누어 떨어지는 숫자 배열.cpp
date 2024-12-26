#include <string>
#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& arr, int size){
    for(int i = 0; i<size; i++)
    {
        for(int j=i+1;j<size;j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    
}

void swap(int& num1, int& num2){
    int temp = 0;
        
    temp = num2;
        
    num2 = num1;
        
    num1 = temp;
        
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i] % divisor == 0)
        {
            answer.push_back(arr[i]);
        }
    }
    
    
    if(answer.empty())
        answer.push_back(-1);
    
    sort(answer, answer.size());
    
    for(auto num : answer)
    {
        cout << num;
    }
    
    return answer;
}