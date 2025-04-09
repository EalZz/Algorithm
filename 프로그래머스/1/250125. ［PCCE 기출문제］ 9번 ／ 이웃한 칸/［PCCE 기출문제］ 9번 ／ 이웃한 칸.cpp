#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    if(h == 0) {
        if(w == 0) {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
        } 
        else if(w == board[0].size() - 1) {
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
        }
        else {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
        }
    }
    else if(h == board.size() - 1) {
        if(w == 0) {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
        else if(w == board[0].size() - 1) {
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
        else {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
    }
    else {
        if(w == 0) {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
        else if(w == board[0].size() - 1) {
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
        else {
            if(w + 1 < board[0].size() && board[h][w] == board[h][w + 1]) answer++;
            if(w - 1 >= 0 && board[h][w] == board[h][w - 1]) answer++;
            if(h + 1 < board.size() && board[h][w] == board[h + 1][w]) answer++;
            if(h - 1 >= 0 && board[h][w] == board[h - 1][w]) answer++;
        }
    }

    return answer;
}
