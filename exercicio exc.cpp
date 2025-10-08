// 1. Copie o código para a área de resposta.
// 2. Complemente o código declarando e implementando a classe Codigo.
// 3. Classe Codigo armazena valor se o mesmo for menor ou igual a 100.
// 4. Complemente o código declarando e implementando a classe Preco.
// 5. Classe Preco armazena valor se o mesmo for menor ou igual a 200.
// 6. Complemente o código declarando e implementando a classe Pedido.
// 7. Classe Pedido é composta por atributos que são instâncias de Codigo e Preco.

#include <iostream>
#include <stdexcept>

using namespace std;

// Declarações de classes.
class Codigo{
    private:
        int valor;
        static const int LIMITE = 100;

    public:
        Codigo() : valor(0) {}
        void set(int valor);
        int get() const {return this -> valor;}

};

class Preco{
    private:
        int valor;
        static const int LIMITE = 200;
    public:
        Preco() : valor(0) {}
        void set(int valor);
        int get() const {return this -> valor;}
};

class Pedido{
    private:
        Codigo codigo;
        Preco preco;
    public:
        void setCodigo(Codigo codigo) {this -> codigo = codigo;}
        void setPreco(Preco preco) {this -> preco = preco;}
        Codigo getCodigo() const {return codigo;}
        Preco getPreco() const {return preco;}
};


// Implementações de métodos.

void Codigo :: set(int valor){
    if (valor > LIMITE){
        throw invalid_argument("Valor excede o limite do Codigo. ");
    }
    this -> valor = valor;
}
void Preco :: set(int valor){
    if (valor > LIMITE){
        throw invalid_argument("Valor excede o limite do Preco. ");
    }
    this -> valor = valor;
}
// Função main.

int main(){  

    int dadoA, dadoB;

    cin >> dadoA;

    cin >> dadoB;

    Codigo codigo;

    Preco preco;

    try{

        codigo.set(dadoA);

        preco.set(dadoB);

    }

    catch(invalid_argument &excecao){

        cout << "FALHA";

        return 0;

    }

    Pedido pedido;

    pedido.setCodigo(codigo);

    pedido.setPreco(preco);

    cout << pedido.getCodigo().get();

    cout << pedido.getPreco().get();

    return 0;

}