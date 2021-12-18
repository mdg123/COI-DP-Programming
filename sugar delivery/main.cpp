#include <bits/stdc++.h>

using namespace std;

int dp[5005];
int r;

int f(int r){ // f(r) 은 설탕양 r만큼 있을때, 사용하는 최소한의 봉지 수
    //cout<<"f("<<r<<")"<<endl;
    int& res=dp[0];
    if(res!=-1)
        return res;

    if(r==0)
        return res = 0;
    else if(r<3)
        return res = -1;

    int r3=-1, r5=-1;
    if(r>=3)
        r3 = f(r-3); //r-3킬로그램만큼 덜어낸 최소한의 봉지수
    if(r>=5)
        r5 = f(r-5);  // r-5킬로그램만큼 덜어낸 최소한의 봉지수

    if(r3!=-1 && r5!=-1)
        return res=min(r3, r5)+1;
    else if(r3==-1 && r5!=-1)
        return res=r5+1;
    else if(r3!=-1 && r5==-1)
        return res=r3+1;
    else
        return res=-1;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &r);
    printf("%d", f(r));
    return 0;
}
