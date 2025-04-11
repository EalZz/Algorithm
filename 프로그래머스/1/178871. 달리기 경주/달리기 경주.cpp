#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    //선수와 순위(인덱스) 맵핑
    for(int i = 0; i < players.size(); i++) m[players[i]] = i; 
    
    //선수가 불리면 앞 선수와 스왑 후 인덱스도 교체
    for(auto call : callings) {
        int call_idx = m[call];
        int swap_idx = call_idx - 1;
        string front = players[swap_idx];
        swap(players[call_idx], players[swap_idx]);
        
        m[call] = swap_idx;
        m[front] = call_idx;
    }
    
    return players;
}

/*
vector<string> solution(vector<string> players, vector<string> callings) {
    for(auto c : callings) {
        auto it = find(players.begin() + 1, players.end(), c);
        auto postit = it - 1;
        string player = *it;
        players.erase(it);
        players.insert(postit, player);
    }
    
    return players;
}
*/