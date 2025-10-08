#include <iostream>
#include <cmath> // Necessário para usar a função sqrt()

using namespace std;

class Triangulo{
private:
    double a, b, c;
    double area;
    
public:
    // Construtor (Opcional, mas útil para iniciar os lados)
    Triangulo(double a = 0.0, double b = 0.0, double c = 0.0) : a(a), b(b), c(c) {}
    
    // Métodos SET para definir os lados
    void setA(double a){
        this -> a = a;
    }

    void setB(double b){
        this -> b = b;
    }

    void setC(double c){
        this -> c = c;
    }
    
    // Método GET para a área
    double getArea() const {
        return area;
    }

    // Método para validar se é um triângulo
    bool validar() const {
        // Verifica a Lei da Desigualdade Triangular
        if (((a + b) > c) && ((a + c) > b) && ((c + b) > a)) {
            return true;
        } else {
            return false;
        }
    }

    // Método para calcular a área (usando a Fórmula de Heron)
    void calcularArea() {
        if (!validar()) {
            cout << "Erro: O triângulo com lados (" << a << ", " << b << ", " << c << ") não é válido." << endl;
            this->area = 0.0; // Define a área como zero para triângulos inválidos
            return;
        }

        // 1. Calcular o Semiperímetro (s)
        double s = (a + b + c) / 2.0;

        // 2. Aplicar a Fórmula de Heron
        // Área = sqrt(s * (s - a) * (s - b) * (s - c))
        this->area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    // Método para exibir informações
    void mostrarInformacoes() {
        cout << "\n--- Triângulo ---" << endl;
        cout << "Lados: A=" << a << ", B=" << b << ", C=" << c << endl;
        
        if (validar()) {
            cout << "Status: VÁLIDO" << endl;
            calcularArea(); // Garante que a área seja calculada antes de mostrar
            cout << "Área: " << this->area << " unidades quadradas" << endl;
        } else {
            cout << "Status: INVÁLIDO" << endl;
            cout << "Área: Não calculável" << endl;
        }
    }
};

// --- Função principal para testar a classe ---
int main() {
    // Exemplo 1: Triângulo Válido (3, 4, 5 é um Triângulo Retângulo)
    Triangulo t1;
    t1.setA(3.0);
    t1.setB(4.0);
    t1.setC(5.0);
    t1.mostrarInformacoes(); // Deve retornar Área = 6.0

    // Exemplo 2: Triângulo Inválido
    Triangulo t2;
    t2.setA(2.0);
    t2.setB(3.0);
    t2.setC(6.0);
    t2.mostrarInformacoes(); // Deve retornar INVÁLIDO

    return 0;
}