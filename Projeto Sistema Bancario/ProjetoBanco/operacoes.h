#ifndef OPERACOES_H
#define OPERACOES_H

#include "contas.h"

int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero);
int depositar(Conta contas[], int qtd, int numero, double valor);
int sacar(Conta contas[], int qtd, int numero, double valor);
int transferir(Conta contas[], int qtd, int origem, int destino, double valor);

#endif


