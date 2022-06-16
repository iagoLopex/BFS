#include <bits/stdc++.h>

using namespace std;

char cube[35][35][35];
int dist[35][35][35];

int o, n, m;

//         fixo z       fixo y      fixo x 
int dx[]={0,1, 0,-1,  0,1, 0,-1,  0,0, 0, 0};
int dy[]={1,0,-1, 0,  0,0, 0, 0,  0,1, 0,-1};
int dz[]={0,0, 0, 0,  1,0,-1, 0,  1,0,-1, 0};

void bfs3D(int az, int ax, int ay){
	
	queue<pair<int,pair<int,int>>>ilusion;
	ilusion.push({az,{ax,ay}});
	
	dist[az][ax][ay] = 0;
	
	while(!ilusion.empty()){
		
		pair<int,pair<int,int>>u = ilusion.front();
		ilusion.pop();
		
		for(int w=0; w<12; w++){
			
			int bz = u.first + dz[w];    
			int bx = u.second.first + dx[w];
			int by = u.second.second + dy[w];
			
			if((bx>=0 && bx<n) && (by>=0 && by<m) && (bz>=0 && bz<o) && cube[bz][bx][by] != '#' && dist[bz][bx][by] == -1){
				cube[bz][bx][by] = '#';
				dist[bz][bx][by] =  dist[u.first][u.second.first][u.second.second] + 1;
				ilusion.push({bz,{bx,by}});
			}
		}
	}
}

int main(){
	
	int k, i, j, mex, mey, mez, toz, tox, toy;
	string lix;
	
	cin >> o >> n >> m;
	while(o || n || m){
		
		memset(dist, -1, sizeof dist);

		//leitura de cada folha
		for(k=0; k<o; k++){
			for(i=0; i<n; i++){
				for(j=0; j<m; j++){
					cin >> cube[k][i][j];
					if(cube[k][i][j] == 'S'){ mez=k; mex=i; mey=j; }
					if(cube[k][i][j] == 'E'){ toz=k; tox=i; toy=j; }
				}
			}
			getline(cin, lix);
		}
		bfs3D(mez, mex, mey);
		if(dist[toz][tox][toy] == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << dist[toz][tox][toy] << " minute(s).\n"; 

		cin >> o >> n >> m;
	}
}
