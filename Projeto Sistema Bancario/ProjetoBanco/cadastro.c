#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"
#include "consulta.h"
#include "operacoes.h"

void menu_atualizar_cadastro(Conta contas[], int qtd) {

    int opcao, numero, i;
    char telefone[20], agencia[20];
    int idx = -1;

    system("cls||clear");

    printf("=================================================================\n");
    printf("===================== ATUALIZAR CADASTRO ========================\n");
    printf("=================================================================\n");
    printf("Informe o número da conta para se atualizar o telefone ou agência: ");
    scanf("%d", &numero);
    getchar();

    for (i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("\nConta não encontrada.\n");
        printf("Não é possível atualizar os dados.\n");
        printf("Pressione ENTER para continuar...");
        getchar();

        system("cls||clear");
    }

    if (contas[idx].status == ENCERRADA) {
        printf("\nA conta de Nº%d está encerrada.\n");
        printf("Não é possível atualizar os dados.\n");
        printf("Pressione ENTER para continuar...");
        getchar();

        system("cls||clear");

        return;
        }

    do {

    system("cls||clear");

    printf("=========================================\n");
    printf("===== ATUALIZAR CADASTRO CONTA Nº%d =====\n", numero);
    printf("=========================================\n");
    printf("1 - Atualizar telefone\n");
    printf("2 - Atualizar agencia\n");
    printf("0 - Voltar\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {

        case 1:
            printf("\nInforme o novo telefone: ");
            fgets(telefone, 20, stdin);
            telefone[strcspn(telefone, "\n")] = 0;
            strcpy(contas[idx].telefone, telefone);

            printf("\nTelefone atualizado com sucesso.\n");

            system("pause");
            system("cls||clear");

            break;

        case 2:
            printf("\nInforme a nova agência: ");
            fgets(agencia, 20, stdin);
            agencia[strcspn(agencia, "\n")] = 0;
            strcpy(contas[idx].agencia, agencia);

            printf("\nAgência atualizada com sucesso.\n");

            system("pause");
            system("cls||clear");

            break;

        case 0:
            printf("\nRetornando ao menu principal...\n");
            printf("Pressione ENTER para continuar...");
            getchar();

            system("cls||clear");
            return;

        default:
            printf("\nOpção inválida!\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    }while(opcao != 0);
}

int abrir_conta(Conta contas[], int *qtd, int numero, char nome[], char cpf[], char agencia[], char telefone[]) {
    
    int i;
    
    if (*qtd >= MAX_CONTAS) {
        printf("----------------------------------------\n");
		printf("O limite de abertura de contas já foi atingido! Não foi possível continuar com a abertura da conta!\n");
        printf("----------------------------------------\n");
        printf("Pressione ENTER para continuar...");
        getchar();

        system("cls||clear");

        return 0;
    }

    for (i = 0; i < *qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0) {
            printf("----------------------------------------\n");
        	printf("Falha ao criar conta. Já existe uma conta ATIVA com esse CPF.\n");
            printf("----------------------------------------\n");
            printf("Pressione ENTER para continuar...");
            getchar();

            system("cls||clear");
            
            return 0;
        }
    }

    Conta nova;
    nova.numero = numero;
    strcpy(nova.nome, nome);
    strcpy(nova.cpf, cpf);
    strcpy(nova.agencia, agencia);
    strcpy(nova.telefone, telefone);

    nova.saldo = 0.0;
    nova.status = ATIVA;

    contas[*qtd] = nova;
    (*qtd)++;

    return 1;
}