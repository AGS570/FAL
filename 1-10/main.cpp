// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//descenso(t,a,b) = {(Ea,b € t : 0 <= a <=b < |t| ) ^ (Ac € t: a<=c<=b)}
bool descenso(vector<int> &t, int a,int b){
    if(a == b) return true;
    if(t[a] < t[b])return false;
    for(int i =a+1; i<b;i++){
        if(t[i]>=t[a])return false;
    }
    return true;
}

// función que resuelve el problema

//coste O(n)
//P = {0<|datos|}
//Q = {(Ei,j: 0<=i<=j< |datos|) ^ descenso(datos,i,j)) ^ (Ek: k = j - i+1 ) ^ 
//      (Ea,b: 0<=a<=b< |datos| ) descenso(datos,a,b)^ (Ah:h=b-a+1:k>=h) }
//invariante = {0 <= ini < fin <=|datos|} ^ {1<=max<=fin}
int resolver(vector<int> &datos) {
    int ini =0,fin=1;
    int max=1;

    while(fin < datos.size()){
        if(datos[fin] < datos[ini]){ 
            if(fin-ini+1> max){
                max = fin-ini+1;
            }
        }else if(datos[fin] == datos[ini]){
            
            if(fin-ini+1 > max){
                max = fin-ini+1;
            }
            ini = fin;
        }else{
            ini = fin;
        }
        fin++;
    }

    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int num, in;

    cin >> num;
    for(int i =0; i < num;i++){
        cin>>in;
        datos.push_back(in);
    }
    
    int sol = resolver(datos);
    // escribir sol
    
    cout << sol << endl;
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