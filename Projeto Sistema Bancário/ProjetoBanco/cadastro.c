#include <stdio.h>
#include <string.h>

#include "cadastro.h"
#include "consulta.h"
#include "operacoes.h"

int abrir_conta(Conta contas[], int *qtd, int numero, char nome[], char cpf[], char agencia[], char telefone[]) {
    
    int i;
    
    if (*qtd >= MAX_CONTAS) {
		printf("O limite de abertura de contas já foi atingido! Não foi possível continuar com a abertura da conta!\n");
        return 0;
    }

    for (i = 0; i < *qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0) {
        	printf("Falha ao criar conta. Já existe uma conta ATIVA com esse CPF.\n");
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

int atualizar_contato(Conta contas[], int qtd, int numero,
                      char novo_telefone[], char nova_agencia[]) {

    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    if (idx < 0)
        return 0;

    strcpy(contas[idx].telefone, novo_telefone);
    strcpy(contas[idx].agencia, nova_agencia);

    return 1;
}
