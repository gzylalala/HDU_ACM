#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX=10005;

int price[MAX];
double prob[MAX];

// We use dp to record the limitation
double dp[MAX];

using namespace std;

int main()
{
    int n,m;
    while(scanf_s("%d%d",&n,&m) && (m+n)!=0)
    {
        for (int i=1;i<=m;i++)
            scanf_s("%d%lf",&price[i],&prob[i]);

        memset(dp,0.0,sizeof(dp));

        for (int i=1;i<=m;i++)
            for (int j=n;j>=price[i];j--)
                dp[j]=max(dp[j],1-(1-dp[j-price[i]])*(1-prob[i]));

        double result=dp[n]*100;

        printf("%.1lf%%\n",result);


    }
}

