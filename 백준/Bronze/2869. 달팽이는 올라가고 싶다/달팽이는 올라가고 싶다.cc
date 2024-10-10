#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int up = 0, down = 0, goal = 0, count = 0;
	cin >> up >> down >> goal;
	int goal_l = goal - up;
	count = goal_l / (up - down) + 1;

	if (goal_l % (up - down) != 0)
		count++;
	if (up >= goal)
		count = 1;


	cout << count;

	return 0;
}