#include <string>
#include <vector>
#include <iostream>



using namespace std;

int purseSize(const int width, const int height){
    return width * height;
}

void swap(int &first, int &second){
    int temp;
    temp = first;
    first = second;
    second = temp;
}

int solution(vector<vector<int>> sizes) {

    for(auto &size : sizes){
        if(size[0]<size[1]){
            swap(size[0], size[1]);
        }
    }
    
    int maxW = sizes[0][0];
    int maxH = sizes[0][1];
    
    for(int i = 1; i < sizes.size(); ++i){
        cout << sizes[i][0] << " " << sizes[i][1]<<endl;
        if(sizes[i][0] > maxW){
            maxW = sizes[i][0];
        }
        if(sizes[i][1] > maxH){
            maxH = sizes[i][1];
        }
    }

    return purseSize(maxW, maxH);
}