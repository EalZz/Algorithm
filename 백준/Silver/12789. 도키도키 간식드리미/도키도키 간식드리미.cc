#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
void switchLine(queue<int>& q, stack<int>& st);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    int cnt = 1;
    stack<int> st;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        int tmp = 0; cin >> tmp;
        q.push(tmp);
    }

    while (1) {
        //현 대기줄에 사람이 있을 때
        if (!q.empty()) {
            if (!st.empty()) {
                if (q.front() != cnt && st.top() != cnt) switchLine(q, st);
                else if (q.front() == cnt) {
                    q.pop();
                    cnt++;
                }
                else if (st.top() == cnt) {
                    st.pop();
                    cnt++;
                }
            }
            else {
                if (q.front() != cnt) switchLine(q, st);
                else {
                    q.pop();
                    cnt++;
                }
            }
        }
        //현 대기줄에 사람이 없을 때
        else {
            if (!st.empty()) {
                if (st.top() == cnt) {
                    st.pop();
                    cnt++;
                }
                //더 이상 진행 할 수 없으므로 Sad 출력
                else {
                    cout << "Sad";
                    return 0;
                }
            }
            //두 줄 모두 사람이 없으면 Nice출력
            else {
                cout << "Nice";
                return 0;
            }
        }
    }
    return 0;
}

void switchLine(queue<int>& q, stack<int>& st) {
    int tmp = q.front();
    st.push(tmp);
    q.pop();
}