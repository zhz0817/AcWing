#include <bits/stdc++.h>
using namespace std;

#define FOR_INC(i, start, end) for (int i = start; i < end; ++i)
#define FOR_DEC(i, start, end) for (int i = start; i > end; --i)
#define FOR_INC_EQUAL(i, start, end) for (int i = start; i <= end; ++i)
#define FOR_DEC_EQUAL(i, start, end) for (int i = start; i >= end; --i)


int main()
{
	int n,v;
    cin>>n>>v;
    vector<int> weights(2000,0);
    vector<int> values(2000,0);
    vector<int> amounts(2000,0);
    int count = 0;
    FOR_INC_EQUAL(i, 1, n){
        int v1,w,s;
        cin>>v1>>w>>s;
        weights[i] = v1;
        values[i] = w;
        amounts[i] = s;
    }
    vector<int> dp(2010,0);
    FOR_INC_EQUAL(i, 1, count){
        FOR_DEC_EQUAL(j, v, weights[i]){
            dp[j] = max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    cout<<dp[v]<<endl;
	return 0;
}