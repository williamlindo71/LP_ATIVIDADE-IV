#include <stdio.h>
#include <string.h>
#include <locale.h>

struct ContaBancaria {
    int numeroConta;
    char nomeTitular[500];
    float saldo;
    char tipoConta[500]; 
};


void depositar(struct ContaBancaria conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de R$%.2f realizado com sucesso!\n", valor);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente.\n");
    } else {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: R$%.2f\n", conta.saldo);
}

void main() {
    struct ContaBancaria minhaConta = {8254, "WIlliam", 500, "Corrente"}; 

    int opcao;
    do {
        printf("\nEscolha uma operação:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Ver saldo\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        float valor;
        switch (opcao) {
            case 1:
                printf("Digite o valor para depósito:\n");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor para saque:\n");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(minhaConta);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Escolha novamente.\n");
                break;
        }
    } while (opcao != 4);

   
}