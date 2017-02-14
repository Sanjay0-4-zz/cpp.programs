#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;


int main() {
	//code
	int t,min=INT_MAX,max=INT_MIN;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],ans=n+1;
	    for(int i=0;i<n;i++)
	    {   
	       cin>>a[i];
	       if(min>a[i])
	        min=a[i];
	       if(max<a[i])
	        max=a[i];
	    }
	    int sum[MAX],dp[n];
	    for (int d=(min-max); d<=(max-min); d++)
        {
            memset(sum, 0, sizeof sum);
            for (int i = 0; i < n; i++)
            {
                dp[i] = 1;
                if (a[i] - d >= 1 && a[i] - d <= 1000000)
                    dp[i] += sum[a[i] - d];
                ans += dp[i] - 1;
                sum[a[i]] += dp[i];
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
