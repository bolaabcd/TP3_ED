//---------------------------------------------------------------------
// Arquivo      : indice_termos.cpp
// Conteudo     : arquivo de implementacao para indice de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "indice_termos.hpp"
#include "msgassert.hpp"
#include "leitor_termos.hpp"
#include <fstream>
#include <sstream>

Indice_Termos::Indice_Termos(String_Hasher hsher, int tamanho_inicial)
// Descricao: inicializa um indice reverso com um tamanho inicial e todas entradas vazias.
// Entrada: hash a utilizar e tamanho inicial (que na verdade nao muda durante a execucao do programa).
// Saida: objeto inicializado.
{
    erroAssert(tamanho_inicial >= 0, "Tamanho de indice invalido.");
    this->hasher = hsher;
    this->make_primos();
    this->tamanho_atual = this->get_next_tamanho(2*tamanho_inicial);
    this->mapa = new Lista_Lista_ID_Freqs[this->tamanho_atual];
}

Lista_ID_Freqs *Indice_Termos::get_lista_id_freqs(std::string termo)
// Descricao: retorna a lista de ids e frequencias associadas ao termo passado como argumento.
// Entrada: termo cuja lista sera retornada.
// Saida: apontador pra lista correspondente ao termo, ou um apontador nulo se ele nao estiver presente no corpus.
{
    int pos = this->hasher.get_hash(termo, this->tamanho_atual);
    erroAssert(pos < this->tamanho_atual && pos >= 0, "Tentativa de acesso a posicao de indice invalida.");
    return this->mapa[this->hasher.get_hash(termo, this->tamanho_atual)].get_certo(termo);
}

void Indice_Termos::add_documento(
    std::string corpus,
    std::string documento,
    String_Set &stopw)
// Descricao: adiciona todos os termos de um documento ao indice.
// Entrada: caminhos para o corpus e para o documento a ser adicionado, e conjunto de palavras a ignorar.
// Saida: nada.
{
    int iddoc = this->getiddoc(documento);
    erroAssert(iddoc >= 0, "ID de um documento nao pode ser negativo.");

    Leitor_Termos lei(corpus + "/" + documento, &stopw);

    while (1)
    {
        std::string palavra = lei.ler();
        if (!lei.ok() || lei.eof())
            break;
        int pos = this->hasher.get_hash(palavra, this->tamanho_atual);
        erroAssert(pos < this->tamanho_atual && pos >= 0, "Tentativa de acesso a posicao de indice invalida.");
        mapa[pos].add_certo(palavra, iddoc);
    }
}

void Indice_Termos::make_primos()
// Descricao: cria a lista dos 26 tamamnhos primos que o nosso programa pode utilizar.
// Entrada: nada.
// Saida: nada.
{
    // Gerado externamente com crivo linear
    this->tamanhos_primos_validos = new int[26]{
        17,
        37,
        71,
        137,
        277,
        547,
        1091,
        2179,
        4357,
        8707,
        17417,
        34819,
        69653,
        139267,
        278543,
        557057,
        1114117,
        2228243,
        4456451,
        8912921,
        17825803,
        35651593,
        71303171,
        142606357,
        285212677,
        570425377,
    };
}

int Indice_Termos::get_next_tamanho(int tam)
// Descricao: obtem o primeiro tamanho valido maior que o passado como argumento.
// Entrada: tamanho cujo primeiro primo maior sera encontrado.
// Saida: primeiro primo da lista maior que a entrada.
{
    for (int i = 0; i < 26; i++)
        if (this->tamanhos_primos_validos[i] > tam)
            return this->tamanhos_primos_validos[i];
    erroAssert(false, "Numero pedido grande demais (provavelmente a quantidade de termos distintos no corpus eh poderosa demais para esse humilde programa).");
}

int Indice_Termos::getiddoc(std::string nome)
// Descricao: obtem o id de um documento a partir de seu nome.
// Entrada: nome do documento, que deve ser seu id seguido de .txt ou outro formato de extensao.
// Saida: id do documento.
{
    std::string numrev;
    bool iniciou = false;
    for (int i = nome.size() - 1; i >= 0; i--)
    {
        if (iniciou && (nome[i] < '0' || nome[i] > '9'))
            break;
        else if (iniciou)
            numrev.push_back(nome[i]);
        else if (nome[i] >= '0' && nome[i] <= '9')
        {
            iniciou = true;
            i++;
        }
    }
    std::string num;
    for (int i = numrev.size() - 1; i >= 0; i--)
        num.push_back(numrev[i]);
    return atoi(num.c_str());
}

int Indice_Termos::get_tamanho_usado()
// Descricao: informa, para fins de depuracao, a quantidade de entradas na tabela de hash efetivamente usada.
// Entrada: nada.
// Saida: quantidade de entradas da tabela efetivamente usadas.
{
    int ans = 0;
    for (int i = 0; i < this->tamanho_atual; i++)
    {
        if (this->mapa[i].get_tamanho() > 0)
            ans++;
    }
    return ans;
}

Indice_Termos::~Indice_Termos()
// Descricao: destrutor padrao do indice, que limpa a memoria alocada pelo mesmo.
// Entrada: nada.
// Saida: nada.
{
    if(this->mapa != nullptr)
        delete[] this->mapa;
    if(this->tamanhos_primos_validos != nullptr)
        delete[] this->tamanhos_primos_validos;
}