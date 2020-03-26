//
//  main.cpp
//  bigNumberMultiplication
//
//  Created by 鍾安 on 2017/10/21.
//  Copyright © 2017年 鍾安. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    
    vector<int> input[2];
    vector<int> output;
    
    for (int i = 0; i < 2; i++) {
        while (true) {
            char ch;
            
            scanf("%c", &ch);
            if (ch == ' ' || ch == '\n') {
                break;
            }
            else {
                ch -= 48;
                input[i].push_back(ch);
            }
        }
    }
    
    for (int n = 0; n < 2; n++) {
        for (int i = 0; i < input[n].size() / 2; i++) {
            swap( input[n].at(i), input[n].at(input[n].size() -i-1) );
        }
    }
    
    //process
    for (int i = 0; i < input[0].size(); i++) {
        for (int j = 0; j < input[1].size(); j++) {
            int tempVal = input[0].at(i) * input[1].at(j);
            
            while (output.size() <= i+j) {
                output.push_back(0);
            }
            output.at(i+j) += tempVal;
        }
    }
    
    //standard
    for (int i = 0; i < output.size(); i++) {
        int tempVal = output.at(i);
        
        if (tempVal >= 10) {
            int val0, val1;
            
            val0 = tempVal%10;
            val1 = tempVal/10;
            
            output.at(i) = val0;
            if ( i+1 == output.size()) {
                output.push_back(val1);
            }
            else {
                output.at(i+1) += val1;
            }
        }
    }
    
    //output
    for (long i = output.size() -1; i >= 0; i--) {
        printf("%d", output.at(i));
    }
    
    
    return 0;
}





