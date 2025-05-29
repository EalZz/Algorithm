#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
    vector<int> divisor = {2, 3, 5, 7 ,11};

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a = 0;
        cin >> a;
        cout << "#" << test_case << " ";
		
        for(auto d : divisor) {
            int cnt = 0;
            while(a % d == 0){
                cnt++;
                a /= d;
            }
            cout << cnt << " ";
        }
        cout << endl;
	}
	return 0;
}