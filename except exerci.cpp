// 1. Copie o código para a área de resposta.
// 2. Complemente o código declarando atributo da classe.
// 3. Complemente o código implementando método validar.
// 4. Método validar lança exceção se tamanho do valor passado como parâmetro for superior a TAMANHO_MAXIMO.
// 5. Parâmetro quando do lançamento da exceção é "Argumento invalido".
// 6. Complemente o código implementando os métodos set e get .
// 7. Método set armazena valor passado como parâmetro se método validar não lançar exceção.
// 8. Método get retorna valor do atributo da classe.

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#define TAMANHO_MAXIMO 5

class Nome {

     private:

          // Declaração de atributo.
        string nome;
 

        void validar(string);

     public:  

          void set(string);

          string get();

};

// Implementações de métodos.
void Nome :: validar(string nome){
    if(nome.length() > TAMANHO_MAXIMO){
        throw invalid_argument("Argumento invalido");
    }
    this -> nome = nome;
}
void Nome :: set(string nome){
    validar(nome);
}

string Nome :: get(){
    return nome;
}



int main(){

     string dadoA, dadoB;

     cin >> dadoA;

     cin >> dadoB;    

     Nome nome;    

     try{

         nome.set(dadoA);

     }

     catch(invalid_argument &excessao){

         cout << excessao.what();

     }

     try{

         nome.set(dadoB);

     }

     catch(invalid_argument &excessao){

         cout << excessao.what();

     }         

     return 0;

}