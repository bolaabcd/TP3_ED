//---------------------------------------------------------------------
// Arquivo      : ranking_documentos.cpp
// Conteudo     : arquivo de implementacao para ranking de documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "ranking_documentos.hpp"
#include "msgassert.hpp"
#include <fstream>

Ranking_Documentos::Ranking_Documentos(int tam)
{
    this->tamanho = tam;
    this->ids = new int[tam];
    this->vals = new double[tam];
}

void Ranking_Documentos::imprimir(std::string out_nome, int num_posicoes)
{
    std::ofstream out(out_nome);
    avisoAssert(num_posicoes <= this->tamanho, "Menos que 10 documentos, imprimindo rank com a quantidade presente de documentos.");
    for (int i = 0; i < num_posicoes && i < this->tamanho; i++)
    {
        if (this->vals[i] <= 0)
            break;
        out << this->ids[i] << " ";
    }
    out << std::endl;
    out.close();
}

void Ranking_Documentos::set_val(int pos, double val)
{
    this->vals[pos] = val;
}

void Ranking_Documentos::set_id(int pos, int id)
{
    erroAssert(this->ids != nullptr, "Lista de ids inexistente.");
    erroAssert(pos < tamanho && pos >= 0, "Tentativa de acessar posicao invalida.");
    this->ids[pos] = id;
}

int Ranking_Documentos::get_id(int pos)
{
    return this->ids[pos];
}

double Ranking_Documentos::get_val(int pos)
{
    return this->vals[pos];
}

void Ranking_Documentos::ordena()
{
    this->quicksort_interno(0, this->tamanho - 1);
}

bool Ranking_Documentos::menor_aux(int l, int r)
{
    if (this->vals[l] == this->vals[r])
        return this->ids[l] > this->ids[r];
    else
        return this->vals[l] < this->vals[r];
}

void Ranking_Documentos::quicksort_interno(int l, int r)
{
    if (l >= r)
        return;
    erroAssert(l < r, "Intervalo invalido no quicksort recursivo.");

    int meio = (l + r) / 2;
    int pivo = meio;
    if (this->menor_aux(l, r))
    {
        if (this->menor_aux(meio, l))
            pivo = l;
        else if (this->menor_aux(r, meio))
            pivo = r;
    }
    else
    {
        if (this->menor_aux(meio, r))
            pivo = r;
        else if (this->menor_aux(l, meio))
            pivo = l;
    }

    double aux = this->vals[pivo];
    int auxid = this->ids[pivo];
    int i, j;
    for (i = l, j = r;;)
    {
        for (; i <= j && (aux == this->vals[i] ? auxid > this->ids[i] : aux < this->vals[i]); i++)
            ;
        for (; i <= j && (aux == this->vals[j] ? this->ids[j] > auxid : this->vals[j] < aux); j--)
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

Ranking_Documentos::~Ranking_Documentos()
{
    delete[] this->ids;
    delete[] this->vals;
}