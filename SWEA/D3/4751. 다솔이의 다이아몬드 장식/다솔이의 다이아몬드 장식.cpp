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
        string s; cin >> s;
        if (s.size() == 1) {
            cout << "..#.." << endl
                << ".#.#." << endl
                << "#." << s << ".#" << endl
                << ".#.#." << endl
                << "..#.." << endl;
        }
        else {
            for (int j = 0; j < s.size(); j++) cout << "..#."; cout << "." << endl;
            for (int j = 0; j < s.size(); j++) cout << ".#.#"; cout << "." << endl;
            for (int j = 0; j < s.size(); j++) cout << "#." << s[j] << "." ; cout << "#" << endl;
            for (int j = 0; j < s.size(); j++) cout << ".#.#"; cout << "." << endl;
            for (int j = 0; j < s.size(); j++) cout << "..#."; cout << "." << endl;
        }
    }
    return 0;
}