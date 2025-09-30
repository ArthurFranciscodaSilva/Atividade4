#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tam 10 // Aqui definimos o tamanho do vetor

// Funcao para exibir o vetor 
// o void serve para indicar que a funcao nao retorna nada
void exibeVetor(float vetor[], int tamanho) {  
    for (int i = 0; i < tamanho; i++) {      
        printf("%.2f ", vetor[i]);
    }
    printf("\n");
}

// Aqui implementamos o Bubble Sort em ordem crescente
void bubbleSortCrescente(float vetor[], int tamanho) {
    int i, j;
    float temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {   // Aqui fazemos a comparacao, se o elemento atual for maior que o proximo, trocamos
            if (vetor[j] > vetor[j + 1]) {        // Aqui fazemos a troca, se o elemento atual for maior que o proximo, trocamos
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Iniciamos a funcao para ordenar os elementos em ordem decrescente, (bubble sort decrescente)
void bubbleSortDecrescente(float vetor[], int tamanho) {
    int i, j;
    float temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
// iniciamos a funcao principal, onde o programa inicia a execucao
int main() {
    char nomes[tam][50]; //nome dos produtos
    float valores[tam]; //valores dos produtos em ponto flutuante
    char nomeusuar[30];
    char buffer[50];
    int i;
    

    
    // Solicitacao ao usuario, nome e os valores     
    printf("Ola, qual o seu nome? ");
    fgets(nomeusuar, sizeof(nomeusuar), stdin);
    nomeusuar[strcspn(nomeusuar, "\n")] = '\0'; // remove o ENTER
    printf("Bem vindo %s, vamos cadastrar os produtos!:\n", nomeusuar);

    // Iniciamos a leitura dos valores de cada produto
    for (i = 0; i < tam; i++) {    // aqui usamos o for para repetir a leitura 10 vezes
         // Aqui solicitamos o nome do produto e adicionamos ao banco de dados
        printf("\nDigite o nome do produto %d: ", i + 1);
        fgets(nomes[i], sizeof(nomes[i]), stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o ENTER

        while (1) {
        printf("Informe o valor do produto %d (exemplo: 2.50): ", i + 1);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Tente novamente.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0'; // remove o ENTER
            // aqui vamos  validar se o que o usuario digitou tem ponto ou nao e se tem digito ou nao
        int componto = 0, valido = 1, comdigito = 0;
        for (int j = 0; buffer[j] != '\0'; j++) {
            if (buffer[j] == '.') {
                if (componto) { // já tinha um ponto antes
                    valido = 0;
                    break;
                }
                componto = 1;
            }
            else if (!isdigit((unsigned char)buffer[j])) {
                valido = 0;
                break;
            }
            else {
                comdigito = 1;
            }
    }

    if (!valido || !comdigito) {
        printf("Valor inserido invalido. Digite novamente (formato aceito 0.00)\n");
        continue;
    }

    float valor;
    if (sscanf(buffer, "%f", &valor) != 1) {
        printf("Valor inserido invalido. Digite novamente (formato aceito 0.00)\n");
        continue;
    }

    valores[i] = valor;
    break;
}

        
    }

    printf("\nProdutos e valores cadastrados:\n");
    for (i = 0; i < tam; i++) {
        printf("%s: R$ %.2f\n", nomes[i], valores[i]);
    }

    // Cópia dos valores para ordenação
    float crescente[tam], decrescente[tam];
    for (i = 0; i < tam; i++) {
        crescente[i] = valores[i];
        decrescente[i] = valores[i];
    }

    // Ordena crescente, mostra o vetor ordenado
    bubbleSortCrescente(crescente, tam);
    printf("\nVetor em ordem crescente:\n");
    exibeVetor(crescente, tam);

    // Ordena decrescente, mostra o vetor ordenado
    bubbleSortDecrescente(decrescente, tam);
    printf("\nVetor em ordem decrescente:\n");
    exibeVetor(decrescente, tam);

    return 0;
}

