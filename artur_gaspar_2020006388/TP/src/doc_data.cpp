//---------------------------------------------------------------------
// Arquivo      : doc_data.cpp
// Conteudo     : arquivo de implementacao para informacoes dos documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "doc_data.hpp"

Doc_Data::Doc_Data(int tam)
{
    this->ids = new int[tam];
    this->Wds = new double[tam];
    this->tamanho = tam;
}

int Doc_Data::size()
{
    return this->tamanho;
}

int Doc_Data::get_id(int pos)
{
    return this->ids[pos];
}

double Doc_Data::get_Wd(int pos)
{
    return this->Wds[pos];
}

void Doc_Data::set_id(int pos, int id)
{
    this->ids[pos] = id;
}

void Doc_Data::set_Wd(int pos, double Wd)
{
    this->Wds[pos] = Wd;
}