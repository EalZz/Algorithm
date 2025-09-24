#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> pri(priorities.size());
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++) {
        pri[i] = priorities[i];
        pq.push(priorities[i]);
    }
    
    int idx = 0;
    while(1) {
        if(pri[idx] == -1) idx++;
        if(idx >= pri.size()) idx = 0;
        
        if(pri[idx] == pq.top()) {
            if(idx == location) return answer;
            pri[idx] = -1;
            pq.pop();
            answer++;
        }
        idx++; 
    }
    
    return -1;
}