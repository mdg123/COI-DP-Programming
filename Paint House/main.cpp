#include <bits/stdc++.h>

using namespace std;

int dp[1005][3], clr[1005][3];

int f(int i, int j){
    int& res=dp[i][j];

    if(res!=-1)
        return res;

    if(j==0)
        res=min(f(i-1,1), f(i-1,2))+clr[i][0];
    else if(j==1)
        res=min(f(i-1,0), f(i-1,2))+clr[i][1];
    else
        res=min(f(i-1,0), f(i-1,1))+clr[i][2];
    return res;
}

int main()
{
    for(int i=0;i<1005;i++)
        memset(dp[i], -1, sizeof(dp[i]));
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d", &clr[i][0],&clr[i][1],&clr[i][2]);

    dp[1][0]=clr[1][0];
    dp[1][1]=clr[1][1];
    dp[1][2]=clr[1][2];

    /*
    for(int i=2;i<=n;i++){
        for(int j=0;j<3;j++){
            if(j==0)
                dp[i][0]=min(dp[i-1][1], dp[i-1][2])+clr[i][0];
            else if(j==1)
                dp[i][1]=min(dp[i-1][0], dp[i-1][2])+clr[i][1];
            else
                dp[i][2]=min(dp[i-1][0], dp[i-1][1])+clr[i][2];
        }
    }
    cout<<min(min(dp[n][0], dp[n][1]), dp[n][2]);
    */
    cout<<min(min(f(n,0), f(n,1)), f(n,2));
    return 0;
}
