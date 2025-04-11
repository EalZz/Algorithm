#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    //for(int i = 0; i < players.size(); i++) m[players[i]] = i; 
    for(int i = 0; i < players.size(); i++) m[players[i]] = i; 
    //선수, 처음순위로 매핑
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