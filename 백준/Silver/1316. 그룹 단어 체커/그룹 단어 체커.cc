#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n = 0, max = 0, count = 0, i_count = 0, index = 0, result = 0;
	cin >> n;
	string* str = new string[n];
	char alphabet[26];
	int a_count[26] = { 0, };
	

	for (int i = 0; i < 26;i++) {
		alphabet[i] = 'a' + i;
	}
	//n : 테스트 횟수
	for (int i = 0; i < n; i++) {
		int a_count[26] = { 0, };
		bool check = true;
		cin >> str[i];
		const char* pch = str[i].c_str();
		int len = str[i].length();

		//j : 각각 알파벳을 비교
		for (int j = 0; j < 26; j++) {
			// k : 알파벳을 단어의 인덱스별로 비교
			for (int k = 0; k < len; k++) {
				if (pch[k] == alphabet[j]) {
					a_count[j]++;
				}
			}
			if (a_count[j] >= 2) {
				//2개이상있는 알파벳의 첫번째 인덱스
				int a_index = str[i].find(alphabet[j]);
				for (int k = a_index + a_count[j]; k < len; k++) {
					if (pch[k] == pch[a_index]) {
						check = false;
						break;
					}
				}
			}
		}
		if (check == true) {
			result++;
		}
		//cout << "check : " << check << endl;
	}
	cout << result << endl;

	return 0;
}
