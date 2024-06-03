#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,v;
    cin>>n>>v;
    vector<int> weights;
    weights.emplace_back(0);
    vector<int> values;
    values.emplace_back(0);
    int index = 0;
    for(int i=1;i<=n;i++){
        int v1,w,s;
        cin>>v1>>w>>s;
        while(s>0){
            s--;
            weights.emplace_back(v1);
            values.emplace_back(w);
            index++;
        }
    }
    int dp[index+1][v+1];
    for(int i=0;i<=index;i++){
        for(int j=0;j<=v;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=index;i++){
        for(int j=0;j<=v;j++){
            if(j>=weights[i])
                dp[i][j] = std::max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[index][v]<<endl;
	return 0;
}