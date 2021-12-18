#include <bits/stdc++.h>

using namespace std;

int dp[305];
int a[305];
//dp[i] = max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]);


int f(int r){
    int& res=dp[r];
    if(res!=-1)
        return res;
    res=max(f(r-2)+a[r], f(r-3)+a[r-1]+a[r]);
    return res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int r;
    scanf("%d", &r);
    for(int i=1;i<=r;i++)
        scanf("%d", &a[i]);
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=a[1]+a[2];
    //cout<<f(r)<<endl;
    for(int i=3;i<=r;i++){
        dp[i]=max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]);
    }
    cout<<dp[r]<<endl;
    return 0;
}
