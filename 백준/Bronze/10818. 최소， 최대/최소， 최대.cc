#include <iostream>
using namespace std;

int main() {
    int t, max = 0, min = 0;
    cin >> t;

    int *list = new int[t];

    for (int i = 0; i < t; i++) {
        cin >> list[i];
    }

    max = list[0];
    min = list[0];

    for(int j = 0; j < t; j++) {
        if (max < list[j])
            max = list[j];
    }

    for (int j = 0; j < t; j++) {
        if (min > list[j])
            min = list[j];
    }

    cout << min << " " << max;

    return 0;
}
