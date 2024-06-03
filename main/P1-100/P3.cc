#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,v;
    cin>>n>>v;
    vector<int> weights(n,0);
    vector<int> values(n,0);
    for(int i=0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    int dp[n+1][v+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=v;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            if(j<weights[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = std::max(dp[i-1][j],dp[i][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    cout<<dp[n][v]<<endl;
	return 0;
}