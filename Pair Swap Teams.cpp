#include<bits/stdc++.h>
using namespace std;

string s;
int maxN = 1e5 + 5;
int visited[4 + 1]= {0};
int cnt[4 + 1]= {0};
int len;

int dfs(int n, int offset)
{
	visited[n] = 1;
	int ans = 0;
	//if(!cnt[n]) return ans;
	for(int i = 0; i < cnt[n]; i++)
		if(s[(offset + i) % len] != 'A' + n) ans++;
	int minC = maxN;
	int flag = 0;
	
	for(int i = 0; i < 4; i++)
	{
		
		if(!visited[i])
		{	
			//cout << n << endl;
			//cout << i << endl;
			//if(n == 2) cout << dfs(i, (offset + cnt[n]) % len)<<endl;
			minC = min(dfs(i, (offset + cnt[n]) % len), minC);
			visited[i] = 0;	
			//cout <<endl;
			flag = 1;
		} 
	}
	//if(!flag) cout << 1 ;
	return flag ?  ans + minC : ans;
}

int main()
{
	//freopen("data.txt", "r", stdin);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		len = s.size();
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < len; i++)
		{
			cnt[s[i] - 'A']++;
		}
		int ans = maxN;
		//cout << dfs(2, 0) <<endl;
		for(int offset = 0; offset < len; offset++)
		{
			memset(visited, 0, sizeof(visited));
			ans = min(ans, dfs(0, offset));
			//cout << ans <<endl;
		}
		cout << ans / 2 << endl;
	}
	return 0;
}
