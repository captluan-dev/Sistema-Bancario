#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contas.h"

int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero) {
    
    int i;
    
    for (i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

int depositar(Conta contas[], int qtd, int numero, double valor) {
    
    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    
    if (idx == -1) {
		printf("\nErro! Conta de destino não encontrada. ");
		return 0;
		}
		
    if (contas[idx].status == ENCERRADA) {
		printf("\nErro! Conta de destino encerrada. ");
		return 0;
		}
		
    if (valor <= 0) {
		printf("\nErro! Valor inválido. ");
		return 0;
		}
    
    contas[idx].saldo += valor;
    
    printf("\nDepósito realizado!\n");
	printf("Novo saldo: %.2f\n", contas[idx].saldo);
    
    return 1;
}

int sacar(Conta contas[], int qtd, int numero, double valor) {
    
    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    
    if (idx == -1) {
		printf("\nErro! Conta não encontrada.\n");
		return 0;
		}
		
    if (contas[idx].status == ENCERRADA) {
		printf("\nErro! A conta de Nº%d está 'encerrada'.\n", numero);
		return 0;
		}
		
    if (valor <= 0) {
		printf("\nErro! Valor inválido.\n");
		return 0;
		}
		
    if (valor > contas[idx].saldo) {
		printf("\nErro! O saldo da conta é insuficiente.\n");
		return 0;
		}
    
    contas[idx].saldo -= valor;
    
    printf("Novo saldo: %.2f\n", contas[idx].saldo);
    
    return 1;
}

int transferir(Conta contas[], int qtd, int origem, int destino, double valor) {
    
    int idxOrigem = encontrar_conta_por_numero(contas, qtd, origem);
    int idxDestino = encontrar_conta_por_numero(contas, qtd, destino);
    
    if (idxOrigem == -1 && idxDestino == -1) {
    	printf("\nErro! Conta de 'origem' e 'destino' não encontradas.\n");
    	return 0;
	}
    
    if (idxOrigem == -1) {
		printf("\nErro! Conta de 'origem' não encontrada.\n");
		return 0;
		}
		
	if (idxDestino == -1) {
		printf("\nErro! Conta de 'destino' não encontrada.\n");
		return 0;
	}
	
	if (contas[idxOrigem].status == ENCERRADA && contas[idxDestino].status == ENCERRADA) {
		printf("\nErro! Conta de 'origem' e 'destino' estão encerradas.\n");
		return 0;
	}
    
    if (contas[idxOrigem].status == ENCERRADA) {
		printf("\nErro! Conta de 'origem' está encerrada.\n");
		return 0;
		}
		
	if (contas[idxDestino].status == ENCERRADA) {
		printf("\nErro! Conta de 'destino' está encerrada.\n");
		return 0;
	}
		
    if (valor <= 0) {
		printf("\nErro! Valor inválido.\n");
		return 0;
		}
		
    if (valor > contas[idxOrigem].saldo) {
		printf("\nErro! O saldo da conta de 'origem' é insuficiente para realizar a transferência.\n");
		return 0;
		}
    
    contas[idxOrigem].saldo -= valor;
    contas[idxDestino].saldo += valor;
    
    return 1;
}
