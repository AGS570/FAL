// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int buscarIz(vector<int>&datos, int index, int dst){
    if(index >= datos.size()) return -1;
    if(datos[index] == dst)return index;

    return buscarIz(datos,index+1,dst);
}

int buscarDr(vector<int>&datos, int index, int dst){
    if(index < 0) return -1;
    if(datos[index] == dst)return index;

    return buscarDr(datos,index-1,dst);
}



// función que resuelve el problema
vector<int> resolver(vector<int>&datos,int dst) {
    vector<int> res;
    int iz = buscarIz(datos,0,dst);
    int dr;
    if(iz != -1){
        res.push_back(iz);
        dr = buscarDr(datos,datos.size()-1,dst);
        if(dr != iz) res.push_back(dr);
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int>datos;
    int num, dst, in;;
    cin >> num >> dst;
    if (! std::cin)
        return false;
    
        for(int i =0; i < num; i++){
            cin >> in;
            datos.push_back(in);
        }

    vector<int> sol = resolver(datos,dst);
    
    // escribir sol
    
    if(sol.empty())cout << "NO EXISTE";
    else if(sol.size() == 1) cout << sol[0];
    else cout << sol[0] << " " << sol[1];
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