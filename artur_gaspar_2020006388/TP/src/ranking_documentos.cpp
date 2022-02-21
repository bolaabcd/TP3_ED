//---------------------------------------------------------------------
// Arquivo      : ranking_documentos.cpp
// Conteudo     : arquivo de implementacao para ranking de documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "ranking_documentos.hpp"
#include "msgassert.hpp"
#include <fstream>

Ranking_Documentos::Ranking_Documentos(int tam)
// Descricao: inicializa um ranking de documentos vazio.
// Entrada: tamanho do ranking.
// Saida: objeto inicializado.
{
    erroAssert(tam >= 0, "Quantidade de documentos negativa nao e permitido.");
    this->tamanho = tam;
    this->ids = new int[tam];
    this->vals = new double[tam];
}

void Ranking_Documentos::imprimir(std::string out_nome, int num_posicoes)
// Descricao: imprime os ids dos documentos mais relevantes.
// Entrada: arquivo de saida e numero de posicoes a imprimir.
// Saida: escreve no arquivo as num_posicoes primeiras posicoes.
{
    std::ofstream out(out_nome);
    erroAssert(!out.fail(), "Nao foi possivel abrir arquivo em que o ranking deve ser impresso.");
    int amt = 0;
    for (int i = 0; i < num_posicoes && i < this->tamanho; i++)
    {
        if (this->vals[i] <= 0)
            break;
        out << this->ids[i] << " ";
        amt++;
    }
    out << std::endl;
    out.close();
    if(amt < num_posicoes)
        avisoAssert(num_posicoes <= this->tamanho, "Menos documentos que a quantidade desejada possui algum termo da busca, imprimindo rank com a quantidade de documentos que efetivamente possuem o termo.");

}

void Ranking_Documentos::set_val(int pos, double val)
// Descricao: seta a relevancia de um arquivo.
// Entrada: posicao do arquivo cuja relevancia sera setada e o valor da relevancia.
// Saida: nada.
{
    erroAssert(pos < tamanho && pos >= 0, "Tentativa de acessar posicao invalida do ranking de documentos.");

    this->vals[pos] = val;
}

void Ranking_Documentos::set_id(int pos, int id)
// Descricao: seta o id de um arquivo.
// Entrada: posicao do arquivo cujo id sera setado e o valor do id.
// Saida: nada.
{
    erroAssert(this->ids != nullptr, "Lista de ids inexistente.");
    erroAssert(pos < tamanho && pos >= 0, "Tentativa de acessar posicao invalida do ranking de documentos.");

    this->ids[pos] = id;
}

int Ranking_Documentos::get_id(int pos)
// Descricao: retorna id do documento na posicao.
// Entrada: posicao.
// Saida: id.
{
    erroAssert(pos < tamanho && pos >= 0, "Tentativa de acessar posicao invalida do ranking de documentos.");

    return this->ids[pos];
}

double Ranking_Documentos::get_val(int pos)
// Descricao: retorna a relevancia do documento na posicao.
// Entrada: posicao.
// Saida: relevancia.
{
    erroAssert(pos < tamanho && pos >= 0, "Tentativa de acessar posicao invalida do ranking de documentos.");

    return this->vals[pos];
}

void Ranking_Documentos::ordena()
// Descricao: ordena o ranking por relevancia, e se a relevancia for igual coloca o com menor id primeiro.
// Entrada: nada.
// Saida: nada.
{
    this->quicksort_interno(0, this->tamanho - 1);
}

bool Ranking_Documentos::menor_aux(int l, int r)
// Descricao: compara os elementos das posicoes l e r.
// Entrada: posicoes l e r.
// Saida: verdadeiro se l deve vir depois de r, falso caso contrario.
{
    if (this->vals[l] == this->vals[r])
        return this->ids[l] > this->ids[r];
    else
        return this->vals[l] < this->vals[r];
}

void Ranking_Documentos::quicksort_interno(int l, int r)
// Descricao: metodo auxiliar recursivo usado pra ordenacao.
// Entrada: intervalo ordenado no momento.
// Saida: nada.
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

int Ranking_Documentos::size() 
// Descricao: informa a quantidade de documentos rankeados.
// Entrada: nada.
// Saida: quantidade de documentos no rank.
{
    return this->tamanho;
}

Ranking_Documentos::~Ranking_Documentos()
// Descricao: destrutor padrao do tipo.
// Entrada: nada.
// Saida: libera a memoria alocada no construtor.
{
    delete[] this->ids;
    delete[] this->vals;
}