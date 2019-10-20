#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 4;

int cmp ( const void *a , const void *b ) 
{ 
	return *(int *)a - *(int *)b; 
}	

int main() {
	//freopen("data.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<int> A;
    vector<int> B;
    for(int i = 0; i < N; i++)
    {
    	int a;
    	cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < M; i++)
    {
    	int b;
    	cin >> b;
    	B.push_back(b);
	}
	sort(B.begin(), B.end());
    /*sort(B, B + M);
    for(int i = 0; i < M; i++)
    	printf("%d ", B[i]);*/
    int n = 0, m = 0;
    for(int i = 0; i < M + N; i++)
    {
        if(A[n] < B[m]) 
        {
            cout << A[n] << " " ;
            n++;
            if(n == N)
            {
            	for(int j = m; j < M; j++)
            		cout << B[j] << " " ;
            	break;
			}
        }
        else
        {
            cout << B[m] << " " ;
            m++;
            if(m == M)
            {
            	for(int j = n; j < N; j++)
            		cout << A[j] << " " ;
            	break;
			}
        }
    }
    cout << endl;
        
    return 0;
}