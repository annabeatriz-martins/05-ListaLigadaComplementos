#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* anterior = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	//se alista tiver vazia ou o primeiro é maior q o novo valor
	if (primeiro == NULL || primeiro->valor > novo->valor)
	{
		novo->prox = primeiro;
		primeiro = novo;
		return;
	}
	else
	{
		//percorre a lista pra achar o ponto certo para inserir o novo valor
		NO* aux = primeiro;
		while (aux->prox != NULL && aux->valor < novo->valor)
		{
			//if()
			//{
				novo->prox = aux;
				aux = anterior->prox;
				anterior->prox = novo;
				break;
			//}
			aux = aux->prox;
		}
		aux->prox = novo;
		return;
	}
}

void excluirElemento()
{
	int num = 0;
	bool apagou = false;
	bool vazio = false;

	cout << "Digite um numero: ";
	cin >> num;

	NO* aux = primeiro;
	NO* anterior = NULL;

	if (primeiro == NULL) 
	{
		cout << "Lista vazia" << endl;
		vazio = true;
	}

	while (aux != NULL && aux->valor <= num)
	{
		if(aux->valor == num)
		{
			if(anterior == NULL)
			{
				primeiro = aux->prox;
			}
			else
			{
				anterior->prox = aux->prox;
			}

			free(aux);
			cout << "Elemento excluido" << endl;
			apagou = true;
			break;
		}
		anterior = aux;
		aux = aux->prox;
	}

	if (!apagou && !vazio) 
	{
		cout << "Elemento nao encontrado" << endl;
	}
}

void buscarElemento()
{
	int num = 0;
	bool achei = false;

	cout << "Digite um numero: ";
	cin >> num;

	NO* aux = primeiro;

	if (primeiro == NULL) 
	{
		cout << "Lista vazia" << endl;
		return;
	}

	while(aux != NULL && aux->valor <= num) 
	{
		if (aux->valor == num) 
		{
			cout << "Elemento encontrado" << endl;
			achei = true;
			return;
		}
		aux = aux->prox;
	}

	if (!achei) 
	{
		cout << "Nao encontrado" << endl;
	}
}


