#include <iostream>
#include <vector>
using namespace std;

// Classe base abstrata
class Animal {
public:
    // Método virtual puro (torna a classe abstrata)
    virtual void falar() const = 0;

    // Sempre bom ter um destrutor virtual
    virtual ~Animal() {}
};

// Classe derivada Cachorro
class Cachorro : public Animal {
public:
    void falar() const override {
        cout << "Au Au" << endl;
    }
};

// Classe derivada Gato
class Gato : public Animal {
public:
    void falar() const override {
        cout << "Miau" << endl;
    }
};

// Classe derivada Vaca
class Vaca : public Animal {
public:
    void falar() const override {
        cout << "Muuu" << endl;
    }
};

int main() {
    // Vetor de ponteiros para Animal
    vector<Animal*> animais;

    // Criando objetos e armazenando no vetor
    animais.push_back(new Cachorro());
    animais.push_back(new Gato());
    animais.push_back(new Vaca());

    // Todos "falam" com polimorfismo
    for (Animal* a : animais) {
        a->falar(); // Cada classe executa seu próprio método
    }

    // Liberar memória
    for (Animal* a : animais) {
        delete a;
    }

    return 0;
}
