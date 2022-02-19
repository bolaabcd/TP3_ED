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
    void set_val(int pos, double val);
    void set_id(int pos, int id);
    int get_id(int pos);
    double get_val(int pos);
    void ordena();
    ~Ranking_Documentos();

private:
    int tamanho;
    int *ids;
    double *vals;
    void quicksort_interno(int l, int r);
    bool menor_aux(int l, int r);
};

#endif