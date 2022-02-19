//---------------------------------------------------------------------
// Arquivo      : ranking_documentos.cpp
// Conteudo     : arquivo de implementacao para ranking de documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "ranking_documentos.hpp"
#include "msgassert.hpp"
#include <fstream>

Ranking_Documentos::Ranking_Documentos(int tamanho)
{
    this->tamanho = tamanho;
}

void Ranking_Documentos::imprimir(std::string out_nome, int num_posicoes)
{
    std::ofstream out(out_nome);
    avisoAssert(num_posicoes <= this->tamanho, "Menos que 10 documentos, imprimindo rank com a quantidade presente de documentos.");
    for (int i = 0; i < num_posicoes && i < this->tamanho; i++)
    {
        out << this->ids[i] << " ";
    }
    out << std::endl;
    out.close();
}

void Ranking_Documentos::set_Wd(int pos, double Wd)
{
    this->vals[pos] = Wd;
}

void Ranking_Documentos::set_id(int pos, int id)
{
    this->ids[pos] = id;
}

int Ranking_Documentos::get_id(int pos)
{
    return this->ids[pos];
}

double Ranking_Documentos::get_Wd(int pos)
{
    return this->vals[pos];
}

void Ranking_Documentos::ordena()
{
    this->quicksort_interno(0, this->tamanho - 1);
}

void Ranking_Documentos::quicksort_interno(int l, int r)
{
    if (l >= r)
        return;
    erroAssert(l < r, "Intervalo invalido no quicksort recursivo.");

    int meio = (l + r) / 2;
    int pivo = meio;
    if (this->vals[l] < this->vals[r])
    {
        if (this->vals[meio] < this->vals[l])
            pivo = l;
        else if (this->vals[r] < this->vals[meio])
            pivo = r;
    }
    else
    {
        if (this->vals[meio] < this->vals[r])
            pivo = r;
        else if (this->vals[l] < this->vals[meio])
            pivo = l;
    }

    double aux = this->vals[pivo];
    int i, j;
    for (i = l, j = r;;)
    {
        for (; i <= j && aux < this->vals[i]; i++)
            ;
        for (; i <= j && this->vals[j] < aux; j--)
            ;

        if (i > j)
            break;

        // Trocando elementos
        double a = this->vals[i];
        this->vals[i] = this->vals[j];
        this->vals[j] = a;

        int aid = this->ids[i];
        this->ids[i++] = this->ids[j];
        this->ids[j--] = aid;
    }

    quicksort_interno(l, j);
    quicksort_interno(i, r);
}