#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definindo a estrutura para representar um bem
struct Bem {
    string nome;
    string categoria;
    string data_aquisicao;
    double peso;
    string endereco; // apenas para imoveis
};

const int MAX_BENS = 100;

// Função para cadastrar um novo bem
void cadastrarBem(Bem* bens[], int& numBens) {
    if (numBens < MAX_BENS) {
        Bem* novoBem = new Bem; // Aloca memoria para um novo bem
        cout << "Nome do bem: ";
        cin.ignore(); // Limpa o buffer do teclado
        getline(cin, novoBem->nome); // Recebe o nome do bem
        cout << "Categoria do bem: ";
        getline(cin, novoBem->categoria); // Recebe a categoria do bem
        cout << "Data de aquisicao do bem: ";
        getline(cin, novoBem->data_aquisicao); // Recebe a data de aquisicao do bem
        cout << "Peso do bem: ";
        cin >> novoBem->peso; // Recebe o peso do bem
        cin.ignore(); // Limpa o buffer do teclado
        if (novoBem->categoria == "imovel") { // Se for um imovel
            cout << "Endereco do imovel: ";
            getline(cin, novoBem->endereco); // Recebe o endereço do imovel
        }
        bens[numBens] = novoBem; // Armazena o novo bem no array de bens
        numBens++; // Incrementa o numero de bens cadastrados
    } else {
        cout << "Capacidade maxima atingida." << endl;
    }
}

// Funcao para salvar os bens em um arquivo
void salvarBens(Bem* bens[], int numBens) {
    ofstream arquivo("bens.txt"); // Cria um arquivo de saída
    if (arquivo.is_open()) { // Se o arquivo foi aberto com sucesso
        for (int i = 0; i < numBens; ++i) { // Para cada bem cadastrado
            arquivo << "Nome: " << bens[i]->nome << ", Categoria: " << bens[i]->categoria << ", Data de aquisicao: " << bens[i]->data_aquisicao << ", Peso: " << bens[i]->peso;
            if (bens[i]->categoria == "imovel") { // Se for um imovel
                arquivo << ", Endereco: " << bens[i]->endereco; // Adiciona o endereco ao arquivo
            }
            arquivo << endl; // Pula para a proxima linha
        }
        arquivo.close(); // Fecha o arquivo
        cout << "Bens salvos em 'bens.txt'." << endl; // Informa ao usuario que os bens foram salvos
    } else {
        cout << "Nao foi possivel salvar os bens." << endl; // Se nao foi possivel abrir o arquivo, informa o usuario
    }
}

int main() {
    Bem* bens[MAX_BENS]; // Declara um array de ponteiros para bens
    int numBens = 0; // Variavel para armazenar o numero de bens cadastrados

    char opcao; // Variavel para armazenar a opcao do usuario
    do {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar novo bem" << endl;
        cout << "2. Salvar bens" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha a opcao: ";
        cin >> opcao; // Recebe a opcao do usuario

        switch (opcao) { // Verifica a opcao escolhida pelo usuario
            case '1':
                cadastrarBem(bens, numBens); // Chama a funcao para cadastrar um novo bem
                break;
            case '2':
                salvarBens(bens, numBens); // Chama a funcao para salvar os bens em um arquivo
                break;
            case '3':
                cout << "Saindo..." << endl; // Mensagem de saida
                break;
            default:
                cout << "Opcao invalida." << endl; // Mensagem para opcao invalida
        }
    } while (opcao != '3'); // Loop continua até o usuario escolher sair

    // Liberar memoria
    for (int i = 0; i < numBens; ++i) {
        delete bens[i]; // Deleta o bem da memoria
    }

    return 0;
}
