#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    
    for(int i = 0; i<nums.size()-2; ++i){
        for(int j=i+1; j<nums.size()-1;++j){
            for(int k=j+1; k<nums.size();++k){
                sum = nums[i] + nums[j] + nums[k];
                cout << sum << endl;
                for(int p = 2; p <= sum; ++p){
                    if(p == sum)
                        ++answer;
                    else
                    {
                        if(sum % p == 0)
                            break; 
                    }
                }
            }
        }
    }
    


    return answer;
}