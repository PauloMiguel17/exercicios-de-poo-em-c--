#include <iostream>
#include <stdexcept>

using namespace std;

int par(int a){
    if(a%2 != 0){
        throw invalid_argument("numero impar");
    }
    return(a);
}


int main(){
    int a;

    cout << "programa de numeros pares, digite um numero: " << endl;
    cin >> a;

    try{
        par(a);
        cout << "numero par" << endl;
    }
    catch(const invalid_argument& e){
        cerr << "Excecao capturada: " << e.what() << endl;
    }

    return 0;
}