#include <bits/stdc++.h>

using namespace std;

int dp[1005]; //dp[i]란? 계단 i개가 있을때, 올라가는 방법의 수
//dp[i] = dp[i-1] + dp[i-2];


int f(int r){

    int& res=dp[r];
    if(res!=-1)
        return res;

    return res=(f(r-1)+f(r-2))%10007;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    int r;
    scanf("%d", &r);
    //cout<<f(r);

    for(int i=3;i<=r;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[r];
    return 0;
}
