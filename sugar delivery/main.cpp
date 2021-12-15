#include <bits/stdc++.h>

using namespace std;

int dp[5005];

int f(int r){
    int& res = dp[r];
    if(res!=-1)
        return res;

    if(r==0)
        return res = 0;
    else if(r<3)
        return res = -1;

    int r1=-1, r2=-1;
    if(r>=3) r1 = f(r-3);
    if(r>=5) r2 = f(r-5);

    if(r1!=-1 && r2!=-1)
        return res = min(r1, r2)+1;
    else if(r1==-1 && r2!=-1)
        return res = r2+1;
    else if(r1!=-1 && r2==-1)
        return res = r1+1;
    else
        return res = -1;
}

int main()
{
    int r;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &r);
    cout<<f(r)<<endl;
    return 0;
}
