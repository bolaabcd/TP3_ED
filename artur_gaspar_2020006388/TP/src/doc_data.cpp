//---------------------------------------------------------------------
// Arquivo      : doc_data.cpp
// Conteudo     : arquivo de implementacao para informacoes dos documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "doc_data.hpp"

Doc_Data::Doc_Data(int tam)
// Descricao: inicializa um vetor de ids e outro de Wds pros documentos.
// Entrada: tamanho inicial.
// Saida: inicializa ids, Wds e tamanho.
{
    this->ids = new int[tam];
    this->Wds = new double[tam];
    this->tamanho = tam;
}

int Doc_Data::size()
// Descricao: retorna a quantidade de documentos.
// Entrada: nada.
// Saida: quantidade de documentos.
{
    return this->tamanho;
}

int Doc_Data::get_id(int pos)
// Descricao: retorna o id de um documento.
// Entrada: posicao em questao.
// Saida: id do documento na posicao.
{
    return this->ids[pos];
}

double Doc_Data::get_Wd(int pos)
// Descricao: retorna o Wd de um documento.
// Entrada: posicao em questao.
// Saida: Wd do documento na posicao.
{
    return this->Wds[pos];
}

void Doc_Data::set_id(int pos, int id)
// Descricao: seta o id de um documento.
// Entrada: posicao e valor a setar.
// Saida: nada.
{
    this->ids[pos] = id;
}

void Doc_Data::set_Wd(int pos, double Wd)
// Descricao: seta o Wd de um documento.
// Entrada: posicao e valor a setar.
// Saida: nada.
{
    this->Wds[pos] = Wd;
}

Doc_Data::~Doc_Data()
// Descricao: destroi a estrutura.
// Entrada: nada.
// Saida: nada.
{
    delete[] this->ids;
    delete[] this->Wds;
}