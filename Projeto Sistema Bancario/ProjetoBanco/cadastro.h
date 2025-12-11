#ifndef CADASTRO_H
#define CADASTRO_H

#include "contas.h"

int abrir_conta(Conta contas[], int *qtd, int numero, char nome[], char cpf[], char agencia[], char telefone[]);
void menu_atualizar_cadastro(Conta contas[], int qtd);

#endif


