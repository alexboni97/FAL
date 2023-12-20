#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<bool>& joob, const vector<bool>& func, int cont, int i) {
	if (cont > 0) {
		//El trabajo ya esta ocupado
		if (joob[cont]) return false;
		//El funcionario ya tiene trabajo
		if (func[i]) return false;
	}
	return true;
}

void comeSano(const vector<vector<int>>& distancias, const vector<vector<int>>& allegados, const vector<bool>& plazas, const vector<bool>& comensales, int n,int m, int cont, bool exito, vector<int>& sol, const vector<int>& sumasacumuladas) {
	for (int i = 0; i < N; i++) {
		tiempoActual += tiempos[i][cont];
		if (esValida(joob, func, cont, i)) {
			joob[cont] = true;
			func[i] = true;
			if (cont == N - 1) {
				if (tiempoActual < total) total = tiempoActual;
			}
			else {
				if (acumulados[cont + 1] + tiempoActual < total) calcularTiempo(tiempos, N, cont + 1, joob, func, total, tiempoActual, acumulados);
			}
			joob[cont] = false;
			func[i] = false;
		}
		tiempoActual -= tiempos[i][cont];
	}
}

void resuelveCaso() {
	int n, m;
	bool exito=false;
	cin >> n >> m;
	vector<vector<int>> distancias(n, vector<int>(n));
	vector<vector<int>> allegados(m, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> distancias[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> allegados[i][j];
		}
	}
	vector<bool>plazas(n);
	vector<bool>comensales(m);
	vector<int> sol(m);
	vector<int>sumac(m);



	int total = -1;
	int tiempoActual = 0;
	vector<int> minimos(N);
	for (int i = 0; i < N; i++) {
		minimos[i] = tiempos[0][i];
		for (int j = 0; j < N; j++) {
			if (minimos[i] > tiempos[j][i]) minimos[i] = tiempos[j][i];
		}
	}
	vector<int> acumulados(N);
	for (int i = N - 2; i > -1; i--) acumulados[i] = acumulados[i + 1] + minimos[i];
	comeSano(distancias, allegados, plazas, comensales, n, m, 0, exito, sol, sumac);

	if (!exito)cout << "CANCELA";
	else
		cout << "PAREJAS" << total << endl;
	
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	unsigned int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}