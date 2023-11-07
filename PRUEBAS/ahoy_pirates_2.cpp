// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

#define N 1000000
#define BARBARY 0
#define BUCCANER 1
#define INV -1
#define NOP 3

int casos = 1;

class SegmentTree {
private:
    vector<int>st, lazy;
    int tam;
    void setLazyUpdate(int vertex, int op) {
        lazy[vertex] = op;

    }
    void pushLazyUpdate(int vertex, int L, int R) {
        if (lazy[vertex] == INV) st[vertex] = (L - R + 1);
        if (lazy[vertex] == BARBARY || lazy[vertex] == BUCCANER) st[vertex] = (R - L + 1) * lazy[vertex];

        if (L != R) {
            int m = (L + R) / 2;
            setLazyUpdate(2 * vertex, lazy[vertex]);
            setLazyUpdate(2 * vertex + 1, lazy[vertex]);
        }

        lazy[vertex] = NOP;
    }
    void updateRange(int vertex, int L, int R, int a, int b, int op) {
        pushLazyUpdate(vertex, L, R);

        if (b < L || R < a) return;

        if (a <= L && R <= b) {
            setLazyUpdate(vertex, op);
            pushLazyUpdate(vertex, L, R);
            return;
        }
        int m = (L + R) / 2;
        updateRange(2 * vertex, L, m, a, b, op);
        updateRange(2 * vertex + 1, m + 1, R, a, b, op);

        st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
    }
    int query(int vertex, int L, int R, int i, int j) {

        pushLazyUpdate(vertex, L, R);

        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return st[vertex];
        int mitad = (L + R) / 2;
        return query(vertex * 2, L, mitad, i, j) + query(vertex * 2 + 1, mitad + 1, R, i, j);
    }

    void build(int* values, int p, int l, int r) {
        if (l == r) {
            st[p] = values[l];
            return;
        }
        int m = (l + r) / 2;
        build(values, 2 * p, l, m);
        build(values, 2 * p + 1, m + 1, r);
        st[p] = st[p * 2] + st[p * 2 + 1];
    }
public:
    SegmentTree(int maxN) : lazy(maxN, NOP) {
        st.reserve(4 * maxN + 10);
    }

    int query(int a, int b) {
        return query(1, 0, tam - 1, a, b);
    }
    void update(int a, int b, int op) {
        updateRange(1, 0, tam - 1, a, b, op);
    }
    void build(int* values, int n) {
        tam = n;
        build(values, 1, 0, n - 1);
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    cout << "Case " << casos << ":\n";

    int m; cin >> m;
    string pirates = "";
    for (int i = 0; i < m; i++) {
        string aux = pirates;
        int t; cin >> t >> aux;
        for (int j = 0; j < t; j++) {
            pirates.append(aux);
        }
    }
    SegmentTree st(N);
    int values[N];
    for (int i = 0; i < pirates.size(); i++) {
        if (pirates.at(i) == '1')
            values[i] = 1;
        else values[i] = 0;
    }
    st.build(values,pirates.size());
    int q, queries = 1; cin >> q;
    for (int i = 0; i < q; i++) {

        char c; int a, b; cin >> c >> a >> b;
        switch (c) {
        case 'F': // to buccaner
            st.update(a, b, BUCCANER);
            break;
        case 'E': // to barbary
            st.update(a, b, BARBARY);
            break;
        case 'I':// to inverse
            st.update(a, b, INV);
            break;
        case 'S':
            cout << "Q" << queries << ": " << st.query(a, b) << "\n";
            // st.query(a, b);
            break;
        }
    }

    casos++;
}

    /*

}
    */

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}