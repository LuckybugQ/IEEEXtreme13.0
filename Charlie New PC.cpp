#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2 * 1e9;
const int INF = 1000000000;
typedef long long ll;

int maxC;
int B, N;
int K[10 + 2];
int Ki[10 + 2][100 + 2];

void dfs(int cur,int C)
{
	if(cur == N - 1)
	{
		for(int i = 0; i < K[cur]; i++)
		{
			int tmpc = C + Ki[cur][i];
			//cout << tmpc <<endl;
			if(tmpc > maxC && tmpc <= B) maxC = tmpc;
		}
		return;
	}
	for(int i = 0; i < K[cur]; i++)
	{	
		dfs(cur + 1, C + Ki[cur][i]);
	}
}

int main() {
    //freopen("data.txt", "r", stdin);
    int T;
    cin >> T;
	while(T--)
	{
		maxC = 0;
		cin >> B >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> K[i];
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < K[i]; j++)
			{
				cin >> Ki[i][j];
			}
		}
		dfs(0, 0);
		cout << maxC << endl;
	}
	
    
    return 0;
}


