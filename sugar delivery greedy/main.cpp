#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r=0;
    scanf("%d", &r);
    for(int i=0;i<=r/3;i++){
        int a = r-i*3;
        if(a%5==0){
            cout<<a/5+i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
