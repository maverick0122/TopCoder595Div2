#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))

class LittleElephantAndIntervalsDiv2
{
	const int maxM = 110; 
	public:
		int getNumber(int M, vector <int> L, vector <int> R)
		{
			int row[maxM];
			memset(row,-1,sizeof(row));
			
			int n = L.size();
			
			for(int i=0; i<n; i++)
			{
				for(int j=L[i]; j<=R[i]; j++)
				{
					row[j] = i;
				}
			}
			set<int> cnt;
			
			for(int i=1; i<=M; i++)
				if(row[i]>=0)
					cnt.insert(row[i]);
			
			int ans = 1;
			for(int i=0; i<cnt.size(); i++)
				ans *= 2;
				
			return ans;
		}	
};

int main()
{
	LittleElephantAndIntervalsDiv2 t; 
	//cout<<t.getNumber(4,{1,2,3},{1,2,3})<<endl;
	system("pause");
}
