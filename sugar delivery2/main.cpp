#include <bits/stdc++.h>

using namespace std;

int dp[5005]; //dp[i]는 설탕의 양 i만큼 있을때, 사용하는 최소한의 봉지 수

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    int r, r3, r5;
    scanf("%d", &r);

    for(int i=3; i<=r;i++){
        r3=dp[i-3];
        if(i<5)
            r5=-1;
        else
            r5=dp[i-5];

        if(r3!=-1 && r5!=-1)
            dp[i]=min(r3, r5)+1;
        else if(r3==-1 && r5!=-1)
            dp[i]=r5+1;
        else if(r3!=-1 && r5==-1)
            dp[i]=r3+1;
        else
            dp[i]=-1;
    }
    cout<<dp[r]<<endl; //printf("%d", dp[r]);
    return 0;
}
