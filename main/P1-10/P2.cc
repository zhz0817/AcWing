#include <bits/stdc++.h>
using namespace std;

#define FOR_INC(i, start, end) for (int i = start; i < end; ++i)
#define FOR_DEC(i, start, end) for (int i = start; i > end; --i)
#define FOR_INC_EQUAL(i, start, end) for (int i = start; i <= end; ++i)
#define FOR_DEC_EQUAL(i, start, end) for (int i = start; i >= end; --i)

int main() {
  int n, v;
  cin >> n >> v;
  int dp[v + 1];
  memset(dp, 0, sizeof(dp));
  FOR_INC_EQUAL(i, 1, n) {
    int weight, value;
    cin >> weight >> value;
    FOR_DEC_EQUAL(j, v, weight) { dp[j] = max(dp[j], dp[j - weight] + value); }
  }
  cout << dp[v] << endl;
  return 0;
}

// https://www.acwing.com/problem/content/discussion/content/2807/