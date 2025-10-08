#include <iostream>
#include <string>
using namespace std;

// Classe base
class Veiculo {
protected:
    string marca;
    string modelo;
    int ano;
    
public:
    Veiculo(string m, string mod, int a) : marca(m), modelo(mod), ano(a) {}
    
    virtual void exibirInfo() {
        cout << marca << " " << modelo << " (" << ano << ")" << endl;
    }
    
    virtual ~Veiculo() {} // Destruidor virtual
};

// Classe Carro
class Carro : public Veiculo {
private:
    int portas;
    
public:
    Carro(string m, string mod, int a, int p) 
        : Veiculo(m, mod, a), portas(p) {}
    
    void exibirInfo() override {
        cout << "Carro: " << marca << " " << modelo << " (" << ano   << ") - " << portas << " portas" << endl;
    }
};

// Classe Moto
class Moto : public Veiculo {
private:
    int cilindradas;
    
public:
    Moto(string m, string mod, int a, int cil) 
        : Veiculo(m, mod, a), cilindradas(cil) {}
    
    void exibirInfo() override {
        cout << "Moto: " << marca << " " << modelo << " (" << ano << ") - " << cilindradas << "cc" << endl;
    }
};

// Classe Caminhao
class Caminhao : public Veiculo {
private:
    double capacidade_carga; // em toneladas
    
public:
    Caminhao(string m, string mod, int a, double carga) 
        : Veiculo(m, mod, a), capacidade_carga(carga) {}
    
    void exibirInfo() override {
        cout << "Caminhão: " << marca << " " << modelo << " (" << ano  << ") - " << capacidade_carga << " toneladas" << endl;
    }
};

int main() {
    // Testando as classes
    Carro carro1("Toyota", "Corolla", 2022, 4);
    Moto moto1("Honda", "CB 500", 2021, 500);
    Caminhao caminhao1("Volvo", "FH", 2020, 15.5);
    
    cout << "=== Sistema de Veículos ===" << endl;
    carro1.exibirInfo();
    moto1.exibirInfo();
    caminhao1.exibirInfo();
    
    // Testando polimorfismo com ponteiros
    cout << "\n=== Polimorfismo ===" << endl;
    Veiculo* veiculos[3];
    
    veiculos[0] = new Carro("Fiat", "Uno", 2019, 2);
    veiculos[1] = new Moto("Yamaha", "MT-07", 2023, 689);
    veiculos[2] = new Caminhao("Scania", "R450", 2021, 20.0);
    
    for (int i = 0; i < 3; i++) {
        veiculos[i]->exibirInfo();
    }
    
    // Liberando memória
    for (int i = 0; i < 3; i++) {
        delete veiculos[i];
    }
    
    return 0;
}