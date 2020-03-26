//
//  main.cpp
//  test_XOR
//
//  Created by 鍾安 on 2018/12/1.
//  Copyright © 2018年 鍾安. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <bitset>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    bitset<8> a("00010001") ,b("11001100");
    
    cout<< a << " " << b << endl;
    
    a = a^b;
    b = a^b;
    a = a^b;
    
    cout<< a << " " << b << endl;
    
    
    
    return 0;
}
