#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_NOME 50
#define TAM_TIPO 30

// Estrutura para representar um item
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

// Variáveis globais
Item mochila[MAX_ITENS];
int totalItens = 0;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para adicionar item
void adicionarItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n❌ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }
    
    printf("\n=== ADICIONAR ITEM ===\n");
    
    printf("Nome do item: ");
    limparBuffer();
    fgets(mochila[totalItens].nome, TAM_NOME, stdin);
    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;
    
    printf("Tipo do item (ex: Arma, Munição, Kit Médico): ");
    fgets(mochila[totalItens].tipo, TAM_TIPO, stdin);
    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;
    
    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);
    
    totalItens++;
    printf("\n✅ Item adicionado com sucesso!\n");
}

// Função para remover item
void removerItem() {
    if (totalItens == 0) {
        printf("\n❌ Mochila vazia! Não há itens para remover.\n");
        return;
    }
    
    char nomeBusca[TAM_NOME];
    int encontrado = 0;
    
    printf("\n=== REMOVER ITEM ===\n");
    printf("Digite o nome do item a remover: ");
    limparBuffer();
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    
    // Buscar o item
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            
            // Deslocar os itens seguintes uma posição para trás
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            
            totalItens--;
            printf("\n✅ Item '%s' removido com sucesso!\n", nomeBusca);
            break;
        }
    }
    
    if (!encontrado) {
        printf("\n❌ Item não encontrado na mochila.\n");
    }
}

// Função para listar itens
void listarItens() {
    if (totalItens == 0) {
        printf("\n📦 Mochila vazia! Nenhum item cadastrado.\n");
        return;
    }
    
    printf("\n=== INVENTÁRIO DA MOCHILA ===\n");
    printf("┌────────────────────────────────────────────────────────────────┐\n");
    printf("│ %-25s │ %-20s │ %-10s │\n", "NOME", "TIPO", "QUANTIDADE");
    printf("├────────────────────────────────────────────────────────────────┤\n");
    
    for (int i = 0; i < totalItens; i++) {
        printf("│ %-25s │ %-20s │ %-10d │\n", 
               mochila[i].nome, 
               mochila[i].tipo, 
               mochila[i].quantidade);
    }
    
    printf("└────────────────────────────────────────────────────────────────┘\n");
    printf("Total de itens: %d/%d\n", totalItens, MAX_ITENS);
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║   🏝️  CÓDIGO DA ILHA - FREE FIRE 🏝️   ║\n");
    printf("║      Sistema de Inventário v1.0       ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  1 - Adicionar item                    ║\n");
    printf("║  2 - Remover item                      ║\n");
    printf("║  3 - Listar itens                      ║\n");
    printf("║  0 - Sair                              ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    
    printf("\n🎮 Bem-vindo ao Desafio Código da Ilha! 🎮\n");
    printf("Prepare sua mochila para sobreviver na ilha misteriosa!\n");
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 0:
                printf("\n👋 Obrigado por jogar! Boa sorte na ilha!\n");
                printf("🏆 Sistema encerrado com sucesso.\n\n");
                break;
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            limparBuffer();
            getchar();
        }
        
    } while (opcao != 0);
    
    return 0;
}
