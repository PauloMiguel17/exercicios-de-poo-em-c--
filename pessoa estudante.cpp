#include <iostream>
#include <string>

using namespace std;

class Pessoa{
    protected:
        string nome;
        int idade;
    public:
        Pessoa(string n, int i) : nome(n), idade(i){}
};

class Aluno : public Pessoa{
    private:
        int semestre;
        int matricula;
        string curso;
    public:
        Aluno(string n, int i, int s, int m, string c) : Pessoa(n, i) , semestre(s), matricula(m), curso(c){}
        void mostrarInfo(){
            cout << "Aluno: " << nome << " idade: " << idade << " semestre" << semestre << "º" << " curso" << curso << " matricula: " << matricula << endl; 
        }
};

int main(){
    Aluno a("paulinho", 19, 3, 2420, "computacao");

    a.mostrarInfo();

    return 0;

}