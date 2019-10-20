#include<bits/stdc++.h>
using namespace std;

string s;
int maxN = 1e5 + 5;

struct node
{
	int x;
	int h;
	node *left, *right;
	node(int x):x (x), left(nullptr), right(nullptr){}
};

int insert_value(node *cur, node *newv)
{
	if(newv->x <= cur->x)
    {
    	if(cur->left != nullptr) 
    	{
    		insert_value(cur->left, newv);
		}
		else
		{
			cur->left = newv;
			newv->h = cur->h + 1;
		}
	}
    else
    {
    	if(cur->right != nullptr) 
    	{
    		insert_value(cur->right, newv);
		}
		else
		{
			cur->right = newv;
			newv->h = cur->h + 1;
		}
	}
}

        


int main()
{
	//freopen("data.txt", "r", stdin);
	int N;
	cin >> N;
	int tmp;
	
	scanf("%d", &tmp);
	
	node *head = new node(tmp);
	head->h = 1;
	printf("%d ", head->h);
	for(int i = 1; i < N; i++)
	{
		scanf("%d", &tmp);
		node *n = new node(tmp);
		insert_value(head, n);
		printf("%d ", n->h);
	}
	printf("\n");
	
	
	return 0;
}
