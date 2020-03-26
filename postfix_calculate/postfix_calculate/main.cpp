//
//  main.cpp
//  postfix_calculate
//
//  Created by 鍾安 on 2017/11/2.
//  Copyright © 2017年 鍾安. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    stack<float> staNum;
    
    while ( true ) {
        char ch = -1;
        string str;
        bool isBreak = false;
        
        while (ch != ' ' && ch != '\n') {
            scanf("%c", &ch);
            str.push_back(ch);
        }
        str.pop_back();
        if (ch == '\n') {
            isBreak = true;
        }
        
        if (str.at(0) < 48 || str.at(0) > 59) {
            //operator
            char oper = str.at(0);
            float a,b,c;
            
            b = staNum.top();
            staNum.pop();
            a = staNum.top();
            staNum.pop();
            
            switch (oper) {
                case '+':
                    c = a+b;
                    break;
                case '-':
                    c = a-b;
                    break;
                case '*':
                    c = a*b;
                    break;
                case '/':
                    c = a/b;
                    break;
                default:
                    printf("error\n");
                    break;
            }
            
            staNum.push(c);
        }
        else {
            //number
            float number = 0;
            
            for (int i = 0; i < str.size(); i++) {
                number += (str.at(i)-48) * pow(10, str.size() -1 -i);
            }
            staNum.push(number);
        }
        
        if (isBreak) {
            break;
        }
        
    }
    
    printf("%f\n", staNum.top());
    
    return 0;
}
