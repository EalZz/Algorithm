#include <iostream>
using namespace std;

int main() {
    int x, t;
    cin >> t >> x;

    int *list = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> list[i];
    }

    for (int j = 0; j < t; j++) {
        if (list[j] < x ) {
            cout << list[j] << " ";
        }
    }

    return 0;
}