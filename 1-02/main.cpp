// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<string> datos, string nat) {
    bool encontrado = false;;
    int res =1;
    for(int i =0; i < datos.size(); i++){
        res++;


        if (datos[i] == nat){
            res = 1;
            encontrado = true;
        }
    }
    if(!encontrado) return 0;
    return res;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anios;
    string nat;
    string in;
    vector<string> v;
    cin >> anios >>nat;
    if (anios == 0)
        return false;
    
    for(int i =0; i < anios; i++){
        cin >> in;
        v.push_back(in);
    }
    int sol = resolver(v,nat);
    
    // escribir sol
    if(sol == 0) cout << "NUNCA";
    else cout << sol;
    cout << endl;
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
