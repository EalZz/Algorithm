#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int *list = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> list[i];
    }

    int search, count = 0;
    cin >> search;

    for (int j = 0; j < t; j++) {
        if (list[j] == search) {
            count += 1;
        }
    }
    cout << count << endl;

    return 0;
}