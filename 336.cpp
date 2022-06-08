#include <bits/stdc++.h>
            
using namespace std;

int dist[100005];
int cont;

void bfs(int v, int quan, vector<vector<int>>&adj){
    
    queue<int>q;
    q.push(v);
    dist[v]=0;
    
    while(!q.empty()){
        
        int u = q.front();
        q.pop();
        
        for(int k: adj[u]){
            if(dist[k] == -1){
                q.push(k); 
                dist[k] = dist[u] + 1;
                if(dist[k] > quan) cont++;
            }
        }
    }
}

int main(){ 
    
    int e, i, a, b, vert, quant, dale=0;
    
    cin >> e;
    while(e){
		
        vector<vector<int>>adj(100005);
        
        for(i=0; i<e; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> vert >> quant;
        while(vert || quant){
            
            dale++;
            memset(dist, -1, sizeof dist);
            
            cont=0;
            bfs(vert, quant, adj);
            for(i=0; i<adj.size(); i++){
				for(int h: adj[i]){
					if(dist[h] == -1){
						dist[h] = 0;
						cont++;
					}
				}
			}
            cout << "Case " << dale << ": " << cont << " nodes not reachable from node " << vert << " with TTL = " << quant << "." << endl;   
            cin >> vert >> quant;
        }
        cin >> e;
    }
}       
