#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;
struct Edge{
		int a;
		int b;
		int w;
		
}edges[100001];
struct Node{
		int id;
		set<int> neighbours;
}nodes[100001];
int DFS(int n,int count,vector<bool> &visited){
	visited[n] = true;
	count++;
	set<int> s = nodes[n].neighbours;
	set<int>::iterator it;
	for(it=s.begin();it!=s.end ();it++){
		int t = *it;
		if(!visited[t]) {
			count = DFS(t, count,visited);
		}
	}
	return count;	
}

bool cmp(Edge a, Edge b)
{
	return a.w > b.w;
}
int main()
{
    int n;
    scanf("%d",&n);
	for(int i=0;i<n-1;i++) {
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		edges[i].a = a;
		edges[i].b = b;
		edges[i].w = w; 
		nodes[a].neighbours.insert(b);
		nodes[b].neighbours.insert(a);
	}
	long long ans = 0;
	long long count = 0;
	sort(edges,edges + n,cmp);
	for(int i=0;i<n-1;i++) {
		Edge e = edges[i];
		nodes[e.a].neighbours.erase(e.b);
		nodes[e.b].neighbours.erase(e.a);
		
		vector<bool> visited(n,0);
		int n1 = DFS(e.a,0,visited);
		int n2 = DFS(e.b,0,visited);
		ans += (((n1*n2)%MOD)*e.w) % MOD;
		ans = ans % MOD;
	}
	cout<<ans;
    return 0;
}