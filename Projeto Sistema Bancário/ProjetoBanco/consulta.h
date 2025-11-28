#ifndef CONSULTA_H
#define CONSULTA_H

#include "contas.h"

int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char *cpf);
void consultar_por_cpf(const Conta contas[], int qtd);
void consultar_por_numero(const Conta contas[], int qtd);
void menu_consulta(const Conta contas[], int qtd);
void mostrar_dados(const Conta *c);
void listar_contas(const Conta contas[], int qtd);
void encerrar_conta(Conta contas[], int qtd);
void esperar_tecla();

#endif

