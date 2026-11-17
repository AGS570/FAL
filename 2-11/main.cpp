// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// función que resuelve el problema


int resolverNoFinal(int datos, int m) {
    
    int n = datos/10;
    int mod = datos%10;

   if(datos == 0){
    return 0;
   }

    if(mod >= m){
        int np= resolverNoFinal(n, mod);
        return{np*10+mod};
    }else{
        return{resolverNoFinal(n,m)};
    }
}

int resolverFinal(int datos, int m,int res, int p){

    int n = datos/10;
    int mod = datos%10;

    if(datos == 0){
    return res;
   }

    if(mod >= m){
        return  resolverFinal(n, mod , res+mod*pow(10,p), p+1);;
    }else{
        return{resolverFinal(n,m,res,p)};
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int datos;
    cin >> datos;
    // escribir sol
    
    cout << resolverFinal(datos, datos%10,0, 0) << " " << resolverNoFinal(datos,-1) << endl;
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