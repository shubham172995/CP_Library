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

void buildmin(int p, int l, int r){
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

void updatemin(int p){
	int p1, p2;
	if(left(p)<n)
		p1=st[left(p)];
	else p1=-1;
	if(right(p1)<n)
		p2=st[right(p)];
	else p2=-1;
	if(p1==-1)st[p]=p2;
	if(p2==-1)st[p]=p1;
	if(p1!=-1&&p2!=-1)st[p]=a[p1]<a[p2]?p1:p2;
	if(p!=1)
		updatemin(p/2);
}

void buildsum(int p, int l, int r){
	if(l==r)
		st[p]=a[l];
	else{
		build(left(p), l, (l+r)/2);
		build(right(p), ((l+r)/2)+1, r);
		int p1=st[left(p)], p2=st[right(p)];
		st[p]=p1+p2;
	}
}

int rsq(int p, int l, int r, int i, int j){
	if(i>r||j<l)
		return -1;
	if(l>=i&&r<=j)
		return st[p];
	int p1=rsq(left(p), l, (l+r)/2, i, j);
	int p2=rsq(right(p), ((l+r)/2)+1, r, i, j);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return p1+p2;
}

void updatesum(int p){
	int p1, p2;
	if(left(p)<n)
		p1=st[left(p)];
	else p1=-1;
	if(right(p1)<n)
		p2=st[right(p)];
	else p2=-1;
	if(p1==-1)st[p]=p2;
	if(p2==-1)st[p]=p1;
	if(p1!=-1&&p2!=-1)
	if(p!=-1&&p2!=-1)st[p]=p1+p2;
	if(p>1)
		updatesum(p/2);
}

//Updates with deletions and Insertions.

void update(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}


//Searching for the first element greater than a given amount

int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(t[2*v] > x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}




int main(){
	cin>>n;
	st.resize(4*n);
	loop(i, 0, n){
		cin>>a[i];
	}
	build(1, 0, n-1);
}