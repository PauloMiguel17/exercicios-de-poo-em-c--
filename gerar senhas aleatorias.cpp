#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm> // Para std::shuffle

int main() {
    //Conjuntos de caracteres disponíveis
    const std::string MAIUSCULAS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string MINUSCULAS = "abcdefghijklmnopqrstuvwxyz";
    const std::string NUMEROS = "0123456789";
    const std::string SIMBOLOS = "!@#$%^&*()-_=+[]{}|;:',.<>/?";

    // Configuração do gerador de números aleatórios (método moderno) 
    std::random_device rd;  // Obtém um número aleatório do hardware do sistema
    std::mt19937 gerador(rd());

    //Coleta dos requisitos do usuário
    int comprimento;
    char usarMaiusculas, usarMinusculas, usarNumeros, usarSimbolos;

    std::cout << "=============================" << std::endl;
    std::cout << "      GERADOR DE SENHAS      " << std::endl;
    std::cout << "=============================" << std::endl;

    std::cout << "Qual o comprimento da senha? ";
    std::cin >> comprimento;

    std::cout << "Incluir letras maiusculas? (s/n): ";
    std::cin >> usarMaiusculas;

    std::cout << "Incluir letras minusculas? (s/n): ";
    std::cin >> usarMinusculas;

    std::cout << "Incluir numeros? (s/n): ";
    std::cin >> usarNumeros;

    std::cout << "Incluir simbolos? (s/n): ";
    std::cin >> usarSimbolos;

    //Montagem do alfabeto e da senha inicial
    std::string alfabeto = "";
    std::string senha = "";

    if (usarMaiusculas == 's' || usarMaiusculas == 'S') {
        alfabeto += MAIUSCULAS;
        // Adiciona um caractere do tipo para garantir que ele esteja na senha
        senha += MAIUSCULAS[gerador() % MAIUSCULAS.length()];
    }
    if (usarMinusculas == 's' || usarMinusculas == 'S') {
        alfabeto += MINUSCULAS;
        senha += MINUSCULAS[gerador() % MINUSCULAS.length()];
    }
    if (usarNumeros == 's' || usarNumeros == 'S') {
        alfabeto += NUMEROS;
        senha += NUMEROS[gerador() % NUMEROS.length()];
    }
    if (usarSimbolos == 's' || usarSimbolos == 'S') {
        alfabeto += SIMBOLOS;
        senha += SIMBOLOS[gerador() % SIMBOLOS.length()];
    }
    
    // Verifica se o alfabeto não está vazio (o usuário escolheu pelo menos uma opção)
    if (alfabeto.empty()) {
        std::cout << "\nErro: Voce deve escolher pelo menos um tipo de caractere." << std::endl;
        return 1; // Termina o programa com um código de erro
    }

    // Verifica se o comprimento desejado é possível
    if (comprimento < senha.length()) {
        comprimento = senha.length();
        std::cout << "\nAviso: O comprimento foi ajustado para " << comprimento 
                  << " para incluir todos os tipos de caracteres solicitados." << std::endl;
    }

    //Preenchimento do restante da senha
    while (senha.length() < comprimento) {
        // Seleciona um caractere aleatório do alfabeto completo
        senha += alfabeto[gerador() % alfabeto.length()];
    }

    //Embaralhamento da senha final
    // Isso garante que os caracteres obrigatórios não fiquem sempre no início
    std::shuffle(senha.begin(), senha.end(), gerador);


    //Exibição da senha gerada
    std::cout << "\n-----------------------------" << std::endl;
    std::cout << "Senha gerada: " << senha << std::endl;
    std::cout << "-----------------------------" << std::endl;

    return 0;
}