//
//  main.cpp
//  mergeSort
//
//  Created by 鍾安 on 2018/2/5.
//  Copyright © 2018年 鍾安. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void MergeSort(int start, int end, vector<int>& vec) {
    if ( start >= end) return;
    
    int len = end - start + 1;
    int start1 = start, end1 = start + (len>>1);
    int start2 = end1+1, end2 = end;
    
    MergeSort(start1, end1, vec);
    MergeSort(start2, end2, vec);
    
    for (int i = 0 ; i < vec.size(); i++) {
        printf("%d ", vec.at(i));
    }
    
    int k = 0;
    vector<int> vecTemp(len);
    
    while (start1 <= end1 && start2 <= end2) {
        vecTemp.at(k++) = vec.at(start1) >= vec.at(start2) ? vec.at(start1++) : vec.at(start2++);
    }
    while (start1 <= end1) {
        vecTemp.at(k++) = vec.at(start1++);
    }
    while (start2 <= end2) {
        vecTemp.at(k++) = vec.at(start2++);
    }
    for (int i = 0; i < vecTemp.size(); i++) {
        vec.at(start + i) = vecTemp.at(i);
    }
    
    printf("\n");
    
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(6);
    
    MergeSort(0, vec.size()-1, vec);
    
    for (int i = 0; i < vec.size()-1; i++) {
        printf("%d ", vec.at(i));
    }
    
    return 0;
}




