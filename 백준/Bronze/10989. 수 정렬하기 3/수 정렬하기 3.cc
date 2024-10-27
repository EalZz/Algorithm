#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
long long gcd(long long a, long long b);
bool isPrime(long long int num);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cnt[10001] = { 0 };
	int n,count;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> count;
		cnt[count]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = 0; j < cnt[i]; j++)
			cout << i<<'\n';

	return 0;
    
    return 0;
}