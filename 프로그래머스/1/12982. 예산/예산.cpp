#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0, cnt = 0;
    sort(d.begin(), d.end());
    
    for(int i = 0; i <= d.size() - 1; i++) {
        sum += d[i];
        if (sum > budget) break;
        cnt++;
    }
    return cnt;
}