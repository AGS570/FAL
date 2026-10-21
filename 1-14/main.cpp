// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//subida(v,p,q) = {0<=p<q <|v|  ^ (Ak : p<k<q ) -> (v[p] < v[p+1] ^ v[k-1] < v[k])}
//valido(v,p,q,d) = {(0<=p<q <|v| )^ d > 0 ^ (Aa,b : p<=a <b<=q: subida(v,a,b))-> b-a <=d}



//P = |datos| > 0 ^ 0 <= p < |datos|
//Q = {(p:0<=p < |datos| ) ^ (a,b: 0<=a <=p ^ p < b < |datos|)-> (Aa,b: datos[a]<datos[b])}
//invariante = 0<=i < |datos| 
// función que resuelve el problema
bool resolver(vector<int> datos,int p) {
    bool res = true;
    if(datos.size()-1==p)return true ;
    
    int max = datos[0],min;
    for(int i =0; i < datos.size();i++){
        if(i <= p){
            if(datos[i] > max)
                max = datos[i];
        }else{
            if(i == p+1){
                min = datos[i];
            }else{
                if(datos[i] < min){
                    min = datos[i];
                }
            }
        }
    }
    if(max >= min) res = false;
    
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int in,tam,pos;
    cin >> tam >>pos;
    for(int i =0; i < tam;i++){
        cin >> in;
        datos.push_back(in);
    }
    
    bool sol = resolver(datos,pos);
    // escribir sol
    if(sol) cout << "SI" <<endl;
    else cout << "NO" << endl;
    
    
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