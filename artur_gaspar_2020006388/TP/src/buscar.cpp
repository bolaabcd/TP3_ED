//---------------------------------------------------------------------
// Arquivo      : ordena.cpp
// Conteudo     : arquivo principal do programa ordena
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include <iostream>
#include <getopt.h>
#include <string>
#include "memlog.hpp"
#include "msgassert.hpp"

// variaveis globais para opcoes
std::string reg_nome, querry_nome, out_nome, corpus_nome, stop_nome;
int regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "buscar\n");
    fprintf(stderr, "\t-h      \t(obter ajuda) \n");
    fprintf(stderr, "\t-i <arq>\t(arquivo de consulta) \n");
    fprintf(stderr, "\t-o <arq>\t(arquivo de saida) \n");
    fprintf(stderr, "\t-c <arq>\t(pasta com documentos - corpus) \n");
    fprintf(stderr, "\t-s <arq>\t(arquivo de palavras a ignorar - stopwords) \n");
    fprintf(stderr, "\t-p <arq>\t(arquivo de registro de desempenho)\n");
    fprintf(stderr, "\t-l      \t(registrar padrao de acesso e localidade)\n");
}

void parse_args(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: 
{
}

int main(int argc, char **argv)
// Descricao: programa principal para ordenacao externa de URLs
// Entrada: argc e argv
// Saida: no arquivo especificado escreve o resultado ordenado
{
    // avaliar linha de comando
    parse_args(argc, argv);

    // iniciar registro de acesso
    iniciaMemLog(reg_nome, regmem, 0);

    // ativar registro de acesso
    ativaMemLog();

    // codigo aqui

    // conclui registro de acesso
    return finalizaMemLog();
}
