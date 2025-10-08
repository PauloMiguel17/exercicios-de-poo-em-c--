#include <iostream>

using namespace std;

// Declarações das classes e implementações dos métodos.
class Elemento{
    private:
        int dado;
        Elemento *ptr_proximo;
    public:
        Elemento(){
            dado = 0;
            ptr_proximo = NULL;
        }
        void setDado(int dado){
            this -> dado = dado;
        }
        int getDado(){
            return dado;
        }
        void setProximo(Elemento* ptr_proximo){
            this -> ptr_proximo = ptr_proximo;
        }
        Elemento* getProximo(){
            return ptr_proximo;
        }

};

class Fila {
private:
    Elemento* ptr_primeiro;
    Elemento* ptr_ultimo;
public:
    Fila() {
        ptr_primeiro = NULL;
        ptr_ultimo = NULL;
    }
    void inserir(Elemento*);
    Elemento* remover();
};

void Fila::inserir(Elemento* novo_elemento) {
    novo_elemento->setProximo(NULL);
    if (ptr_primeiro == NULL) {
        ptr_primeiro = novo_elemento;
        ptr_ultimo = novo_elemento;
    } else {
        ptr_ultimo->setProximo(novo_elemento);
        ptr_ultimo = novo_elemento;
    }
}

Elemento* Fila::remover() {
    if (ptr_primeiro == NULL) {
        return NULL;
    }
    Elemento* elemento_removido = ptr_primeiro;
    ptr_primeiro = ptr_primeiro->getProximo();
    if (ptr_primeiro == NULL) {
        ptr_ultimo = NULL;
    }
    return elemento_removido;
}



int main() {

     Elemento elementoA, elementoB, elementoC;

     int dado;

     cin >> dado;

     elementoA.setDado(dado);

     cin >> dado;

     elementoB.setDado(dado);

     cin >> dado;

     elementoC.setDado(dado);

     Fila fila;

     fila.inserir(&elementoA);

     fila.inserir(&elementoB);

     fila.inserir(&elementoC);

     cout << fila.remover()->getDado();

     cout << fila.remover()->getDado();

     cout << fila.remover()->getDado();

     return 0;

}