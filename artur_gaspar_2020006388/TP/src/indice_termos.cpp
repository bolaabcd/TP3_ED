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

Indice_Termos::Indice_Termos(String_Hasher hasher, int tamanho_inicial)
{
    this->hasher = hasher;
    this->make_primos();
    this->tamanho_atual = this->get_next_tamanho(tamanho_inicial);
    this->mapa = new Lista_Lista_ID_Freqs[this->tamanho_atual];
}

Lista_ID_Freqs *Indice_Termos::get_lista_id_freqs(std::string termo)
{
    return mapa[this->hasher.get_hash(termo, this->tamanho_atual)].get_certo(termo);
}

void Indice_Termos::add_documento(
    std::string corpus,
    std::string documento,
    String_Set &stopw)
{
    int iddoc = this->getiddoc(documento);

    Leitor_Termos lei(corpus + "/" + documento, &stopw);

    while (1)
    {
        std::string palavra = lei.ler();
        if (!lei.ok())
            break;

        mapa[this->hasher.get_hash(palavra, this->tamanho_atual)].add_certo(palavra, iddoc);
    }
}

void Indice_Termos::ordena_tudo()
{
    for (int i = 0; i < this->tamanho_atual; i++)
        this->mapa[i].ordena_tudo();
}

void Indice_Termos::make_primos()
{
    // Gerado externamente
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
{
    for (int i = 0; i < 26; i++)
        if (this->tamanhos_primos_validos[i] > tam)
            return this->tamanhos_primos_validos[i];
    erroAssert(false, "Erro: quantidade de termos distintos grande demais.");
}

int Indice_Termos::getiddoc(std::string nome)
{
    std::string numrev;
    bool iniciou = false;
    for (int i = nome.size() - 1; i >= 0; i--)
    {
        if (iniciou && nome[i] < '0' || nome[i] > '9')
            break;
        else if (iniciou)
            numrev.push_back(nome[i]);
        else if (nome[i] >= '0' && nome[i] <= '9')
            iniciou = true;
    }
    std::string num;
    for (int i = numrev.size() - 1; i >= 0; i--)
        num.push_back(numrev[i]);
    return atoi(num.c_str());
}