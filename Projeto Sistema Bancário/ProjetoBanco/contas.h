#ifndef CONTAS_H
#define CONTAS_H

#define MAX_CONTAS 100
#define TAM_NOME 100
#define TAM_CPF 15
#define TAM_AGENCIA 10
#define TAM_TELEFONE 20

#define ATIVA 1
#define ENCERRADA 0

typedef struct {
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char agencia[TAM_AGENCIA];
    char telefone[TAM_TELEFONE];
    double saldo;
    int status;
} Conta;

#endif
