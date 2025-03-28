#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANTAS 100

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
    char tipo[50];  
} Planta;

Planta estoque[MAX_PLANTAS];
int numPlantas = 0;

void adicionarPlanta() {
    if (numPlantas >= MAX_PLANTAS) {
        printf("\nErro: Estoque cheio!\n");
        return;
    }

    Planta novoPlanta = {numPlantas + 1};  // ID começa de 1

    // Perguntar o nome da planta
    getchar();  // Limpa o buffer
    printf("\nDigite o nome da Planta: ");
    fgets(novoPlanta.nome, 50, stdin);
    novoPlanta.nome[strcspn(novoPlanta.nome, "\n")] = '\0';  // Remove o '\n' extra

    // Pergunta a quantidade
    printf("Digite a quantidade inicial: ");
    scanf("%d", &novoPlanta.quantidade);

    // Pergunta o preço
    printf("Digite o preço: ");
    scanf("%f", &novoPlanta.preco);

    // Pergunta o tipo de planta
    getchar();  // Limpa o buffer
    printf("Digite o tipo da planta: ");
    fgets(novoPlanta.tipo, 50, stdin);
    novoPlanta.tipo[strcspn(novoPlanta.tipo, "\n")] = '\0';  // Remove o '\n' extra

    estoque[numPlantas++] = novoPlanta;  // Adiciona a nova planta ao estoque
    printf("\nPlanta adicionada com sucesso!\n");
}

void listarPlantas() {
    if (numPlantas == 0) {
        printf("\nNenhuma planta no estoque.\n");
        return;
    }

    printf("\nLista de plantas:\n");
    for (int i = 0; i < numPlantas; i++) {
        printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f | Tipo: %s\n", 
               estoque[i].id, estoque[i].nome, estoque[i].quantidade, 
               estoque[i].preco, estoque[i].tipo);
    }
}

void entradaMercadoria() {
    int id, quantidade;
    
    // Perguntar o ID do produto para entrada de mercadoria
    printf("\nDigite o ID do produto para entrada: ");
    scanf("%d", &id);

    if (id < 1 || id > numPlantas) {
        printf("\nErro: Produto não encontrado.\n");
        return;
    }

    // Pergunta a quantidade a ser adicionada de mercadoria
    printf("Digite a quantidade a adicionar: ");
    scanf("%d", &quantidade);

    if (quantidade > 0) {
        estoque[id - 1].quantidade += quantidade;
        printf("\nEntrada registrada com sucesso!\n");
    } else {
        printf("\nErro: Quantidade inválida.\n");
    }
}

void saidaMercadoria() {
    int id, quantidade;
    
    // Pergunta o ID do produto para saída de mercadoria
    printf("\nDigite o ID do produto para saída: ");
    scanf("%d", &id);

    if (id < 1 || id > numPlantas) {
        printf("\nErro: Produto não encontrado.\n");
        return;
    }

    // Pergunta a quantidade a retirar
    printf("Digite a quantidade a retirar: ");
    scanf("%d", &quantidade);

    if (quantidade > 0 && quantidade <= estoque[id - 1].quantidade) {
        estoque[id - 1].quantidade -= quantidade;
        printf("\nSaída registrada com sucesso!\n");
    } else {
        printf("\nErro: Quantidade inválida ou insuficiente.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- Controle do Estoque de Plantas ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Entrada de Mercadoria\n");
        printf("4. Saída de Mercadoria\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        
        while (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente: ");
            while (getchar() != '\n');  // Limpa o buffer
        }

        switch (opcao) {
            case 1: adicionarPlanta(); break;
            case 2: listarPlantas(); break;
            case 3: entradaMercadoria(); break;
            case 4: saidaMercadoria(); break;
            case 5: printf("\nSaindo do sistema. Até logo!\n"); break;
            default: printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}