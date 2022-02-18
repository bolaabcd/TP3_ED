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
#include "indexador.hpp"
#include "processador_consultas.hpp"
#include "ranking_documentos.hpp"

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
// Saida: reg_nome, querry_nome, out_nome, corpus_nome, stop_nome, regmem
{
    // tratando caso de nao ter argumentos
    if (argc == 1)
    {
        uso();
        exit(1);
    }

    // variavel externa do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes

    regmem = 0;
    reg_nome[0] = 0;
    querry_nome[0] = 0;
    out_nome[0] = 0;
    corpus_nome[0] = 0;
    stop_nome[0] = 0;
    bool i = false, o = false, c = false, s = false, p = false;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "i:o:c:s:p:hl")) != EOF)
    {
        switch (c)
        {
        case 'i':
            avisoAssert(!i, "Mais de um arquivo de consulta passado, o ultimo sera usado.");
            i = true;
            querry_nome = optarg;
            break;
        case 'o':
            avisoAssert(!o, "Mais de um arquivo de saida passado, o ultimo sera usado.");
            o = true;
            out_nome = optarg;
        case 'c':
            avisoAssert(!c, "Mais de uma pasta de documentos passada, a ultima sera usada.");
            c = true;
            corpus_nome = optarg;
            break;
        case 's':
            avisoAssert(!s, "Mais de um arquivo de stopwords passado, o ultimo sera usado.");
            s = true;
            stop_nome = optarg;
            break;
        case 'p':
            avisoAssert(!p, "Mais de um arquivo de registro passado, o ultimo sera usado.");
            p = true;
            reg_nome = optarg;
            break;
        case 'l':
            regmem = 1;
            break;
        case 'h':
        default:
            uso();
            exit(1);
        }
    }
    // verificacao da consistencia das opcoes
    erroAssert(reg_nome.length() > 0,
               "buscar - nome de arquivo de registro de acesso tem que ser definido.");
    erroAssert(querry_nome.length() > 0,
               "buscar - nome de arquivo de consulta tem que ser definido.");
    erroAssert(out_nome.length() > 0,
               "buscar - nome de arquivo de saida tem que ser definido.");
    erroAssert(corpus_nome.length() > 0,
               "buscar - nome da pasta de documentos tem que ser definido.");
    erroAssert(stop_nome.length() > 0,
               "buscar - nome de arquivo de stopwords tem que ser definido.");
}

int main(int argc, char **argv)
// Descricao: programa principal para indexacao e busca de documentos
// Entrada: argc e argv
// Saida: no arquivo especificado escreve os 10 melhores documentos pra busca dada
{
    // avaliar linha de comando
    parse_args(argc, argv);

    // iniciar registro de acesso
    iniciaMemLog(reg_nome, regmem, 0);

    // ativar registro de acesso
    ativaMemLog();

    Indexador ind;

    Indice_Termos iter(String_Hasher(), 16);
    ind.cria_indice(corpus_nome, stop_nome, iter);

    Processador_Consultas pcs;

    Ranking_Documentos ran = pcs.consultar(iter, querry_nome, 10);

    ran.imprimir(out_nome);

    // conclui registro de acesso
    return finalizaMemLog();
}
