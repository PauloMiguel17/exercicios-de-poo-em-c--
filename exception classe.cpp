#include <iostream>
#include <stdexcept>

using namespace std;

class Pessoa{
    private:
        int idade;
        string nome;
    public:
        void inserirIdade(int idade){
            if(idade < 0 || idade > 150){
                throw invalid_argument("idade incompativel com a vida");
            }
            this -> idade = idade;
        }

        void inserirNome(string nome){
            this -> nome = nome;
        }

        void fezaniver(int num){
            if(num <= 0 || num > 150){
                throw invalid_argument("idade incopativel com a vida");
            }
            idade += num;
        }

        string getNome(){
            return nome;
        }

        int getIdade(){
            return idade;
        }
};

int main(){

    Pessoa a;

    try{
        a.inserirNome("miguelo");
        cout << "seu nome eh: " <<  a.getNome() << endl;

        a.inserirIdade(10);
        cout << "sua idade atual eh: " << a.getIdade() << endl;

        a.fezaniver(196);
        cout << "voce fez aniversario iupiiii" <<  endl;
        cout << "sua idade agora eh: " << a.getIdade() << endl;

    }
    catch(const exception& e){
        cout << "erro: " << e.what() << endl;
    }


    return 0;
}