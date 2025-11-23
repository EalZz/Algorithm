#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, pair<int, int>> cmd = {
        {"R", {0, 1}}, {"L", {0, -1}}, {"B", {-1, 0}}, {"T", {1, 0}},
        {"RT", {1, 1}}, {"LT", {1, -1}}, {"RB", {-1, 1}}, {"LB", {-1, -1}}
    };

    map<char, int> tocol = {
        {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4},
        {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8}
    };

    map<int, char> tostr = {
        {1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'},
        {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}
    };

    string k, r; 
    cin >> k >> r;
    int N; cin >> N;

    pair<int, int> king, rock;

    king.first = k[1] - '0';
    king.second = tocol[k[0]];

    rock.first = r[1] - '0';
    rock.second = tocol[r[0]];

    while (N--) {
        string s; cin >> s;
        int dy = cmd[s].first;
        int dx = cmd[s].second;

        int krow = king.first + dy;
        int kcol = king.second + dx;

        if (krow < 1 || krow > 8 || kcol < 1 || kcol > 8) continue;

        if (krow == rock.first && kcol == rock.second) {
            int rrow = rock.first + dy;
            int rcol = rock.second + dx;

            if (rrow < 1 || rrow > 8 || rcol < 1 || rcol > 8) continue;
            
            rock.first = rrow;
            rock.second = rcol;
        }

        king.first = krow;
        king.second = kcol;
    }

    cout << tostr[king.second] << king.first << '\n'
         << tostr[rock.second] << rock.first;

    return 0;
}
