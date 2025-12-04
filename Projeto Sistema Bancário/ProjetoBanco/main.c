/*
Projeto: Sistema Bancï¿½rio
Arquivo: main.c
Descrição:
    Arquivo principal do sistema. Exibe o menu interativo,
    recebe entradas e chama funções implementadas em:
    cadastro.c, operacoes.c e consulta.c.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "contas.h"
#include "cadastro.h"
#include "operacoes.h"
#include "consulta.h"



// ------------------------------
// Funções do Menu
// ------------------------------
int menu() {
    int opcao;

    printf("\n=========== SISTEMA BANCÁRIO ===========\n");
    printf("1. Abrir conta\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Transferir\n");
    printf("5. Consultar saldo e dados\n");
    printf("6. Atualizar telefone e agência\n");
    printf("7. Listar contas\n");
    printf("8. Encerrar conta\n");
    printf("9. Sair\n");
    printf("----------------------------------------\n");
    printf("Escolha: ");

    scanf("%d", &opcao);
    getchar(); // limpar buffer

    return opcao;
}

// ------------------------------
// Função Principal
// ------------------------------
int main() {
    
    setlocale(LC_ALL, "portuguese");

    // Contas de exemplo carregadas no sistema
Conta contas[MAX_CONTAS] = {
    {1, "Ana Beatriz Moreira", "12345678910", "001-1", "(11)99812-3040", 1500.00, ATIVA},
    {2, "Lucas Henrique Silva", "98765432100", "237-8", "(21)99145-6621", 0.00, ENCERRADA},
    {3, "Mariana Costa Ribeiro", "45678912377", "104-2", "(31)99220-7629", 7800.00, ATIVA},
    {4, "Pedro Antonio Siqueira", "15975348622", "341-5", "(71)99702-1149", 50.00, ATIVA},
    {5, "Juliana Ferreira Santos", "85236974190", "033-3", "(48)99681-3370", 0.00, ENCERRADA}
};

int qtdContas = 5;
int proximo_numero = 6;

    int op;

    do {
        op = menu();

        switch (op) {

        case 1: { // ABRIR CONTA
            char nome[100], cpf[20], agencia[20], telefone[20];
            
            system("cls||clear");
            
            printf("\n============= ABRIR CONTA ==============\n");

            printf("Nome do cliente: ");
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("CPF: ");
            fgets(cpf, 20, stdin);
            cpf[strcspn(cpf, "\n")] = 0;

            printf("Agência: ");
            fgets(agencia, 20, stdin);
            agencia[strcspn(agencia, "\n")] = 0;

            printf("Telefone: ");
            fgets(telefone, 20, stdin);
            telefone[strcspn(telefone, "\n")] = 0;

            if (abrir_conta(contas, &qtdContas, proximo_numero, nome, cpf, agencia, telefone)) {
            	
                printf("Conta criada com sucesso!\n");
                proximo_numero++;
                
                printf("\n----------------------------------------\n");
            }
            break;
        }

        case 2: { // DEPOSITAR
            int numero;
            double valor;
            printf("Número da conta: ");
            scanf("%d", &numero);
            printf("Valor do depósito: ");
            scanf("%lf", &valor);

            if (depositar(contas, qtdContas, numero, valor))
                printf("Depósito realizado!\n");
            else
                printf("Erro ao depositar.\n");
            break;
        }

        case 3: { // SACAR
            int numero;
            double valor;
            printf("Número da conta: ");
            scanf("%d", &numero);
            printf("Valor do saque: ");
            scanf("%lf", &valor);

            if (sacar(contas, qtdContas, numero, valor))
                printf("Saque realizado!\n");
            else
                printf("Erro ao sacar.\n");
            break;
        }

        case 4: { // TRANSFERIR
            int origem, destino;
            double valor;

            printf("Conta de origem: ");
            scanf("%d", &origem);
            printf("Conta de destino: ");
            scanf("%d", &destino);
            printf("Valor da transferência: ");
            scanf("%lf", &valor);

            if (transferir(contas, qtdContas, origem, destino, valor))
                printf("Transferência realizada!\n");
            else
                printf("Falha na transferência.\n");
            break;
        }

        case 5: { // CONSULTAR
			menu_consulta(contas, qtdContas);
			break;
        }

        case 6: { // ATUALIZAR CONTATOS
            int numero;
            char telefone[20], agencia[20];

            printf("Número da conta: ");
            scanf("%d", &numero);
            getchar();

            printf("Novo telefone: ");
            fgets(telefone, 20, stdin);
            telefone[strcspn(telefone, "\n")] = 0;

            printf("Nova agência: ");
            fgets(agencia, 20, stdin);
            agencia[strcspn(agencia, "\n")] = 0;

            if (atualizar_contato(contas, qtdContas, numero, telefone, agencia))
                printf("Dados atualizados!\n");
            else
                printf("Falha ao atualizar.\n");
            break;
        }

        case 7: { // LISTAR CONTAS
            listar_contas(contas, qtdContas);
            break;
        }

        case 8: { // ENCERRAR
            encerrar_conta(contas, qtdContas);
            break;
        }

        case 9:
            printf("Encerrando o sistema...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (op != 9);

    return 0;
}
