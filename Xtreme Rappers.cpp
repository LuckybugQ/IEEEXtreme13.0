#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    long a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a==0 || b==0) cout<<0;
    else if(a==1 && b==1) cout<<0;
    else if(a>=b*2) cout<<b;
    else if(b>=a*2) cout<<a;
    else {
    long count = 0;
	while (a+b>=3 && a>0 && b>0){
		if(a>b) {a-=2; b-=1;count++;
		}
		else{a-=1;b-=2;count++;
		} 
	}
	printf("%d", count);
	}
 
    return 0;
}