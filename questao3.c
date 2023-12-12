#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Produto {
    char nome[500];
    float preco;
    int quantidadeEstoque;
};
void realizarCompra(struct Produto produto) {
    int quantidadeComprada;
    printf("Digite a quantidade que deseja comprar:\n");
    scanf("%d", &quantidadeComprada);

    if (quantidadeComprada > produto->quantidadeEstoque) {
        printf(" Não temos estoque suficiente.\n");
    } else {
        produto->quantidadeEstoque -= quantidadeComprada;
        printf("Compra realizada!\n");
    }
}

void consultarEstoque(struct Produto produto) {
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Preço: R$%.2f\n", produto.preco);
}

int main() {
    setlocale(LC_ALL,"portuguese");
    struct Produto meuProduto = {"Produto A", 10.50, 50}; 

    void opcao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarCompra(&meuProduto);
                break;
            case 2:
                consultarEstoque(meuProduto);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Escolha novamente.\n");
                break;
        }
    } while (opcao != 3);

   
}