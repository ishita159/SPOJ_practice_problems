#include<iostream>

#define MAX 262145

using namespace std;

typedef long long LL;
LL n,m;
struct tree{
LL add;
LL total;
}T[MAX];

void update(LL Node,LL left,LL right,LL i,LL j,LL v){
    if(left > j || right < i) return;
	if(left >= i && right <= j){
	    if(left != right){
            LL L = Node<<1 , R = L+1;
            T[L].add += v;
            T[R].add += v;
	    }

		T[Node].total += (right-left+1)*v;
		return;
	}

	LL mid=(left + right)>>1, L = Node<<1 , R = L+1;
    update(L,left,mid,i,j,v);
    update(R,mid+1,right,i,j,v);
	T[Node].total += v*(min(right, j)-max(left, i)+1);
}

LL query(LL Node,LL left,LL right,LL i,LL j){
    if(left > j || right < i) return 0;

    if(T[Node].add > 0){
        if(left != right){
            LL L = Node<<1 , R = L+1;
            T[L].add += T[Node].add;
            T[R].add += T[Node].add;
	    }

        T[Node].total += T[Node].add*(right-left+1);
        T[Node].add = 0;
    }

    if(left >= i && right <= j)return T[Node].total;

    LL mid = (right+left)/2, L = Node<<1 , R = L+1;
    LL ret =0;
    ret+= query(L,left,mid,i,j);
    ret+= query(R,mid+1,right,i,j);
    return ret;
}

int main(){
LL t;
cin >> t;
while(t--){
cin >> n >> m;
	for(LL i=0;i<MAX;i++)
		T[i].total = T[i].add = 0;
while(m--){
	LL q,a,b,k;
	cin >> q >> a >> b;
		switch(q){
			case 0:cin >> k;
				update(1,1,MAX/2,a,b,k);break;
			case 1:cout << query(1,1,MAX/2,a,b) << endl;break;
		}
}
}
return 0;
}