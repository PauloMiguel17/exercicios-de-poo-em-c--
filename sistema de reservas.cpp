#include <iostream>
#include <stdexcept>

using namespace std;

class Reserva{
    private:
        string vet[20];
        int reservar;
    public:
        void inicializarvazio(){
            for(int i = 0; i < 20; i++){
                vet[i] = "O";
            }
        }

        void inserir(int reservar){
            if(vet[reservar] != "O"){
                throw runtime_error("posiçao ja ocupada");
            }
            if(reservar > 20){
                throw invalid_argument("posicao invalida");
            }
            vet[reservar] = "X";
        }

        void exibir(){
            for(int i = 0; i < 20; i++){
                cout << i << "-" << vet[i] << endl; 
            }
        }

        void cancelar(int reserva){
            if(vet[reserva] == "O"){
                throw invalid_argument("Ja esta livre");
            }
            vet[reserva] = "O";
        }
};

int main(){
    Reserva a;

    try{
        a.inicializarvazio();
        a.inserir(9);
        a.exibir();
        a.cancelar(9);
        a.exibir();

    }
    catch(const exception& e){
        cout << "erro: " << e.what() << endl;
    }

    return 0;
}