#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> basket;
    int cnt = 0;
    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < board.size(); j++){
            if(!board[j][moves[i] - 1]) continue;
            if(basket.size() != 0 && basket.back() == board[j][moves[i] - 1]) {
                basket.pop_back();
                cnt += 2;
            }
            else basket.push_back(board[j][moves[i] - 1]);
            board[j][moves[i] - 1] = 0;
            break;
        }
    }
    return cnt;
}