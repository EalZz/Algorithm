#include <string>
#include <vector>

using namespace std;

void nQueen(int n, int row, vector<bool>& colA, vector<bool>& diag1, vector<bool>& diag2);
int answer = 0;

int solution(int n) {
    
    vector<bool> colA(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    
    nQueen(n, 0, colA, diag1, diag2);
    
    return answer;
}

void nQueen(int n, int row, vector<bool>& colA, vector<bool>& diag1, vector<bool>& diag2) {
    if(row == n) {
        answer++;
        return;
    }
    
    for(int col = 0; col < n; col++) {
        if(!colA[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
            colA[col] = true;
            diag1[row - col + n - 1] = true;
            diag2[row + col] = true;
            
            nQueen(n, row + 1, colA, diag1, diag2);
            
            colA[col] = false;
            diag1[row - col + n - 1] = false;
            diag2[row + col] = false;
        }
    }
    return;
}