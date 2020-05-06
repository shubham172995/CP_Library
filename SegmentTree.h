#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ll, ll> llll;
typedef vector<llll> vll;
typedef vector<pair<int, ii> > EdgeList; //Edgelist representation of graphs to store an edge and weights for both directions, i.e., in an undirected graph.x

vi st, a;
int n;

int left(int p){
	return p<<1;
}

int right(int p){
	return (p<<1)+1;
}

void build(int p, int l, int r){
	if(l==r)
		st[p]=l;
	else{
		build(left(p), l, (l+r)/2);
		build(right(p), ((l+r)/2)+1, r);
		int p1=st[left(p)], p2=st[right(p)];
		st[p]=a[p1]<a[p2]?p1:p2;
	}
}

int rmq(int p, int l, int r, int i, int j){
	if(i>r||j<l)
		return -1;
	if(l>=i&&r<=j)
		return st[p];
	int p1=rmq(left(p), l, (l+r)/2, i, j);
	int p2=rmq(right(p), ((l+r)/2)+1, r, i, j);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return a[p1]<a[p2]?p1:p2;
}

int main(){
	cin>>n;
	st.resize(4*n);
	loop(i, 0, n){
		cin>>a[i];
	}
	build(1, 0, n-1);
}