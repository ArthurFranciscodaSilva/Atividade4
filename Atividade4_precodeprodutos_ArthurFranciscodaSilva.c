
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 10 // Tamanho fixo do vetor

// Função para exibir o vetor de forma formatada
void exibeVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Bubble Sort em ordem crescente
void bubbleSortCrescente(int vetor[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

// Bubble Sort em ordem decrescente
void bubbleSortDecrescente(int vetor[], int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main() {
    int produtos[TAM];
    int i;
    char nome[30];
    char buffer[50];
    int erro, temNumero;
    int valor;

    // Pergunta o nome
    printf("Ola, qual o seu nome? ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // remove o ENTER
    printf("Bem vindo %s, por favor informe os valores respectivos de cada produto:\n", nome);

    // Leitura dos produtos com validação
    for (i = 0; i < TAM; i++) {
        while (1) {
            printf("Informe o valor do produto %d: ", i + 1);
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Erro de leitura, tente novamente.\n");
                continue;
            }

            buffer[strcspn(buffer, "\n")] = '\0'; // remove o ENTER

            erro = 0;
            temNumero = 0;

            // Validação: apenas dígitos, ponto e espaço são aceitos
            for (int j = 0; buffer[j] != '\0'; j++) {
                if (!(isdigit((unsigned char)buffer[j]) || buffer[j] == ' ')) {
                    erro = 1;
                    break;
                }
                if (isdigit((unsigned char)buffer[j])) temNumero = 1;
            }

            if (erro || !temNumero) {
                printf("Voce nao digitou um numero valido.\n");
                continue;
            }

            // Converte string -> int
            if (sscanf(buffer, "%d", &valor) != 1) {
                printf("Valor invalido, tente novamente.\n");
                continue;
            }

            produtos[i] = (int)valor;
            break; // entrada válida, sai do while
        }
    }

    // Mostra vetor original
    printf("\nVetor original:\n");
    exibeVetor(produtos, TAM);

    // Copia para ordenação
    int crescente[TAM], decrescente[TAM];
    for (i = 0; i < TAM; i++) {
        crescente[i] = produtos[i];
        decrescente[i] = produtos[i];
    }

    // Ordena crescente
    bubbleSortCrescente(crescente, TAM);
    printf("\nVetor em ordem crescente:\n");
    exibeVetor(crescente, TAM);

    // Ordena decrescente
    bubbleSortDecrescente(decrescente, TAM);
    printf("\nVetor em ordem decrescente:\n");
    exibeVetor(decrescente, TAM);

    return 0;
}

