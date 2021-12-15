#include <bits/stdc++.h>

using namespace std;

//dp[i]는 설탕의 양 i만큼 있을때, 최소 봉지수
int dp[5005];

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    int r, r1, r2;
    scanf("%d", &r);

    for(int i=3;i<=r;i++){
        r1=dp[i-3];
        if(i<5) r2=-1;
        else r2=dp[i-5];

        if(r1!=-1 && r2!=-1) dp[i] = min(dp[i-3], dp[i-5])+1;
        else if(r1==-1 && r2!=-1) dp[i]=dp[i-5]+1;
        else if(r1!=-1 && r2==-1) dp[i]=dp[i-3]+1;
        else dp[i]=-1;
    }
    cout<<dp[r]<<endl;
    return 0;
}
