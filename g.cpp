// Problem: G - Longest Path
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Attempted: 2021-08-29 20:02:20 EST

#ifndef LOCAL
#define debug(...) 0
#include <bits/stdc++.h>
#else
#include "C:\programmingfunnyxd\debug.cpp"
#include "C:\programmingfunnyxd\includeordie.h"
#endif
using namespace std;
inline namespace readio { const int BSZ = 1<<15; char ibuf[BSZ]; int ipos, ilen;
char nc() {if (ipos == ilen) {ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);if (!ilen) return EOF;}return ibuf[ipos++];}
template<class T> void ri(T& x) {char ch; int sgn = 1;while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');x *= sgn;}
template<class T> void rc(T& x){ x = nc();while(isspace(x))x = nc();}template<class T, class... Ts> void ri(T& t, Ts&... ts) {ri(t);ri(ts...);}
template<class str>void rs(str& x) { char ch; while (isspace(ch = nc()));do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);}}
template<typename T> void max_self(T& a, T b){a = max(a,b);}template<typename T> void min_self(T& a, T b){a = min(a,b);}
struct minsecond{bool operator()(pair<int,int> a, pair<int,int> b){return a.second > b.second;}};
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;template<typename T> using maxpq = priority_queue<T>;
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, minsecond> secondpq;
typedef long long ll; const ll INF = 1e18; const int MOD = 1e9+7;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define print(x) cout<<x<<"\n"
#define mp(x,y) make_pair(x,y)
#define np(x) next_permutation(all(x))
#define F first
#define S second
#define sz(v) int(v.size())
#define bpop(x) __builtin_popcount(x)
#define fillarr(arr,n,am) fill(arr[0],arr[n],am)
#define fill3d(arr,n,am) fill(arr[0][0],arr[n][0],am)
const int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
int n,m;
vector<int> graph[100002];
int goingto[100002];
int dist[100001];
bool visited[100001];

void dfs(int a){
	visited[a] = true;
	for(int i: graph[a]){
		max_self(dist[i], dist[a]+1);
		goingto[i]--;
		if(goingto[i] == 0){
			dfs(i);
		}
	}
}

void doStuff(){
	ri(n,m);
	for(int i = 0; i < m; i++){
		int a,b; ri(a,b);
		graph[a].pb(b);
		goingto[b]++;
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i] and goingto[i] == 0){
			dfs(i);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		max_self(ans,dist[i]);
	}
	print(ans);
	
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);int t = 1;
	freopen("longpath.in","r",stdin);
	freopen("longpath.out","w",stdout);
	// ri(t);
	while(t--)doStuff();
    #ifdef LOCAL
    cerr << "Runtime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
