#include <bits/stdc++.h>

using namespace std;

int dp[5005];
int r;

int f(int r){ // f(r) �� ������ r��ŭ ������, ����ϴ� �ּ����� ���� ��
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
        r3 = f(r-3); //r-3ų�α׷���ŭ ��� �ּ����� ������
    if(r>=5)
        r5 = f(r-5);  // r-5ų�α׷���ŭ ��� �ּ����� ������

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
