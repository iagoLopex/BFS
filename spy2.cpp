#include <bits/stdc++.h>

using namespace std;

template<class ty>
class aluno{

public:
	ty idade, forca;
	string nome;
	
	aluno(){
		idade=forca=0;
		nome="";
	}
	
	bool operator < (aluno & u){
		return forca < u.forca;
	}
	
	aluno operator + (aluno & u){
		aluno k;
		k.nome = nome + u.nome;
		k.idade = idade + u.idade;
		k.forca = forca + u.forca;
		return k;
	}
	
	friend istream & operator >>(istream &in, aluno & u){
		in >> u.nome;
		in >> u.idade;
		in >> u.forca;
		return in;  
	}
	
	friend ostream & operator <<(ostream &saida, aluno & u){
		saida << "Nome: " << u.nome << endl;
		saida << "idade: " << u.idade << endl;
		saida << "forca: " << u.forca << endl;
		return saida;
	}
};

int main(){
	
	aluno<double>a, b, c;
	
	cin>>a;
	cout << a;
	cout << "----------\n";
	cin>>b;
	cout << b;
	cout << "----------\n";
	c = a+b;
	
	cout << c;
	
	cout << (a<b ? "Yes" : "No");
	
}
/************************************************************************/
