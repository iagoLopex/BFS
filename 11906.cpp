#include <bits/stdc++.h>
        
using namespace std;
        
int n, m, par, impar, cont;
vector<int>dx, dy;

int vis[105][105];
bool vis2[105][105];

void bfs(int ax, int ay){
    
    queue<pair<int, int>>q;
    q.push({ax, ay});
    
    vis[ax][ay] = true;
    
    par=0;
    impar=0;
    
    while(!q.empty()){
        
        pair<int, int>u = q.front();
        q.pop();
    
        cont=0;
        
        //reseto a matriz para verificar a proxima casa
        memset(vis2, false, sizeof vis2);
        for(int k=0; k<8; k++){
            
            int bx = u.first + dx[k];
            int by = u.second + dy[k];
      
      //diferente de vis2 pra dar push nas casas de alcance
      //diferente de 2 para evitar o rio
            if(bx>=0 && bx<n && by>=0 && by<m && !vis2[bx][by] && vis[bx][by] != 2){
                cont++;
                
                //so dou push na casa que eu ainda nao verifiquei
                if(!vis[bx][by])
                {
                    q.push({bx, by});
                    vis[bx][by] = 1;
                }
                
                vis2[bx][by] = true;
            }
        }
    
        //contagem de pares e impares para impressao 
        (cont%2 ? impar++ : par++);
    }
}
        
int main(){
        
    int o, hi, hj, i, no, a, b, dale=0;    
    
    cin >> o;
    while(o--){
        
        dale++;
        memset(vis, 0, sizeof vis);
        cin >> n >> m; 
        
        cin >> hi >> hj;
        
        cin >> no;
        for(i=0; i<no; i++){
            
            cin >> a >> b;
      //2 significa agua que ele nao pode ir nem comecar daquele lugar
            vis[a][b] = 2;
        }
        
        dx = {-hi,-hj, hj, hi, hi, hj,-hj,-hi};
        dy = { hj, hi, hi, hj,-hj,-hi,-hi,-hj};
        
        bfs(0, 0);
        cout << "Case " << dale << ": " << par << " " << impar << endl;
    }
}
