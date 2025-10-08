#include <iostream>
#include <stdexcept>

using namespace std;

class Dominio{
    private:
        int valor;
    public:
        void validar(int valor);
        int getValor(int valor);
        void setValor(int valor);
};

inline void Dominio :: validar(int valor){
    const int MAX = 50;
    if (valor > MAX){
        throw invalid_argument("valor invalido");
    }
}

inline void Dominio :: setValor(int valor){
    validar(valor);
    this -> valor = valor;
}

inline int Dominio :: getValor(int valor){
    return valor;
}

int main(){
    Dominio dominA;
    int num;

    cout << "digite o numero que deseja verificar: ";
    cin >> num;

    try{
        dominA.validar(num);
        dominA.setValor(num);
        cout << "valor inserido: " << dominA.getValor(num) << endl;
        cout << "numero valido" << endl;
    }
    catch(const exception& e){
        cout << "erro: " << e.what() << endl;
    }

    return 0;
}