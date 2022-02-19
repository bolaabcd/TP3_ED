//---------------------------------------------------------------------
// Arquivo      : ranking_documentos.hpp
// Conteudo     : arquivo de cabecalho para ranking de documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef RANKING_DE_DOCUMENTOS
#define RANKING_DE_DOCUMENTOS

#include <string>

class Ranking_Documentos
{
public:
    Ranking_Documentos(int tamanho);
    void imprimir(std::string out_nome, int num_posicoes);
    void set_Wd(int pos, double Wd);
    void set_id(int pos, int id);
    int get_id(int pos);
    double get_Wd(int pos);
    void ordena();

private:
    int tamanho;
    int *ids;
    double *vals;
    void quicksort_interno(int l, int r);
};

#endif