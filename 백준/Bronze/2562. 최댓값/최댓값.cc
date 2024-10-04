#include <iostream>
using namespace std;

int main() {
    int t, max = 0;
    int count = 1;
    t = 9;
    //cin >> t;

    int *list = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> list[i];
    }

    max = list[0];

    for(int j = 0; j < t; j++) {
        if (max < list[j])
            max = list[j];
    }

    for (int j = 0; j < t; j++) {
        if (list[j] != max) {
            count += 1;
        }
        else {
            break;
        }
    }


    cout << max << endl << count;

    return 0;
}
