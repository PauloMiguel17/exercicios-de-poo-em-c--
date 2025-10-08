#include <iostream>
#include <stdexcept>
using namespace std;

class Conta {
private:
    double saldo;
    
public:
    Conta() : saldo(0) {}
    
    void depositar(double valor) {
        if (valor <= 0) {
            throw invalid_argument("Valor deve ser positivo!");
        }
        saldo += valor;
    }
    
    void sacar(double valor) {
        if (valor <= 0) {
            throw invalid_argument("Valor deve ser positivo!");
        }
        if (valor > saldo) {
            throw runtime_error("Saldo insuficiente!");
        }
        saldo -= valor;
    }
    
    double getSaldo() { return saldo; }
};

int main() {
    Conta minhaConta;
    
    try {
        minhaConta.depositar(50);
        cout << "Saldo: " << minhaConta.getSaldo() << endl;
        
        minhaConta.sacar(25);
        cout << "Saldo após saque: " << minhaConta.getSaldo() << endl;
        
        // Isso vai causar erro!
        minhaConta.sacar(100);
    }
    catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    
    return 0;
}