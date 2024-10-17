#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
   int n = 0, m = 0;
   cin >> n >> m;
   char** ch = new char* [n];
   for (int i = 0; i < n; i++) {
      ch[i] = new char[m];
      cin >> ch[i];
   }

   int min = 100;
   for (int i = 0; i < n - 7; i++) {
       for (int j = 0; j < m - 7; j++) {
           int count = 0;

           if ((i + j) % 2 == 0) {
               for (int k = 0; k < 8; k++) {
                   for (int l = 0; l < 8; l++) {
                       if ((i + k + j + l) % 2 == 0) {
                           if (ch[i + k][j + l] != ch[i][j])
                               count++;
                       }
                       else {
                           if (ch[i + k][j + l] == ch[i][j])
                               count++;
                       }
                   }
               }
           }

           else {
               for (int k = 0; k < 8; k++) {
                   for (int l = 0; l < 8; l++) {
                       if ((i + k + j + l) % 2 != 0) {
                           if (ch[i + k][j + l] != ch[i][j])
                               count++;
                       }
                       else {
                           if (ch[i + k][j + l] == ch[i][j])
                               count++;
                       }
                   }
               }
           }

           min = std::min(min, std::min(count, 64 - count));
       }
   }

   cout << min << endl;
   
   delete ch;

   return 0;
}

