#include <bits/stdc++.h>

using namespace std;

int dist[8][8];

int li[]={-2,-1, 1, 2, 2, 1,-1,-2};
int co[]={ 1, 2, 2, 1,-1,-2,-2,-1};

int bfs(int xi, int yi, int f, int t){
	queue<pair<int,int>>u;
	dist[xi][yi]=0;
	u.push({xi, yi});
	while(!u.empty()){
		
		pair<int, int>q = u.front();
		u.pop();
		if(q.first == f && q.second == t) return dist[f][t];
		
		for(int k=0; k<8; k++){
			
			int ax = q.first + li[k];
			int ay = q.second + co[k]; 
			
			if(ax>=0 && ax<8 && ay>=0 && ay<8 && dist[ax][ay]==-1){
				dist[ax][ay] = dist[q.first][q.second] + 1;
				u.push({ax,ay});
				
				for(int g=0; g<8; g++){
					for(int h=0; h<8; h++){
						cout << dist[g][h] << " "; 
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	}
}

int main(){ 
	
	int ix, iy, fx, fy;
	string x, y;
			
	while(cin >> x >> y){
		
		memset(dist, -1, sizeof dist);
		ix=(x[0]-97);
		iy=(x[1]-49);
		
		fx=(y[0]-97);
		fy=(y[1]-49);
		
		cout << "To get from " << x << " to " << y << " takes " << bfs(ix, iy, fx, fy) << " knight moves.\n";
	}				
}			
