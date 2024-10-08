#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string igrade[20][3];

    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 3; col++) {
            cin >> igrade[row][col];
        }
    }

    double credit = 0;
    double mul = 0, sum = 0, result = 0;
    double count = 20;

    for (int i = 0; i < 20; i++) {
        double time = stod(igrade[i][1]);
        if (igrade[i][2] == "P") {
            count--;
            continue;
        }
        else if (igrade[i][2] == "A+") {
            sum += time;
            mul += 4.5 * time;
        }    
        else if (igrade[i][2] == "A0"){
            mul += 4.0 * time;
            sum += time;
        }
        else if (igrade[i][2] == "B+"){
            mul += 3.5 * time;
            sum += time;
        }
        else if (igrade[i][2] == "B0"){
            mul += 3.0 * time;
            sum += time;
        }
        else if (igrade[i][2] == "C+"){
            mul += 2.5 * time;
            sum += time;
        }
        else if (igrade[i][2] == "C0"){
            mul += 2.0 * time;
            sum += time;
        }
        else if (igrade[i][2] == "D+"){
            mul += 1.5 * time;
            sum += time;
        }
        else if (igrade[i][2] == "D0"){
            mul += 1.0 * time;
            sum += time;
        }
        else if (igrade[i][2] == "F"){
            mul += 0 * time;
            sum += time;
        }
    }
    result = mul / sum;
    cout << result << endl;
}