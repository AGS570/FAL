// Nombre del alumno ..... Alberto
// Usuario del Juez ...... FAL-E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool zona_peligro(vector<int>&v, int a, int b){
    for(int i = a; i < b-1;i++){
        if(v[i] != v[i+1])return false;
    }
    if(v[b-1] <= v[b])return false;
    return true;
}
// función que resuelve el problema
bool resolver(vector<int> &datos,int t) {
    if(datos.size()<=t )return false;

    for(int i =0; i < datos.size()-1;i++){
        if(i+t < datos.size() && zona_peligro(datos,i,i+t))return true;
    }
    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n,t,in;
    vector<int>datos;
    cin >> n >> t;
    if (n ==0 && t==0)
        return false;
    
    for(int i =0; i < n; i++){
        cin >> in;
        datos.push_back(in);
    }
    bool sol = resolver(datos,t);
    
    // escribir sol
    if(sol) cout << "SI"<< endl;
    else cout << "NO" << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
