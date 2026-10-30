#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Define a estrutura que armazena os dados de cada aluno
struct Aluno {
    string nome;
    int idade;
    int matricula;
    float notaFinal;
};

// Define o limite maximo de alunos
const int MAX_ALUNOS = 100;

// Funcao para cadastrar um novo aluno
void cadastrarAluno(Aluno alunos[], int &total) {
    if (total >= MAX_ALUNOS) {
        cout << "\nLimite de alunos atingido!\n";
        return;
    }

    Aluno novo;

    cout << "\nDigite o nome do aluno: ";
    getline(cin >> ws, novo.nome);

    cout << "Digite a idade: ";
    cin >> novo.idade;

    cout << "Digite a matricula: ";
    cin >> novo.matricula;

    // Verifica se a matricula ja esta cadastrada
    for (int i = 0; i < total; i++) {
        if (alunos[i].matricula == novo.matricula) {
            cout << "\nMatricula ja cadastrada!\n";
            return;
        }
    }

    cout << "Digite a nota final: ";
    cin >> novo.notaFinal;

    alunos[total] = novo;
    total++;

    cout << "\nAluno cadastrado com sucesso!\n";
}

// Funcao para listar todos os alunos cadastrados
void listarAlunos(Aluno alunos[], int total) {
    if (total == 0) {
        cout << "\nNenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n===== LISTA DE ALUNOS =====\n";

    for (int i = 0; i < total; i++) {
        cout << "\nNome: " << alunos[i].nome;
        cout << "\nIdade: " << alunos[i].idade;
        cout << "\nMatricula: " << alunos[i].matricula;
        cout << "\nNota final: " << alunos[i].notaFinal;
        cout << "\n--------------------------\n";
    }
}

// Funcao para buscar um aluno pela matricula
int buscarAluno(Aluno alunos[], int total, int matricula) {
    for (int i = 0; i < total; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }

    return -1;
}

// Funcao para exibir os dados de um aluno especifico
void consultarAluno(Aluno alunos[], int total) {
    int matricula;

    cout << "\nDigite a matricula do aluno: ";
    cin >> matricula;

    int posicao = buscarAluno(alunos, total, matricula);

    if (posicao == -1) {
        cout << "\nAluno nao encontrado.\n";
    } else {
        cout << "\n===== DADOS DO ALUNO =====\n";
        cout << "Nome: " << alunos[posicao].nome << endl;
        cout << "Idade: " << alunos[posicao].idade << endl;
        cout << "Matricula: " << alunos[posicao].matricula << endl;
        cout << "Nota final: " << alunos[posicao].notaFinal << endl;
    }
}

// Funcao para atualizar a nota final de um aluno
void atualizarNota(Aluno alunos[], int total) {
    int matricula;
    float novaNota;

    cout << "\nDigite a matricula do aluno: ";
    cin >> matricula;

    int posicao = buscarAluno(alunos, total, matricula);

    if (posicao == -1) {
        cout << "\nAluno nao encontrado.\n";
    } else {
        cout << "Aluno: " << alunos[posicao].nome << endl;
        cout << "Nota atual: " << alunos[posicao].notaFinal << endl;

        cout << "Digite a nova nota: ";
        cin >> novaNota;

        alunos[posicao].notaFinal = novaNota;

        cout << "\nNota atualizada com sucesso!\n";
    }
}

// Funcao principal do programa
int main() {
    Aluno alunos[MAX_ALUNOS];
    int total = 0;
    int opcao;

    do {
        cout << "\n===== SISTEMA DE CADASTRO DE ALUNOS =====\n";
        cout << "1 - Cadastrar aluno\n";
        cout << "2 - Listar todos os alunos\n";
        cout << "3 - Buscar aluno por matricula\n";
        cout << "4 - Atualizar nota final\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, total);
                break;

            case 2:
                listarAlunos(alunos, total);
                break;

            case 3:
                consultarAluno(alunos, total);
                break;

            case 4:
                atualizarNota(alunos, total);
                break;

            case 0:
                cout << "\nEncerrando o sistema...\n";
                break;

            default:
                cout << "\nOpcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
