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
    vector<int> weights(12000,0);
    vector<int> values(12000,0);
    int count = 0;
    FOR_INC_EQUAL(i, 1, n){
        int v1,w,s;
        cin>>v1>>w>>s;
        int k = 1;
        while(s>=k){
            count++;
            weights[count] = v1*k;
            values[count] = w*k;
            s-=k;
            k*=2;
        }
        if(s>0){
            count++;
            weights[count] = v1*s;
            values[count] = w*s;
        }
        //比如这个物品有10个，分二进制分为1，2，4，最后剩下3。那么这4个数可以表示0-10以内所有的数，包含了所有的选择。
    }
    int dp[2010];
    memset(dp, 0, sizeof(dp));
    FOR_INC_EQUAL(i, 1, count){
        FOR_DEC_EQUAL(j, v, weights[i]){
            dp[j] = max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    cout<<dp[v]<<endl;
	return 0;
}