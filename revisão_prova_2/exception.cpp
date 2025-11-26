#include <iostream>
#include <stdexcept> // Necessário para exceções padrão

using namespace std;

float dividir(float a, float b) {
    if (b == 0) {
        // Q5: Lançar exceção
        throw std::invalid_argument("Erro: Divisao por zero!");
    }
    return a / b;
}

int main() {
    try {
        // Tenta executar o código arriscado
        float resultado = dividir(10, 0);
        cout << resultado << std::endl;
    } 
    catch (const std::invalid_argument& e) { 
        // Q6: Capturar exceção
        cerr << "Excecao capturada: " << e.what() << std::endl;
    }
    return 0;
}