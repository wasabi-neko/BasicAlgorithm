//
//  main.cpp
//  infix_calculate
//
//  Created by 鍾安 on 2017/11/2.
//  Copyright © 2017年 鍾安. All rights reserved.
//

#include <cstdio>
#include <math.h>
#include <stack>
#include <string>

using namespace std;

int OperPri(char oper);
float Calculate(float a, float b, char oper);

int main(int argc, const char * argv[]) {
    stack<float> staNum;
    stack<char> staOper;
    
    while (true) {
        char ch = 48;
        char oper;
        string str;
        
        while ( ch >= 48 && ch <= 59) {
            scanf("%c", &ch);
            str.push_back(ch);
        }
        oper = ch;
        str.pop_back();
        
        //push number
        if (str.size() > 0) {
            float number = 0;
            
            for (int i = 0; i < str.size(); i++) {
                number += (str.at(i) -48) * pow(10, str.size() -1-i);
            }
            staNum.push(number);
        }
        
        //push oper
        if (oper == '\n') {
            break;
        }
        else {
            
            if (oper != '(') {
                while ( staOper.size() > 0 && OperPri(staOper.top()) > OperPri(oper) ) {
                    float a,b,c;
                    char tempOper;
                    
                    tempOper = staOper.top();
                    staOper.pop();
                    b = staNum.top();
                    staNum.pop();
                    a = staNum.top();
                    staNum.pop();
                    
                    c = Calculate(a, b, tempOper);
                    staNum.push(c);
                }
            }
            
            if (staOper.size() > 0 && oper == ')') {
                staOper.pop();
            }
            else {
                staOper.push(oper);
            }
        }
    }
    
    while ( staNum.size() > 1) {
        float a,b,c;
        char oper;
        
        oper = staOper.top();
        staOper.pop();
        b = staNum.top();
        staNum.pop();
        a = staNum.top();
        staNum.pop();
        
        c = Calculate(a, b, oper);
        staNum.push(c);
    }
    
    printf("%f\n", staNum.top());
    
    return 0;
}

//sta.top > oper : pop
int OperPri(char oper) {
    switch (oper) {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case ')':
            return 0;
            break;
        case '(':
            return -1;
            break;
        default:
            return 0;
            break;
    }
}

float Calculate(float a, float b, char oper) {
    int re = 0;
    
    switch (oper) {
        case '+':
            re = a + b;
            break;
        case '-':
            re = a - b;
            break;
        case '*':
            re = a * b;
            break;
        case '/':
            re = a / b;
            break;
        default:
            printf("calculate error\n");
            break;
    }
    
    return re;
}

