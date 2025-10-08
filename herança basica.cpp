#include <iostream>
#include <string>
using namespace std;

// Classe base (pai)
class Animal {
protected:
    string nome;
    int idade;
    
public:
    Animal(string n, int i) : nome(n), idade(i) {}
    
    void comer() {
        cout << nome << " está comendo." << endl;
    }
    
    void dormir() {
        cout << nome << " está dormindo." << endl;
    }
};

// Classe derivada (filha) - herda de Animal
class Cachorro : public Animal {
    private:
        string raca;
    
    public:
        // Construtor: chama o construtor da classe base
        Cachorro(string n, int i, string r) : Animal(n, i), raca(r) {}
    
        void latir() {
        cout << nome << " (raça: " << raca << ") está latindo: Au Au!" << endl;
        }
    
        void mostrarInfo() {
        cout << "Cachorro: " << nome << ", Idade: " << idade 
             << ", Raça: " << raca << endl;
        }
};

class Gato : public Animal{
    private:
        string raca;
    public:
        Gato(string n, int i, string r) : Animal(n, i), raca(r){}

        void mostrarInfo() {
            cout << "Gato: " << nome << ", Idade: " << idade << ", Raça: " << raca << endl;
    }
};

int main() {
    // Criando objeto da classe derivada
    Cachorro meuCao("Rex", 3, "Labrador");
    Gato meugato("mamis", 3, "srd");
    
    // Métodos herdados da classe base
    meuCao.comer();
    meuCao.dormir();
    
    // Métodos específicos da classe derivada
    meuCao.latir();
    meuCao.mostrarInfo();
    meugato.mostrarInfo();
    
    return 0;
}