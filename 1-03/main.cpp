// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


bool asciende(int i1,int i2){
    if(i1 < i2) return true;
    return false;
}

bool sePasa(int i1, int i2, int limit){
    if((i2-i1) > limit)return true;
    return false;
}
// función que resuelve el problema
bool resolver(int limit,vector<int>v) {
    vector<int> tramo;
    int ini = v[0];
    int fin;
    for(int i=0; i < v.size();i++){
        if(i+1<v.size()){
            fin = v[i+1];
            if(asciende(v[i],v[i+1])){
                if(sePasa(ini,fin,limit))return false;
            }else{
                ini = v[i];

            }
        } 
    }
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int limit;
    int num,in;
    vector<int> v;
    cin >> limit;
    if (! std::cin)
        return false;

    cin >> num;

    for(int i =0; i < num;i++){
        cin >> in;
        v.push_back(in);
    }
    
    bool sol = resolver(limit,v);
    
    // escribir sol
    if (sol)cout<< "APTA";
    else cout << "NO APTA";
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