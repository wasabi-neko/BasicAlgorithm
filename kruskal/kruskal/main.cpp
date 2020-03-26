//
//  main.cpp
//  kruskal
//
//  Created by 鍾安 on 2017/12/16.
//  Copyright © 2017年 鍾安. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <list>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> VertxLink;   //first:link to, second:distant
class Edge {
public:
    Edge() { }
    Edge(pair<int, int> vertexs_val,int d) { vertexs = vertexs_val; distant = d;}
    ~Edge() { }
    
    pair<int, int> vertexs;
    int distant;
};

bool CMP(Edge e1, Edge e2) {
    return e1.distant < e2.distant;
}

int gSize,eSize;
list<VertxLink> graph[500000];
list<Edge> listEdge;

void Kruskal(vector<list<VertxLink>>& MST) {
    set<int> mstSet;
    list<Edge>::iterator iter = listEdge.begin();
    
    while (mstSet.size() < gSize) {
        int a,b,distant;
        
        a = iter->vertexs.first;
        b = iter->vertexs.second;
        distant = iter->distant;
        if (mstSet.count(a) == 0 || mstSet.count(b) == 0) {
            mstSet.insert(a);
            mstSet.insert(b);
            
            MST.at(a).push_back(VertxLink(b,distant));
            MST.at(b).push_back(VertxLink(a,distant));
        }
        iter++;
    }
}

int main(int argc, const char * argv[]) {
//    FILE *file = fopen("test.txt", "w");
//    
//    fprintf(file, "500000 500000\n");
//    for (int i = 0; i < 500000-1; i++) {
//        fprintf(file, "%d %d 1\n",i,i+1);
//    }
//    fprintf(file, "499999 0 1\n");
//
//    fclose(file);
//
//    return 0;
    FILE* file = fopen("test.txt", "r");
    
//    scanf("%d %d", &gSize, &eSize);
    fscanf(file, "%d %d", &gSize, &eSize);
    
    for (int i = 0; i < eSize; i++) {
        int a,b,distant;
        
//        scanf("%d %d %d", &a, &b, &distant);
        fscanf(file, "%d %d %d", &a, &b, &distant);
        
        graph[a].push_back(VertxLink(b,distant));
        graph[b].push_back(VertxLink(a,distant));
        listEdge.push_back(Edge( pair<int, int>(a,b), distant));
    }
    listEdge.sort(CMP);
    
    vector<list<VertxLink>> MST(gSize);
    Kruskal(MST);
    
    for (int i = 0; i < gSize; i++) {
        for (list<VertxLink>::iterator iter = MST.at(i).begin(); iter != MST.at(i).end(); iter++) {
            printf("%d %d %d\n", i, iter->first, iter->second);
        }
    }
    
    return 0;
}
