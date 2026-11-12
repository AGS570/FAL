// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// P = {|datos| > 0 ^ t >= 0}
// Q = {(Ei,j | 0 <= i <= j < |datos|) ^ (Ek[i,j]|(Ah|i<=h<=j|datos[h]>t)) ^
//                                      (Aa,b | 0<=a <=b < |datos|) ^ (Ac[a,b] | (Af|a<=f<=b"datos[f]>t)) ^ (j-i+1 >= b-a+1)}
pair<int,int> resolver(vector<int> & datos, int t) {
    int ini, fin;
    ini =0;
    fin =0;
    int longitud = 0, max =0;
    pair<int,int> res ={0,0};
    //invariante = {0 <=ini <=fin<=|datos| ^ longitud = fin = ini}
    while(fin < datos.size()){
        if(datos[fin] > t){
            longitud++;
            fin++;
            if(longitud > max){
                res.first = ini;
                res.second = fin-1;
                max = longitud;
            }
        }else{
            fin++;
            ini = fin;
            longitud = 0;
        }
    }
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t, in;;
    vector<int> v;

    cin >> n >> t;
    for(int i =0; i < n; i++){
        cin >> in;
        v.push_back(in);
    }
    
    pair<int,int> sol = resolver(v,t);
    // escribir sol
    cout << sol.first << " " << sol.second << endl;
    
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