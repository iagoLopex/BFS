#include <bits/stdc++.h>

using namespace std;

int color[300];
bool vis[300];

vector<vector<int>>adj(300);

void bfs(int v){
	
	queue<int>q;
	q.push(v);
	color[v] = 1;
	bool x;
	
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		vis[u] = true;
		
		(color[u] == 1 ? x=true : x=false);
		
		for(int a : adj[u]){
			if(!vis[a]){
				if(x){// o q eu to agora eh 1
					color[a] = 2;
					q.push(a);
				}
				else{
					color[a] = 1;
					q.push(a);
				}
			}
		}
	}
}

bool volta(int v){
	
	queue<int>q;
	q.push(v);
	color[v] = 1;
	
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		vis[u] = true;
		
		int aux = color[u];
		
		for(int a : adj[u]){
			
			if(!vis[a]){
				q.push(a);
			}
			
			if(aux == color[a]){// se o adjacente for igual eh falso
				return false;
			}
		}
	}
	return true;
}

int main(){
	
	int n, e, a, b;
	cin >> n;
	while(n){
		
		cin >> e;
		adj = vector<vector<int>>(n+1);
		
		memset(color, -1, sizeof color);
		memset(vis, false, sizeof vis);
		for(int i=0; i<e; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bfs(0);
		memset(vis, false, sizeof vis);
		cout << (volta(0) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
		cin >> n;
	}
}
