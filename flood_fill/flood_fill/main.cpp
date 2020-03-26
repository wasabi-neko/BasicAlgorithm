//
//  main.cpp
//  flood_fill
//
//  Created by 鍾安 on 2017/10/31.
//  Copyright © 2017年 鍾安. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>

#define PI 3.141592565358979

using namespace std;

typedef struct Point {
    int x = 0;
    int y = 0;
}Point;

bool IsInlaw(Point p, int size) {
    return (p.x >= 0 && p.x < size) && (p.y >= 0 && p.y < size);
}

//flood fill
// 1 for wall, 0 for road
int main(int argc, const char * argv[]) {

    int size = 0;
    scanf("%d\n", &size);
    
    if (size == 0) {
        printf("error: size is 0\n");
        return -1;
    }
    
    int map[size][size];
    Point backMap[size][size];
    char showMap[size][size];
    int minPath_n = 0;
    queue<Point> que;
    Point startPoint, endPoint;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            char ch;
            
            scanf("%c", &ch);
            showMap[i][j] = ch;
            if (ch == '1') {
                ch = -1;
            }
            else {
                ch = 0;
            }
            map[i][j] = ch;
        }
        scanf("\n");
    }
    
    scanf("%d%d", &startPoint.x, &startPoint.y);
    scanf("%d%d", &endPoint.x, &endPoint.y);
    
    
    //fill
    que.push(Point(startPoint));
    
    while ( que.size() != 0) {
        Point point;
        
        point = que.front();
        que.pop();
        
        for (float theta = 0; theta <= 280; theta += 90) {
            Point newPoint;
            int tempVal;
            int mapVal;
            bool sizeLimit,valLimit,wallLimit, startPLimit;
            bool stopLimit = true;
            
            newPoint.x = point.x + (int)round(cos(theta * PI/180));
            newPoint.y = point.y + (int)round(sin(theta * PI/180));
            
            mapVal = map[newPoint.x][newPoint.y];
            tempVal = map[point.x][point.y] +1;
            
            sizeLimit = IsInlaw(newPoint, size);
            valLimit = (tempVal <= mapVal) || (mapVal == 0);    //
            wallLimit = tempVal != -1;
            startPLimit = !(newPoint.x == startPoint.x && newPoint.y == startPoint.y);
            
            if ( map[endPoint.x][endPoint.y] != 0) {
                stopLimit = tempVal <= map[endPoint.x][endPoint.y];     //is min
            }
            
            if ( sizeLimit && valLimit && wallLimit && startPLimit && stopLimit) {
                map[newPoint.x][newPoint.y] = tempVal;
                backMap[newPoint.x][newPoint.y] = point;
                que.push(newPoint);
                if (newPoint.x == endPoint.x && newPoint.y == endPoint.y) {
                    minPath_n++;
                }
            }
        }
    }
    //end main process
    
    printf("min_path_value: %d\n", map[endPoint.x][endPoint.y]);
    printf("min_path_n: %d\n", minPath_n);
//    //output map
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            printf("%03d ", map[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    
    //show path
    Point point;
    
    point = endPoint;
    while ( !( point.x == startPoint.x && point.y == startPoint.y)) {
        showMap[point.x][point.y] = '#';
        point = backMap[point.x][point.y];
    }
    showMap[endPoint.x][endPoint.y] = 'T';
    showMap[startPoint.x][startPoint.y] = 'S';
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", showMap[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}






