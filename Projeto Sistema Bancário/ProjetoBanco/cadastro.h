#ifndef CADASTRO_H
#define CADASTRO_H

#include "contas.h"

int abrir_conta(Conta contas[], int *qtd, int numero,
                char nome[], char cpf[], char agencia[], char telefone[]);

int atualizar_contato(Conta contas[], int qtd, int numero,
                      char novo_telefone[], char nova_agencia[]);

#endif


