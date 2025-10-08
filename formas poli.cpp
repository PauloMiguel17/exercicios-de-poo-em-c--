#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Forma{
    public:
        virtual double calcularArea() const = 0;

        virtual ~Forma(){}

        virtual void exibir () const{
            cout << "area do: " << calcularArea() << endl;
        }
};

class Quadrado : public Forma{
    private:
        double lado;
    public:
        Quadrado(double l) : lado(l){}

        virtual double calcularArea() const override{
            return lado * lado;
        }

        virtual void exibir()  const override{
            cout << "Area do quadrado: " <<   calcularArea() << endl;
        }
};


int main(){
    
    vector <Forma*> formas;

    formas.push_back(new Quadrado(6.56));
    formas.push_back(new Quadrado(85.56));
    formas.push_back(new Quadrado(42.56));

    for(Forma* f : formas){
        f -> exibir();
    }

    for(Forma* f : formas){
        delete f;
    }

    return 0;
}