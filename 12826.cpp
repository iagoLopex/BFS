#include <bits/stdc++.h>
            
using namespace std;

int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

int dist[10][10];

void bfs(int x, int y){
	
	queue<pair<int,int>>q;
	q.push({x,y});
	dist[x][y] = 0;
	
	while(!q.empty()){
		
		pair<int,int>u; 
		u=q.front(); q.pop();
		
		for(int k=0; k<8; k++){
			
			int ax = u.first + dx[k];
			int ay = u.second + dy[k];
			
			if(ax>=0 && ax<8 && ay>=0 && ay<8 && dist[ax][ay] == -1 && dist[ax][ay]!=-2){
				q.push({ax,ay});
				dist[ax][ay] = dist[u.first][u.second] + 1;
			}
		}
	}
}

int main(){
	
	int mex, mey, tox, toy, nox, noy, go=0;
	while(cin >> mex >> mey >> tox >> toy >> nox >> noy){
		
		go++;
		memset(dist, -1,sizeof dist);
		dist[nox-1][noy-1]=-2;
		mex--; mey--;
		bfs(mex, mey);

		cout << "Case " << go << ": " << dist[tox-1][toy-1] << endl; 
	}
}       
