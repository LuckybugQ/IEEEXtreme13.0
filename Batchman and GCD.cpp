#include<bits/stdc++.h>
using namespace std;

string s;
int maxN = 1e5 + 5;

bool isEven(int x) {
		// 只需要让这个数与1相与即可，因为任何一个数，只要是偶数，那这个数的二进制的第一位，必定是0
		if ((x & 1) == 0) {
			return true;
		} else {
			return false;
		}
	}

/* 迭代法（递推法）：欧几里得算法，计算最大公约数 */  

int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
 
/*int gcd(int x, int y)
{
	int  i, j, t;
	if (x == 0)  
		return  y;
	if (y == 0)  
		return  x;
	for (i = 0; 0 == (x & 1);x >>= 1, ++i);
	for (j = 0; 0 == (y & 1);y >>= 1, ++j);
	if (j < i) 
		i = j;
	for (;;)
	{
		if (x < y) 
			t = y, y = x, x = t;
		if (0 == (x -= y))  
			return  y << i;
		for (;0 == (x & 1);x >>= 1);
	}
}*/

/*int gcd(int x, int y) {
		if (x < y) {
			return gcd(y, x);
		}

		if (y == 0) {
			return x;
		} else {
			if (isEven(x)) {
				if (isEven(y)) {
					return (gcd(x >> 1, y >> 1) << 1);
				} else {
					return gcd(x >> 1, y);
				}
			} else {
				if (isEven(y)) {
					return gcd(x, y >> 1);
				} else {
					return gcd(y, x - y);
				}
			}
		}
	}*/

int main()
{
	//freopen("data.txt", "r", stdin);
	int N, K;
	vector<int> A;
	set<int> GCD;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
	{
	    int a;
	    cin >>a;
		A.push_back(a);
	}
	sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
	for(int i = 0; i < A.size(); i++)
		GCD.insert(A[i]);
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = i + 1; j < A.size(); j++)
		{
		    int g = gcd(A[i], A[j]);
			GCD.insert(g);
		}	
	}
	cout << GCD.size() << endl;
	
	return 0;
}
