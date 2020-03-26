//
//  main.cpp
//  knapsack
//
//  Created by 鍾安 on 2018/10/20.
//  Copyright © 2018年 鍾安. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    Item() { }
    Item(int costData, int valData) {
        this->cost = costData;
        this->val = valData;
    }
    ~Item() { }
    int cost;
    int val;
};

bool CMP (Item a, Item b) {
    return a.val > b.val;
}

const int bagSize = 100;
const int arrSizeMax = 10000;

int staArr[arrSizeMax+1] = {0};
vector<Item> vecItem;

void knapsack(int itemSize, int bagV) {
    int sum = 0;
    
    for (int i = 0; i < itemSize; i++) {
        Item newItem = vecItem.at(i);
        sum += newItem.cost;
        
        for (int j = min(bagV, sum); j - newItem.cost >= 0; j--) {
            staArr[j] = max( staArr[j], staArr[j-newItem.cost] + newItem.val);
        }
    }
}


int main(int argc, const char * argv[]) {
    int n = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int cost, tempVal;
        scanf("%d %d", &cost, &tempVal);
        
        vecItem.push_back(Item(cost, tempVal));
    }
    sort(vecItem.begin(), vecItem.end(), CMP);

//    for ( Item item : vecItem) {
//        printf("%d\n", item.val);
//    }
    
    
    knapsack(vecItem.size(), bagSize);
    printf("%d", staArr[bagSize]);
    
    
    return 0;
}










