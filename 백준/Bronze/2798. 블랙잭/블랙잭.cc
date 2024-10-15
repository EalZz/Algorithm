#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = 0;

    for (int i = 0; i < n - 2; i++) {
        if (arr[i] >= m - 1)
            continue;
        for (int j = i + 1; j < n - 1; j++) { 
            if (arr[j] >= m)
                continue;
            for (int k = j + 1; k < n; k++) { 
                if (arr[i] + arr[j] + arr[k] > m)
                    continue;
                if (max < arr[i] + arr[j] + arr[k])
                    max = arr[i] + arr[j] + arr[k];
            }
        }
    }

    cout << max << endl;

    delete[] arr;  
	return 0;
}
