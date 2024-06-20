//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

struct tStockPrecio
{
    int stock;
    int precio;
};
bool esValida(const vector<int> &facultades, vector<int> &facultades_actual, vector<tStockPrecio> &proveedores, vector<int> &sol, int k, int demanda_actual,int stock_actual,int precio_actual,int&precio_mejor) {
    if(precio_actual>precio_mejor)
        return false;
    if(demanda_actual>stock_actual)
        return false;

    return true;
}


bool esUltimo(const int &k,const int &m){
    return k+1==m;
}


/*
ÁRBOL DE PROFUNDIDAD n, su primer nodo sólo
*/
void vueltaAtras(vector<int> &facultades, vector<int> &facultades_actual, vector<tStockPrecio> &proveedores, vector<int> &sol, int k, int n, int m,int &demanda_actual,int &stock_actual,int &precio_actual,int&precio_mejor, bool &exito){
    int i=0;
    while(i<n){
        sol[k]=i;
        if(esValida(facultades,facultades_actual,proveedores,sol,k,demanda_actual,stock_actual, precio_actual,precio_mejor)){
            if(demanda_actual==0){
                if(precio_actual<precio_mejor)
                    precio_mejor=precio_actual;
                exito=true;

            }else if(esUltimo(k,m)){
                int cant=min(facultades[i],proveedores[k].stock);
                precio_actual+=cant*proveedores[k].precio;
                demanda_actual-=cant;
                if(demanda_actual==0){
                    exito=true;
                    if(precio_actual<precio_mejor)
                    precio_mejor=precio_actual;
                }
                precio_actual-=cant*proveedores[k].precio;
                demanda_actual+=cant;
            }
            else{
                //marcar
                int cant=min(facultades[i],proveedores[k].stock);
                precio_actual+=cant*proveedores[k].precio;
                demanda_actual-=cant;
                stock_actual-=proveedores[k].stock;
                facultades_actual[i]+=cant;
                facultades[i]-=cant;
                vueltaAtras(facultades,facultades_actual, proveedores, sol, k + 1, n, m,demanda_actual,stock_actual, precio_actual, precio_mejor, exito);
                //desmarcar
                 precio_actual-=cant*proveedores[k].precio;
                demanda_actual+=cant;
                stock_actual+=proveedores[k].stock;
                facultades_actual[i]-=cant;
                facultades[i]+=cant;

            }
        }
        i++;
    }
}


/*
n:facultades
m:proveedores

*/
void resuelveCaso() {
    int n,m;
    cin>>n>>m;
    vector<int>facultades(n);
    vector<int>facultades_actual(n,0);
    vector<int>sol(m);
    vector<tStockPrecio>proveedores(m);
    int demanda_actual=0;
    for (int i = 0; i < n; i++)
    {
        cin >> facultades[i];
        demanda_actual+=facultades[i];
    }
    int stock_actual=0;
    for (int i = 0; i < m; i++)
    {
        cin>>proveedores[i].stock;
        stock_actual+=proveedores[i ].stock;
    }
    for (int i = 0; i < m; i++)
    {
        cin>>proveedores[i].precio;
    }
    
    int precio_mejor=INT_MAX;
    int precio_actual=0;

    bool sePuede=false;
    vueltaAtras(facultades, facultades_actual, proveedores, sol, 0, n, m, demanda_actual,stock_actual,precio_actual, precio_mejor, sePuede);

    if(sePuede)
        cout << precio_mejor << endl;
    else
        cout<<"NO\n";

}
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}