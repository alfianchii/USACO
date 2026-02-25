#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;

int n;
vector<long long> weights;

ll recurse_apples(int index, ll sum1, ll sum2) {
  if (index == n) { return abs(sum1 - sum2); }

  return min(
    recurse_apples(index + 1, sum1 + weights[index], sum2),
    recurse_apples(index + 1, sum1, sum2 + weights[index])
  );
}

int main() {
  freopen("apple.in", "r", stdin);

  cin >> n;
  weights.resize(n);
  for (int i = 0; i < n; i++) { cin >> weights[i]; }

  freopen("apple.out", "w", stdout);
  cout << recurse_apples(0, 0, 0) << endl;
}