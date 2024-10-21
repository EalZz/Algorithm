#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void quickSort(int* data, int start, int end);

int main() {
    int num, tmp;
    vector<int> a;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < num; i++)
        cout << a[i] << '\n';

	return 0;
}
