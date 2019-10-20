#include<bits/stdc++.h>

#define MAX_V 100000 + 4
#define MAX_E 200000 + 4
using namespace std;
struct cell{int x,y,cost;};
int par[MAX_V];
bool used[MAX_V];
cell cs[MAX_E],vs[MAX_V];//保存最小生成树的边

size_t hasher(const cell &c)
{
	return c.x + c.y * c.cost + c.x * c.y;
}
bool eqOp(const cell &a, const cell &b)
{
	return (a.x == b.x) && (a.y == b.y);
}


unordered_map<cell, int, decltype(hasher)*, decltype(eqOp)*> firstTree(1, hasher, eqOp);
unordered_map<cell, int, decltype(hasher)*, decltype(eqOp)*> visited(1, hasher, eqOp);
int E,V;



//不要压缩路径 通过并查集表示生成树
void init(int n){for(int i=0;i<=n;i++) par[i]=i;}
int find(int x){return x==par[x]?x:find(par[x]);}
void unite(int x,int y){par[y]=x;}
bool same(int x,int y){return find(x)==find(y);}

bool cmp(cell a,cell b){return a.cost<b.cost;}
bool operator < (cell a,cell b){return a.cost>b.cost;}
int prim(){
    fill(used,used+V+1,false);
    init(V);
    priority_queue<cell> que;
    que.push({1,1,0});
    int u=0;

    while(!que.empty()){
        cell e=que.top();que.pop();
        int t=e.y;
        if(used[t]) continue;
        used[t]=true;
        unite(e.x,e.y);
        vs[u++]=e;
		if(e.x != e.y)
		{
			//cout << e.x << " " << e.y <<endl;
				visited.insert({e, 1});
				firstTree.insert({e, 1});
		}
        for(int i=0;i<E;i++)//这儿可以用其他数据结构优化
            if(cs[i].x==t&&!used[cs[i].y])
                que.push({t,cs[i].y,cs[i].cost});
    }

    E/=2;
    sort(cs,cs+E,cmp);
    sort(vs,vs+V,cmp);
    int j=0,k=0,N=1;
    while(k<V){
    	for(int j = 0; j < V;)
    	{
    		int va=cs[j].cost,vb=vs[k].cost;
        if(va==vb){
            if(!(cs[j].x==vs[k].x&&cs[j].y==vs[k].y) && !(cs[j].x==vs[k].y&&cs[j].y==vs[k].x)){
                par[vs[k].y]=vs[k].y;//断开
                if(!same(cs[j].x,cs[j].y))
				{
					//cout << cs[j].x << " " << cs[j].y <<endl<<endl;
					//cout << vs[k].x << " " << vs[k].y <<endl<<endl;
					for(auto beg = firstTree.begin(), en = firstTree.end(); beg != en; beg++)
					{
						if(beg->first.x != vs[k].x || beg->first.y != vs[k].y)
						{
							visited[beg->first]++;
							//cout << beg->first.x << " " << beg->first.y <<visited[beg->first] <<endl<<endl;
						}
							
					}
					if(visited.find(cs[j]) == visited.end())
					{
						visited.insert({cs[j], 1});
						//cout << cs[j].x << " " << cs[j].y <<visited[cs[j]] <<endl<<endl;
			 		} 
					else
					{
						
						visited[cs[j]]++;
						//cout <<visited[cs[j]] <<endl<<endl;
						//cout << cs[j].x << " " << cs[j].y <<visited[cs[j]] <<endl<<endl;
			 		} 
					N++;
				 } 
                par[vs[k].y]=vs[k].x;//接上
            }
            j++;
        }else if(va<vb){
            j++;
        }else{
            break;
        }
		}
		k++;

    }
    return N;
}

int main()
{
	//freopen("data.txt", "r", stdin); 
    scanf("%d%d",&V,&E);
        for(int i=0;i<E;i++){
            scanf("%d%d%d",&cs[i].x,&cs[i].y,&cs[i].cost);
            cs[E+i].y=cs[i].x;
            cs[E+i].x=cs[i].y;
            cs[E+i].cost=cs[i].cost;
        }
        E*=2;
        int cnt = prim();
        int ans = 0;
        for(auto beg = visited.begin(), en = visited.end(); beg != en; beg++)
		{
			//cout << beg->first.x << " " << beg->first.y <<" " << beg->second <<endl<<endl;
			if(beg->second == cnt)
			{
				ans++;
			  }  
		}			
        printf("%d\n",ans);
    return 0;
}