#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> basket;
    int cnt = 0;
    for(int i = 0; i < moves.size(); i++) {
        for(int j = 0; j < board.size(); j++){
            if(!board[j][moves[i] - 1]) continue; // 빈곳이면 다음 칸

            if(basket.size() != 0 && basket.back() == board[j][moves[i] - 1]) { //같은 것끼리 만났을 때
                basket.pop_back(); //터지니 위에있는 것 pop, 따로 추가 안함
                cnt += 2; 
            }
            else basket.push_back(board[j][moves[i] - 1]); //바구니에 쌓일 때
            
            board[j][moves[i] - 1] = 0; //빈공간으로 만들어줌
            break; //한번 진행 했으니 다음 무브로 이동
        }
    }
    return cnt;
}