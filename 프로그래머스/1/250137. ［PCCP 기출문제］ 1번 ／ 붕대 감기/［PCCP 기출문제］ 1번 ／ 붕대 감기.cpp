#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int result = 0;
    int p_time = 0, b_time = 0, p_health = health, attack_idx = 0;

    while (p_time < attacks.back().front()) {
        
        p_time++;                               // 현재시간 + 1

        cout << "-----------------------------시간 " << p_time << endl;
        // 공격시간(마지막 공격제외)과 현재시간 우선 비교
        if (attack_idx < attacks.size() && p_time == attacks[attack_idx].front()) { 
            p_health -= attacks[attack_idx].back();
            cout << "공격 -" << attacks[attack_idx].back() << endl;
            b_time = 0;                          // 붕대감기 시간 초기화
            attack_idx++;
            cout << "공격 후 체력 " << p_health << endl;
            if (p_health <= 0) {                  // 체력이 0 이하가 되면 반복 종료
                return -1;
            }
            continue;
        }


        if (b_time < bandage.front()) {
            b_time++;
            cout << "현재 시전 시간 " << b_time << endl
                << "추가 회복 목표시간 " << bandage.front() << endl;
            if (p_health < health) {                // 붕대감기 계산
                p_health += bandage[1];
                cout << "회복 +" << bandage[1] << endl;
                if (b_time == bandage.front()) {
                    p_health += bandage.back();
                    cout << "추가회복 +" << bandage.back() << endl;
                    b_time = 0;   
                }
            if (p_health > health)
                p_health = health;
            }
            cout << "회복 후 체력 " << p_health << endl;
        }
    }
    result = p_health;
    return result;
}