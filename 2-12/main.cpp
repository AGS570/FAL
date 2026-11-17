// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int,int> resolver(int datos, int g) {
    int n = datos/10;
    int mod = datos%10;
    pair<int,int> result;

    if(n == 0){
        int f=0,s = 1;
       if(mod == g) f = 1;
       if(mod <= g) s = mod;
       return{f,s};   
    }

    result = resolver(n,g);

    if(result.second%10 == mod) result.first ++;
    if(mod <= g){
        return{result.first,result.second*mod};
    }else {
        return result;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int datos, g;
    cin >> datos >> g;
    pair<int,int> sol = resolver(datos,g);
    // escribir sol
    cout << sol.first << endl;
    
}

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