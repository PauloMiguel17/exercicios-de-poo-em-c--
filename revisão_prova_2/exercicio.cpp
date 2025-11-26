#include <iostream>
#include <stdexcept>

using namespace std;

void verificar(int a){
    if(a > 10 || a < 0){
        throw invalid_argument("numero invalido");
    }
}

int main(){
    int a;

    cout << "digite um numero entre 0 a 10: " << endl;
    cin >> a;

    try{
        verificar(a);
        cout << "numero valido" << endl;
    }
    catch(const invalid_argument& e){
        cerr << "excecao capturada: " << e.what() << endl;
    }
    return 0;
}