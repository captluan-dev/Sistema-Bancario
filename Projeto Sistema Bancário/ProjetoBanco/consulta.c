#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contas.h"
#include "consulta.h"

int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char *cpf) {
	
    int i;
    
    for (i = 0; i < qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

void consultar_por_cpf(const Conta contas[], int qtd) {

    char cpf[20];
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    getchar();

    int idx = encontrar_conta_por_cpf(contas, qtd, cpf);

    if (idx == -1) {
        printf("\nNenhuma conta com esse CPF foi encontrada.\n");
        esperar_tecla();
        return;
    }

    mostrar_dados(&contas[idx]);
    esperar_tecla();
}

void consultar_por_numero(const Conta contas[], int qtd) {

    int numero;
    
    printf("Digite o número da conta: ");
    scanf("%d", &numero);
    getchar();

    int idx = encontrar_conta_por_numero(contas, qtd, numero);

    if (idx == -1) {
        printf("\nConta não encontrada.\n");
        esperar_tecla();
        return;
    }

    mostrar_dados(&contas[idx]);
    esperar_tecla();
}

void menu_consulta(const Conta contas[], int qtd) {
	
    int opcao;

    system("cls||clear");
    printf("\n========================================\n");
    printf("------------ CONSULTAR CONTA -----------\n");
    printf("========================================\n");
    printf("1 - Consultar por número\n");
    printf("2 - Consultar por CPF\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {

        case 1:
            consultar_por_numero(contas, qtd);
            break;

        case 2:
            consultar_por_cpf(contas, qtd);
            break;

        case 0:
            return;

        default:
            printf("Opção inválida!\n");
            esperar_tecla();
    }
}

void mostrar_dados(const Conta *c) {
    
                            // *c -> ponteiro para uma conta específica do vetor

    printf("\n________________________________________\n");
    printf("----------  CONTA Nº %d  --------------\n", c->numero); // "->" É equivalente a '(*c).campo', mas de forma simplificada
    printf("\n");

    printf("[ DADOS PESSOAIS ]\n");
    printf("Nome: %s\n", c->nome);
    printf("CPF: %s\n", c->cpf);
    printf("Telefone: %s\n", c->telefone);

    printf("\n[ INFORMAÇÕES BANCÁRIAS ]\n");
    printf("Agência: %s\n", c->agencia);
    printf("Saldo: %.2f\n", c->saldo);

    printf("Status: %s\n",
        (c->status == ATIVA) ? "ATIVA" : "ENCERRADA"); // Operador Ternário. É uma forma reduzida de escrever: // if(c->status == ATIVA)
                                                                                                               //     printf("ATIVA");
                                                                                                               // else
                                                                                                               //     printf("ENCERRADA");


    printf("________________________________________\n");
}

// ------------------------------------------------------------
// LISTAR CONTAS COM FILTROS (ATIVAS / ENCERRADAS / TODAS)
// ------------------------------------------------------------
void listar_contas(const Conta contas[], int qtd) {
    
    int opcao;
    int encontrou;
    int i;
    
    do {
        system("cls||clear");
        
        printf("\n========================================\n");
        printf("------------- LISTAR CONTAS ------------\n");
        printf("========================================\n");
        printf("1 - Ativas\n");
        printf("2 - Encerradas\n");
        printf("3 - Todas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){

            case 1: {
                system("cls||clear");
                
                printf("\n========================================\n");
                printf("------ LISTAGEM DE CONTAS ATIVAS -------\n");
                printf("========================================\n");
                encontrou = 0;

                for(i = 0; i < qtd; i++) {
                    if (contas[i].status == ATIVA) {
                        mostrar_dados(&contas[i]);
                        encontrou = 1;
                    }
                }

                if (!encontrou)
                    printf("Nenhuma conta ativa encontrada.\n");

                esperar_tecla();
                break;
            }

            case 2: {
                system("cls||clear");
                
                printf("\n========================================\n");
                printf("---- LISTAGEM DE CONTAS ENCERRADAS -----\n");
                printf("========================================\n");
                encontrou = 0;

                for(i = 0; i < qtd; i++) {
                    if (contas[i].status == ENCERRADA) {
                        mostrar_dados(&contas[i]);
                        encontrou = 1;
                    }
                }

                if (!encontrou)
                    printf("Nenhuma conta encerrada encontrada.\n");

                esperar_tecla();
                break;
            }

            case 3: {
                system("cls||clear");
                
                printf("\n========================================\n");
                printf("----------- TODAS AS CONTAS ------------\n");
                printf("========================================\n");
                encontrou = 0;

                for(i = 0; i < qtd; i++) {
                    mostrar_dados(&contas[i]);
                    encontrou = 1;
                }

                if (!encontrou)
                    printf("Nenhuma conta cadastrada.\n");

                esperar_tecla();
                break;
            }

            case 0:
                printf("\nVoltando ao Menu Principal...\n");
                esperar_tecla();
                break;

            default:
                printf("\nOpção inválida!\n");
                esperar_tecla();
        }

    } while(opcao != 0);
}

// -----------------------------------------
// ENCERRA CONTA (SOMENTE SE O SALDO == 0)
// -----------------------------------------

void encerrar_conta(Conta contas[], int qtd) {
    
    int numero;
    int encontrou = 0;
    int i;
    
    system("cls||clear");
    printf("\n========================================\n");
    printf("------------- ENCERRAR CONTA -----------\n");
    printf("========================================\n");
    
    printf("Digite o número da conta: ");
    scanf("%d", &numero);
    
    for (i = 0; i < qtd; i++) {
        
        if (contas[i].numero == numero) {
            encontrou = 1;
            
            // SALDO DIFERENTE DE ZERO -> NÃO ENCERRA
            if (contas[i].saldo != 0) {
                printf("\n________________________________________\n");
                printf("O saldo da conta é diferente de zero.\n");
                printf("A conta NÃO pode ser encerrada.\n");
                printf("________________________________________\n");

                esperar_tecla();
                return;
            }
            
            // JÁ ENCERRADA
            if (contas[i].status == ENCERRADA) {
                printf("\n________________________________________\n");
                printf("Essa conta já está encerrada.\n");
                printf("________________________________________\n");

                esperar_tecla();
                return;
            }
            
            // ENCERRAMENTO OK
            contas[i].status = ENCERRADA;
            printf("\n________________________________________\n");
            printf("Conta %d encerrada com sucesso!\n", numero);
            printf("________________________________________\n");

            esperar_tecla();
            return;
        }
    }
    
    // NÃO ENCONTROU A CONTA
    if (!encontrou) {
        printf("\n________________________________________\n");
        printf("Conta não encontrada!\n");
        printf("________________________________________\n");

        esperar_tecla();
        return;
    }
}

void esperar_tecla() {
    printf("Pressione ENTER para continuar...");
    getchar(); // limpa BUFFER
    getchar(); // espera ENTER
}
