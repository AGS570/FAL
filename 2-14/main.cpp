// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &datos, int index, int min) {
    
    if(index >= datos.size()) return min;

    if(datos[index] < min) min = datos[index];

    return resolver(datos,index +1, min);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int n, in;

    cin >> n;
    if (! std::cin)
        return false;
    
        for(int i =0; i < n; i++){
            cin>> in;
            v.push_back(in);
        }

    int sol = resolver(v,0,v[0]);
    
    // escribir sol
    
    cout << sol << endl;
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