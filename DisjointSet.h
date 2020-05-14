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
typedef vetor<pair<int, ii> > EdgeList; //Edgelist representation of graphs to store an edge and weights for both directions, i.e., in an undirected graph.x


//								STARTS HERE	

vi p, rank;

CreateSet(int n){
	rank.resize(n);
	p.resize(n);
	loop(i, 0, n){
		p[i]=i;
	}
}

int FindSet(int i){
	return p[i]==i?i:(p[i]=FindSet(p[i]));
}

bool isSameSet(int x, int y){
	return FindSet(x)==FindSet(y);
}

void unionSet(int x, int y){
	if(!isSameSet(x, y)){
		int px=FindSet(x), py=FindSet(y);	//Path Compression.
		if(rank[px]>rank[py])
			p[y]=x;
		else{
			p[x]=y;
			rank[y]=rank[x]==rank[y]?rank[y]+1:rank[y];
		}
	}
}

/*

Path compression in Find_set.

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

*/

int numDisjointSets(){
	int num=0;
	loop(i, 0, p.size()){
		if(p[i]==i)
			++num;
	}
	return num;
}

int sizeOfSet(int i){
	int siz=0;
	int par=FindSet(i);
	loop(j, 0, p.size()){
		if(par==FindSet(j))
			++siz;
	}
	return siz;
}