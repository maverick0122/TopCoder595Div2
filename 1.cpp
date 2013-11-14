#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))

class LittleElephantAndBallsAgain
{
	public:
		int getNumber(string S)
		{
			int now=1,ans=1;
			int n = S.length();
			char pre = -1;
			for(int i=0; i<n; i++)
			{
				if(pre!=S[i])
				{
					pre = S[i];
					if(now>ans) ans = now;
					now = 1;
				}
				else
				{
					now++;
				}
			}
			if(now>ans) ans = now;
			return n - ans;
		}	
};

int main()
{
	LittleElephantAndBallsAgain t; 
	cout<<t.getNumber("R")<<endl;
	system("pause");
}
