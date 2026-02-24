#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("max.in", "r", stdin);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int &t : x) { cin >> t; }
	for (int &t : y) { cin >> t; }

	cout << "DEFAULT X: ";
	for (int t : x) { cout << t << " "; }
	cout << "\nDEFAULT Y: ";
	for (int t : y) { cout << t << " "; }
	cout << endl;

	int max_squared = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];

			int square = dx*dx + dy*dy;
			if (square > max_squared) max_squared = square;
		}
	}
	
	freopen("max.out", "w", stdout);
	cout << max_squared << endl;
}