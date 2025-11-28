#include <stdio.h>
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
    
    if (idx == -1) { printf("Erro: conta não encontrada.\n"); return 0; }
    if (contas[idx].status == ENCERRADA) { printf("Erro: conta encerrada.\n"); return 0; }
    if (valor <= 0) { printf("Erro: valor deve ser positivo.\n"); return 0; }
    
    contas[idx].saldo += valor;
    
    printf("Depósito realizado! Novo saldo: %.2f\n", contas[idx].saldo);
    
    return 1;
}

int sacar(Conta contas[], int qtd, int numero, double valor) {
    
    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    
    if (idx == -1) { printf("Erro: conta não encontrada.\n"); return 0; }
    if (contas[idx].status == ENCERRADA) { printf("Erro: conta encerrada.\n"); return 0; }
    if (valor <= 0) { printf("Erro: valor deve ser positivo.\n"); return 0; }
    if (valor > contas[idx].saldo) { printf("Erro: saldo insuficiente.\n"); return 0; }
    
    contas[idx].saldo -= valor;
    
    printf("Saque realizado! Novo saldo: %.2f\n", contas[idx].saldo);
    
    return 1;
}

int transferir(Conta contas[], int qtd, int origem, int destino, double valor) {
    
    int idxOrigem = encontrar_conta_por_numero(contas, qtd, origem);
    int idxDestino = encontrar_conta_por_numero(contas, qtd, destino);
    
    if (idxOrigem == -1 || idxDestino == -1) { printf("Erro: conta não encontrada.\n"); return 0; }
    if (contas[idxOrigem].status == ENCERRADA || contas[idxDestino].status == ENCERRADA) { printf("Erro: uma das contas encerrada.\n"); return 0; }
    if (valor <= 0) { printf("Erro: valor inválido.\n"); return 0; }
    if (valor > contas[idxOrigem].saldo) { printf("Erro: saldo insuficiente.\n"); return 0; }
    
    contas[idxOrigem].saldo -= valor;
    contas[idxDestino].saldo += valor;
    
    return 1;
}
