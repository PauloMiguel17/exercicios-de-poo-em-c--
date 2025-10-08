#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veiculo{
    public:
        virtual void som() const = 0;
        virtual ~Veiculo (){}
        
};

class Carro : public Veiculo{
    public:
        void som() const override{
            cout << "vruuuuuuuuuuuuuuuum" << endl;
        }
};

class Moto : public Veiculo{
    public:
        void som() const override{
            cout << "randandadnadnaandanda" << endl; 
        }
};

class Barco : public  Veiculo{
    public:
        void som() const override{
            cout << "shulepshulep" << endl; 
        }
};

int main(){
    vector <Veiculo*> veiculos;

    veiculos.push_back(new Carro());
    veiculos.push_back(new Moto ());
    veiculos.push_back(new Barco());

    for(Veiculo* a : veiculos){
        a -> som();
    }

    for(Veiculo* a: veiculos){
        delete a;
    }

    return 0;
}