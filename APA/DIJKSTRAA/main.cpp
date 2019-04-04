#include <stdio.h>
#include <vector>
#include <list>
#define inf 10000000
#define ifor(i, b, n) for(int i=b; i<n; ++i)
using namespace std;

int pesos[251][251];
list<int> index;
list<int>::iterator it, aux;

int main(){

	int  v1, v2, n, m, pes, expl, men, fim, ini, cust, vis;

	scanf("%d %d", &n, &m);
	fim = n;
	ini = 0;

	vector<int> adj[n+1];
	int estimativa[n+1];
	bool open[n+1];

	ifor(i, 0, n+1){
		estimativa[i] = inf;
		open[i] = true;
	}

	ifor(i, 0, m){
		scanf("%d %d %d", &v1, &v2, &pes);

		pesos[v1][v2] = pes;
		pesos[v2][v1] = pes;

		adj[v2].push_back(v1);
		adj[v1].push_back(v2);
	}

	estimativa[ini] = 0;
	index.push_back(ini);

	while( !index.empty()){
		men = inf;
		for( it = index.begin(); it != index.end(); ++it){
			vis = (*it);
			if(estimativa[vis] < men){
				men = estimativa[vis];
				expl = vis;
				aux = it;
			}
		}
		index.erase(aux);
		open[expl] = false;

		ifor(i, 0, int(adj[expl].size())){
			vis = adj[expl][i];

			if(open[vis]){
				cust = pesos[expl][vis] + estimativa[expl];

				if(estimativa[vis] == inf){
					estimativa[vis] = cust;
					index.push_back(vis);
				}
				else{
					if(cust < estimativa[vis]){
						estimativa[vis] = cust;
					}
				}
			}
		}
	}

	if(estimativa[fim] == inf){
		printf("----\n");
	}else{
		printf("%d\n", estimativa[fim]);
	}

	index.clear();

}
