#include <iostream>
#include <cmath>

class Circulo {
private:
    double raio;

public:
    // Construtor
    Circulo(double r = 0.0) {
        if (r < 0) {
            throw std::invalid_argument("Raio não pode ser negativo");
        }
        raio = r;
    }

    // Método para calcular a área
    double calcularArea() const {
        return M_PI * raio * raio;
    }

    // Método para calcular o perímetro (circunferência)
    double calcularPerimetro() const {
        return 2 * M_PI * raio;
    }

    // Getter para o raio
    double getRaio() const {
        return raio;
    }

    // Setter para o raio com validação
    void setRaio(double r) {
        if (r < 0) {
            throw std::invalid_argument("Raio não pode ser negativo");
        }
        raio = r;
    }

    // Método para exibir informações do círculo
    void exibirInfo() const {
        std::cout << "Círculo de raio: " << raio << std::endl;
        std::cout << "Área: " << calcularArea() << std::endl;
        std::cout << "Perímetro: " << calcularPerimetro() << std::endl;
    }
};

// Exemplo de uso
int main() {
    try {
        // Criando um círculo com raio 5
        Circulo c1(5.0);
        
        std::cout << "=== Círculo 1 ===" << std::endl;
        c1.exibirInfo();
        
        std::cout << "\n=== Círculo 2 ===" << std::endl;
        // Criando outro círculo
        Circulo c2(3.5);
        c2.exibirInfo();
        
        std::cout << "\n=== Modificando o raio ===" << std::endl;
        c2.setRaio(7.0);
        c2.exibirInfo();
        
        // Isso vai lançar uma exceção
        // Circulo c3(-2.0);
        
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
    
    return 0;
}