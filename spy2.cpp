#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define endl '\n'
#define pb push_back
#define int long long
#define sz(vec) (int)vec.size()
#define fin  freopen("int", "r", stdin)
#define fout freopen("out", "w", stdout)
#define FORr(vec) for(int i = 0; i < sz(vec); i++) cin >> vec[i];
#define FORw(vec) for(int i = 0; i < sz(vec); i++) cout << vec[i] << " \n"[i==sz(vec)-1];
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

/*-------------------------------------------------------------------------------------------*/

struct node{
  unordered_map<char, node*>alf;
  bool leaf, Up;
  
  node(){ leaf=false; Up=false; }
};

class trie{

public:
    node* root;
    vector<string>ans;
    
    trie(){ root = new node; }
    
    void insert(string str){
        bool ok;
        node *aux = root;
        for(char k: str){
            
            ok=false;
            
            if(k <= 'Z'){
                k = tolower(k); 
                ok=true;
            }
            
            if(!aux->alf[k])
                aux->alf[k] = new node;
            
            if(ok) //a letra é maiuscula
                aux->Up = true;
            
            aux = aux->alf[k];
        }
        aux->leaf = true;
    }
    
    void search(string str){
        
        auto go = [&](auto go, int &ind, string build) -> void{
            node *aux = root;
            for( ; ind<sz(str); ind++){
                
                if((aux->alf[ str[ind] ])){//se so tem minuscula
                    build += str[ind];
                    aux = aux->alf[ str[ind] ];
                }
                else{
                    
                    if(aux->leaf) //se é folha
                        break;
                    
                    build += (char)toupper(str[ind]);
                    aux = aux->alf[ (char)toupper(str[ind]) ];
                    
                    /*
                    if(!(aux->alf[ str[ind] ]) && (aux->alf[ (char)toupper(str[ind]) ])){//so tem maiuscula
                        build += str[ (char)toupper(str[ind]) ];
                        aux = aux->alf[ (char)toupper(str[ind]) ];
                    }
                    else{//tem maiuscula e minuscula
                        
                    }
                    */
                }
            }
            ans.pb(build);
        };
        
        int i=0;
        while(i<sz(str)){
            
            /*
            if((root->alf[ str[i] ]) && (root->alf[ (char)toupper(str[i]) ])) //tem com "h" e "H"
                
            else                                                              //se tem palavra que so comeca com um tipo de letra
            */
            
            go(go, i, "");
        }
    }
    
    void decode(string str){
        search(str);
        reverse(ans.begin(), ans.end());
        FORw(ans);
    }
};

signed main(){
    fast;
    
    trie a;
    string text, ss;
    int dicionary, n;
    
    cin>>n;
    cin>>text;
    reverse(text.begin(), text.end());
    
    cin>>dicionary;
    while(dicionary--){
        cin>>ss;
        a.insert(ss);
    }
    cout << endl;
    
    a.decode(text);
}
