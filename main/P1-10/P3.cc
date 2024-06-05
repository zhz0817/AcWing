#include <bits/stdc++.h>
using namespace std;

#define FOR_INC(i, start, end) for (int i = start; i < end; ++i)
#define FOR_DEC(i, start, end) for (int i = start; i > end; --i)
#define FOR_INC_EQUAL(i, start, end) for (int i = start; i <= end; ++i)
#define FOR_DEC_EQUAL(i, start, end) for (int i = start; i >= end; --i)

int main() {
  int n, v;
  cin >> n >> v;
  vector<int> weights(n + 1, 0);
  vector<int> values(n + 1, 0);
  FOR_INC_EQUAL(i, 1, n) { cin >> weights[i] >> values[i]; }
  int dp[v + 1];
  memset(dp, 0, sizeof(dp));
  FOR_INC_EQUAL(i, 1, n) {
    FOR_INC_EQUAL(j, weights[i], v) {
      dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
    }
  }
  cout << dp[v] << endl;
  return 0;
}