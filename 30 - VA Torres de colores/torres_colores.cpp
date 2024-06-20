//ALEX GUILLERMO BONILLA TACO


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=3;

bool esValida(vector<int> &colores,vector<int> &colores_puestos,vector<int> &sol,int k,int n,int m){
    int color = sol[k];
    if (k == 0 && sol[k] != 1)
        return false;
    if (colores_puestos[color] > colores[color])
        return false;
    if (colores_puestos[2] > colores_puestos[0])
        return false;
    if (k != 0 && sol[k - 1] == sol[k] == 2)
        return false;
    return true;
}
bool esFinal(const int &k,const int &m){
    return k+1==m;
}
void mostrarSolucion(const vector<int>&sol,const int &m){
    for (int i = 0; i < m; i++)
    {
        int color=sol[i];
        if(color==0){
            cout<<"azul ";
        }
        else if(color==1){
            cout<<"rojo ";

        }else{
            cout<<"verde ";
        }
    }
    cout<<endl;
    
}
void colocaPieza(vector<int> &colores,vector<int> &colores_puestos,vector<int> &sol,int n,int k, int m,bool&existe){
    int i = 0;

    while (i < n){
        sol[k]=i;
        colores_puestos[i]++;
        if (esValida(colores,colores_puestos, sol,k, n, m)){
            if (esFinal(k, m)){
                if (colores_puestos[1] > colores_puestos[0] + colores_puestos[2])
                {
                    mostrarSolucion(sol, m);
                    existe=true;
                }
            }
            else{
                colocaPieza(colores,colores_puestos, sol, n, k + 1, m,existe);
            }
        }
        colores_puestos[i]--;
        i++;
    }
}
bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int m,a,r,v;
    m=0;
    cin >> m >> a >> r >> v;
    if (m, a, r, v == 0)
        return false;
    vector<int> colores(N);
    colores[0]=a;
    colores[1]=r;
    colores[2]=v;
    vector<int> colores_puestos(N,0);
    vector<int>sol(m,-1);
    int K=0;
    bool existeSolucion=false;
    if (r > 0 && a + r + v >= 2)
        colocaPieza(colores,colores_puestos, sol, N, K, m,existeSolucion);
    if(!existeSolucion)
        cout<<"SIN SOLUCION"<<endl;
                    cout<<endl;

    //Resolver problema
    //Escribir resultado
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}