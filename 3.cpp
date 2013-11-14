#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

const int maxM = 40;

class LittleElephantAndXor
{ 
	int a[maxM],b[maxM],c[maxM];
	long long dp[maxM][2][2][2];
	 
	public:
		void intToBit(int arr[],int n)
		{
			for(int i=0; n; i++,n>>=1)
			{
				arr[i] = n&1;
			}
		}
		
		long long mypow(long long x,int y)
		{
			long long ans = 1;
			while(y--) ans *= x;
			return ans;
		}
		
		long long fun(int pos,bool ia,bool ib,bool ic)
		{
			//printf("%d %d %d %d\n",pos,ia,ib,ic);
			if(pos < 0) return 1;
			if(dp[pos][ia][ib][ic] >= 0) return dp[pos][ia][ib][ic];
			
			long long ans,two = 2;
			if(ia && ib && ic)
				ans = mypow(two,two*(pos+1));
			else if(ia && ib)
			{
				if(c[pos]) ans = two*(fun(pos-1,1,1,0)+fun(pos-1,1,1,1));
				else ans = two*fun(pos-1,1,1,0);
			}
			else if(ia && ic)
			{
				if(b[pos]) ans = two*(fun(pos-1,1,0,1)+fun(pos-1,1,1,1));
				else ans = two*fun(pos-1,1,0,1);
			}
			else if(ib && ic)
			{
				if(a[pos]) ans = two*(fun(pos-1,0,1,1)+fun(pos-1,1,1,1));
				else ans = two*fun(pos-1,0,1,1);
			}
			else if(ia)
			{
				if(b[pos])
				{
					if(c[pos]) ans = fun(pos-1,1,0,0) + fun(pos-1,1,1,0) + fun(pos-1,1,0,1) + fun(pos-1,1,1,1);
					else ans = fun(pos-1,1,0,0) + fun(pos-1,1,1,0);
				}
				else
				{
					if(c[pos]) ans = fun(pos-1,1,0,0) + fun(pos-1,1,0,1);
					else ans = fun(pos-1,1,0,0);
				}
			}
			else if(ib)
			{
				if(a[pos])
				{
					if(c[pos]) ans = fun(pos-1,0,1,0) + fun(pos-1,1,1,0) + fun(pos-1,0,1,1) + fun(pos-1,1,1,1);
					else ans = fun(pos-1,0,1,0) + fun(pos-1,1,1,0);
				}
				else
				{
					if(c[pos]) ans = fun(pos-1,0,1,0) + fun(pos-1,0,1,1);
					else ans = fun(pos-1,0,1,0);
				}
			}
			else if(ic)
			{
				if(a[pos])
				{
					if(b[pos]) ans = fun(pos-1,0,1,1) + fun(pos-1,1,1,1) + fun(pos-1,1,0,1) + fun(pos-1,0,0,1);
					else ans = fun(pos-1,0,0,1) + fun(pos-1,1,0,1);
				}
				else
				{
					if(b[pos]) ans = fun(pos-1,0,0,1) + fun(pos-1,0,1,1);
					else ans = fun(pos-1,0,0,1);
				}
			}
			else
			{
				if(a[pos])
				{
					if(b[pos])
					{
						if(c[pos]) ans = fun(pos-1,0,0,1) + fun(pos-1,1,1,1) + fun(pos-1,1,0,0) + fun(pos-1,0,1,0);
						else ans = fun(pos-1,0,0,0) + fun(pos-1,1,1,0);
					}
					else
					{
						if(c[pos]) ans = fun(pos-1,1,0,1) + fun(pos-1,0,0,0);
						else ans = fun(pos-1,1,0,0);
					}
				}
				else
				{
					if(b[pos])
					{
						if(c[pos]) ans = fun(pos-1,0,0,0) + fun(pos-1,0,1,1);
						else ans = fun(pos-1,0,1,0);
					}
					else
					{
						if(c[pos]) ans = fun(pos-1,0,0,1);
						else ans = fun(pos-1,0,0,0);
					}
				}
			}
			dp[pos][ia][ib][ic] = ans;
			//printf("%d %d %d %d %lld\n",pos,ia,ib,ic,dp[pos][ia][ib][ic]);
			return dp[pos][ia][ib][ic];
		}
		
		long long getNumber(int A, int B, int C)
		{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
			intToBit(a,A);
			intToBit(b,B);
			intToBit(c,C);
			
			memset(dp,-1,sizeof(dp));
			return fun(maxM-1,0,0,0);
		}
};

int main()
{
	LittleElephantAndXor t; 
	cout<<t.getNumber(5e8,2e8,1)<<endl;
}





