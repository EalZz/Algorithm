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
        int count = 0; cin >> count;
        int dev = 0;
        vector<string> new_deck, d_deck_f, d_deck_s;

        if (count % 2 == 0) dev = count / 2;
        else dev = count / 2 + 1;

        for (int j = 0; j < dev; j++) {
            string tmp; cin >> tmp;
            d_deck_f.push_back(tmp);
        }

        for(int j = dev; j < count; j++) {
            string tmp; cin >> tmp;
            d_deck_s.push_back(tmp);
        }

        for (int j = 0; j < dev; j++) {
            new_deck.push_back(d_deck_f[j]);
            if (d_deck_s.size() == j) break;
            new_deck.push_back(d_deck_s[j]);
        }
    
        cout << "#" << i << " ";
        for (int j = 0; j < new_deck.size(); j++) cout << new_deck[j] << " ";
        cout << endl;
    }
    return 0;
}