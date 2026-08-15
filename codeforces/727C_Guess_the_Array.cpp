#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int ask(int i,int j){
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int z;
    scanf("%d",&z);
    return z;
}

int ans[100500];

int main(){
    int n;
    scanf("%d",&n);
    int sum1=ask(1,2),sum2=ask(2,3),sum3=ask(1,3),b=(sum1+sum2-sum3)/2;
    ans[1]=sum1-b;
    ans[2]=b;
    ans[3]=sum2-b;
    for(int i=4;i<=n;i++) ans[i]=ask(2,i)-ans[2];
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}