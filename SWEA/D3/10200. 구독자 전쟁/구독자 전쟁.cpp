#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int T = 0; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N = 0, P = 0, T = 0; cin >> N >> P >> T;
        int max = (P >= T) ? T : P;
        int min = (P + T > N) ? P + T - N : 0;
        
        cout << "#" << i << " " << max << " " << min << endl;
    }
    return 0;
}