#include <bits/stdc++.h>

using namespace std;

int n, m, lastx, lasty;
bool venceu, ok;

char mat[1005][1005];
int dist[1005][1005];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

//vou mandar para a funcao os contadores recursivamente ate que o J nao consiga mais andar
void maze(int countP, int countF, queue<pair<int,int>>&fire, queue<pair<int,int>>&play){
	
	//quem anda primeiro é o fogo
	int auxF = countF;
	countF=0;
	//o for so vai ate a contagem de fogos inseridos na rodada anterior
	for(int i=0; i<auxF; i++){
		
		pair<int,int>u = fire.front();
		fire.pop();
		
		for(int k=0; k<4; k++){
			
			int bx = u.first + dx[k];
			int by = u.second + dy[k];
			
			if(bx>=0 && bx<n && by>=0 && by<m && mat[bx][by] == '.'){
				mat[bx][by] = 'F';
        //coloco na fila do fogo para a proxima rodada
				fire.push({bx,by});
        //conto o numero de vezes que terei que andar na proxima rodada
				countF++;
			}
		}
	}
	
	//quem anda depois é o player
	int auxP = countP;
	countP=0;
	//o for so vai ate a contagem de players inseridos na rodada anterior
	for(int i=0; i<auxP; i++){
		
		pair<int,int>u = play.front();
		play.pop();
		
		for(int k=0; k<4; k++){
			
			int bx = u.first + dx[k];
			int by = u.second + dy[k];
			
			if(bx>=0 && bx<n && by>=0 && by<m && mat[bx][by] == '.' && dist[bx][by] == -1){
				mat[bx][by] = 'J';
				dist[bx][by] = dist[u.first][u.second] + 1;
        
        //coloco na fila do jogador para a proxima rodada
				play.push({bx,by});
				//conto o numero de vezes que terei que andar na proxima rodada
        countP++;
			}
			
			//ele saiu do labirinto
			if((bx<0 || bx>=n || by<0 || by>=m) && !ok){
				
				//armazeno o lugar que ele consegue sair
				lastx = u.first;
				lasty = u.second;
				
				//o jogador consegue sair do labirinto
				venceu = true;
				
				//guardar a primeira saida do jogador da matriz e evitar que ele pegue um caminho maior
				ok=true;
			}
		}
	}
	
	//tipo de return modify :D
	if(venceu){
		
	}
	else{
		if(countP){
			maze(countP, countF, fire, play);
		}
	}
}

int main(){
	
	int o, i, j, countF, countP;
	cin>>o;
	while(o--){
		
		queue<pair<int,int>>fire,play;
		memset(dist, -1, sizeof dist);
		venceu=false;
		ok=false;
		countF=0, countP=0;
		
		cin >> n >> m;
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				cin >> mat[i][j];
				
				if(mat[i][j] == 'J'){ play.push({i,j}); countP++; } 
				if(mat[i][j] == 'F'){ fire.push({i, j}); countF++; }
			}
		}
		dist[play.front().first][play.front().second] = 0;
		maze(countP, countF, fire, play);
		
		//cout << ((venceu) ? dist[lastx][lasty]+1 : "IMPOSSIBLE") << endl;
		if(venceu) cout << dist[lastx][lasty]+1 << endl;
		else cout << "IMPOSSIBLE\n";
	}
}
