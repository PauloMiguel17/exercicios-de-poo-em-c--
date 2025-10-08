#include <iostream>
#include <vector>
using namespace std;

// Classe base
class Funcionario {
protected:
    string nome;
    double salarioBase;
public:
    Funcionario(string n, double s) : nome(n), salarioBase(s) {}

    // Método virtual para sobrescrever nas classes filhas
    virtual double calcularSalario() const {
        return salarioBase;
    }

    virtual void exibirInfo() const {
        cout << "Nome: " << nome 
             << " | Salário: " << calcularSalario() << endl;
    }

    // Sempre bom ter destrutor virtual
    virtual ~Funcionario() {}
};

// Classe derivada: Gerente
class Gerente : public Funcionario {
public:
    Gerente(string n, double s) : Funcionario(n, s) {}
    double calcularSalario() const override {
        return salarioBase * 1.2; // 20% a mais
    }
};

// Classe derivada: Desenvolvedor
class Desenvolvedor : public Funcionario {
public:
    Desenvolvedor(string n, double s) : Funcionario(n, s) {}
    double calcularSalario() const override {
        return salarioBase * 1.1; // 10% a mais
    }
};

// Classe derivada: Estagiário
class Estagiario : public Funcionario {
public:
    Estagiario(string n, double s) : Funcionario(n, s) {}
    double calcularSalario() const override {
        return salarioBase; // sem bônus
    }
};

int main() {
    // Vetor de ponteiros para Funcionario
    vector<Funcionario*> funcionarios;

    funcionarios.push_back(new Gerente("Ana", 5000));
    funcionarios.push_back(new Desenvolvedor("Carlos", 4000));
    funcionarios.push_back(new Estagiario("Bruno", 1500));

    cout << "Lista de Funcionários:\n";
    for (Funcionario* f : funcionarios) {
        f->exibirInfo();
    }

    // Liberar memória
    for (Funcionario* f : funcionarios) {
        delete f;
    }

    return 0;
}
