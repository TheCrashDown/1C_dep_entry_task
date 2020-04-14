#include <iostream>
#include <vector>

struct pair{
	int a = 0;
	int b = 0;
};

int main(){

	int n, m;
	std::cin >> n >> m;
	
	std::vector< std::vector< int > > A(n);
	for(int i = 0; i < n; ++i){
		A[i].resize(m);
	}


	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> A[i][j];
		}
	}

	std::vector< std::vector< pair > > p;
	p.resize(n);
	
	for(int i = 0; i < n; ++i){
		p[i].resize(m);
	}

	for(int i = 0; i < n; ++i){
		p[i][0].a = 0;
	}

	for(int i = 0; i < m; ++i){
		p[0][i].b = 0;
	}



	for(int i = 1; i < n; ++i){
		for(int j = 1; j < m; ++j){
			int u = p[i - 1][j - 1].a;
			int v = p[i - 1][j - 1].b;

			while(v > 0 && u > 0 && A[i][j] != A[p[v - 1][u].a + 1][p[v][u - 1].b + 1]){
				/* ВОТ ТУТ надо делать что-то умнее, такие наивные прыжки не прокатили. Вычитать сразу из обоих, как тут -
				*  плохо, так как какие-то варианты упускаются. Надо как-то попробовать вычесть из одного не трогая другой
				*  и наоборот, но как сделать это не теряя асимптотику - не придумал.
				*/
				v = p[v - 1][u].a;
				u = p[v][u - 1].b;
			}
			if(A[i][j] == A[p[v][u].a][p[v][u].b]){
				++v;
				++u;
			}
			p[i][j].a = v;
			p[i][j].b = u;
		}
	}

	for(int j = 0; j < m; ++j){
		for(int i = 0; i < n; ++i){
			std::cout << p[i][j].a << "," << p[i][j].b << "   ";
		}
		std::cout << "\n";
	}






}