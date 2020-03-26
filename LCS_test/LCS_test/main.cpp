//
//  main.cpp
//  LCS_test
//
//  Created by 鍾安 on 2018/6/9.
//  Copyright © 2018年 鍾安. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const float PI = 3.1415926535;

string s;
string t;

vector<vector<int>> sta; // [s_pos][t_pos]
vector<vector<pair<int, int>>> map; //

int Dp (int sPos, int tPos) {
    if ( sPos < 0 || tPos < 0)
        return 0;
    
    int maxLen = 0;
    pair<int, int> dir;
    
    for (float theta = PI/4; theta < 2*PI+0.1; theta += PI/2) {
        int x = round(cos(theta));
        int y = round(sin(theta));
        
        x = (x>0)? 0 : x;
        y = (y>0)? 0 : y;
        
        if ( (abs(x) | abs(y)) && sPos+x >= 0 && tPos+y >= 0 ) {
            if ( sta[sPos+x][tPos+y] == -1) {
                sta[sPos+x][tPos+y] = Dp(sPos+x, tPos+y);
            }
            
            int tempVal = sta[sPos+x][tPos+y];
            if ( x == -1  && y == -1 && s.at(sPos) == t.at(tPos)) {
                tempVal += 1;
            }
            
            if ( tempVal > maxLen) {
                maxLen = tempVal;
                dir.first = x;
                dir.second = y;
            }
        }
    }
    
    map[sPos][tPos] = dir;
    return maxLen;
    
}

pair<int, int> PrintMap(int x,int y) {
    printf("%d %d\n", x,y);
    int addX = map[x][y].first;
    int addY = map[x][y].second;
    
    printf("add:%d,%d\n", addX, addY);
    if ( addX + addY == 2)
        return pair<int, int>(0x7fffffff,0x7fffffff);
    else if ( addX + addY == 0)
        return pair<int, int>(x,y);
    else
        PrintMap(x+addX, y+addY);
    
    return  pair<int, int>(0x7fffffff,0x7fffffff);
}

int main(int argc, const char * argv[]) {
    
    cin>> s;
    cin>> t;
    sta.resize(s.size(), vector<int>(t.size(), -1));
    map.resize(s.size(), vector<pair<int, int>>(t.size(), pair<int, int>(0,0) ));

    int ans = Dp(s.size()-1, t.size()-1);
    ans += s.at(0) == t.at(0);
    
    printf("ans:%d\n", ans);
    
    pair<int, int> pos;
    pos = PrintMap(s.size()-1, t.size()-1);
    
    for (int i = pos.first+1; i < pos.first+1 + ans; i++) {
        printf("%c", s.at(i));
    }
    printf("\n");
    
    return 0;
}














