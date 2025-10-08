#include <iostream>
using namespace std;

// A classe 'Elemento' representa um único nó em nossa estrutura de dados (a pilha).
// Cada 'Elemento' contém um dado (um inteiro) e um ponteiro para o próximo 'Elemento'.
class Elemento{
	private:
		int dado; // O valor que o elemento armazena.
		Elemento*ptr_proximo; // Ponteiro para o próximo elemento na pilha.
	public:
		// Métodos para definir (set) e obter (get) os valores dos atributos privados.
		void setDado(int);
		int getDado();
		void setProximo(Elemento*);
		Elemento* getProximo();
};

// Define o valor do atributo 'dado'. 'this->dado' refere-se ao atributo da classe.
inline void Elemento::setDado(int dado){
	this->dado = dado;
}

// Retorna o valor do atributo 'dado'.
inline int Elemento::getDado(){
	return dado;
}

// Define para qual elemento o 'ptr_proximo' deve apontar.
inline void Elemento::setProximo(Elemento *ptr_elemento){
	ptr_proximo = ptr_elemento;
}

// Retorna o endereço do próximo elemento.
inline Elemento* Elemento::getProximo(){
	return ptr_proximo;
}

// A classe 'Pilha' gerencia a coleção de 'Elementos' e implementa a lógica LIFO (Last-In, First-Out).
class Pilha {
	private:
		// Ponteiro que sempre aponta para o elemento no topo da pilha.
		Elemento*ptr_primeiro;
	public:
		// Construtor: quando uma nova pilha é criada, ela começa vazia (topo aponta para NULL).
		Pilha() { ptr_primeiro = NULL; }
		// Métodos para adicionar e remover elementos da pilha.
		void inserir(Elemento*);
		Elemento* remover();
};

// Implementação do método para inserir um elemento na pilha (operação "push").
void Pilha::inserir(Elemento* elemento){
	// O novo elemento precisa apontar para quem era o topo da pilha anteriormente.
	elemento->setProximo(ptr_primeiro);
	// O topo da pilha agora passa a ser o novo elemento inserido.
	ptr_primeiro = elemento;
}

// Implementação do método para remover um elemento da pilha (operação "pop").
Elemento* Pilha::remover(){
	// Se a pilha estiver vazia (ptr_primeiro é NULL), não há nada a remover.
	if (ptr_primeiro == NULL){
		return NULL;
	}
	// Guarda o endereço do elemento do topo que será removido.
	Elemento* elemento_removido = ptr_primeiro;
	// O topo da pilha passa a ser o próximo elemento da lista.
	ptr_primeiro = ptr_primeiro->getProximo();
	// Retorna o elemento que foi removido.
	return elemento_removido;
}

int main() {
	// Cria três objetos 'Elemento' estaticamente.
	Elemento elementoA, elementoB, elementoC;
	int dado;

	// Lê um valor do teclado e o define para o elementoA.
	cin >> dado;
	elementoA.setDado(dado);

	// Lê um segundo valor e o define para o elementoB.
	cin >> dado;
	elementoB.setDado(dado);

	// Lê um terceiro valor e o define para o elementoC.
	cin >> dado;
	elementoC.setDado(dado);

	// Cria uma instância da Pilha.
	Pilha pilha;
	// Insere os elementos na pilha. A ordem de inserção é A, depois B, depois C.
	pilha.inserir(&elementoA); // Pilha: [A]
	pilha.inserir(&elementoB); // Pilha: [B, A]
	pilha.inserir(&elementoC); // Pilha: [C, B, A] <- C está no topo

	// Remove os elementos e imprime seus valores. Como é uma pilha (LIFO),
	// a ordem de remoção será o inverso da ordem de inserção.
	cout << pilha.remover()->getDado(); // Remove C, imprime o dado de C.
	cout << pilha.remover()->getDado(); // Remove B, imprime o dado de B.
	cout << pilha.remover()->getDado(); // Remove A, imprime o dado de A.
	
	return 0;
}