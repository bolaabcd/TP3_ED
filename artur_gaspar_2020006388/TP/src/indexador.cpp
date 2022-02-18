//---------------------------------------------------------------------
// Arquivo      : indexador.cpp
// Conteudo     : arquivo de implementacao para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "indexador.hpp"
#include "leitor_termos.hpp"
#include <sstream>
#include <filesystem>
#include <string>

Indexador::Indexador(std::string corpus_path, std::string stopwords_path)
{
    this->corpus = corpus_path;
    this->stopwords = stopwords_path;
    String_Set vazio;
    arq_pra_set(stopwords_path, this->stopw, vazio);
    std::filesystem::path caminho(corpus_path);

    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        arq_pra_set(corpus_path + "/" + stri, this->termos, this->stopw);
    }
}

void Indexador::cria_indice(Indice_Termos &ans)
{
    std::filesystem::path caminho(this->corpus);

    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        // std::cout << dir_entry << '\n';
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        ans.add_documento(this->corpus, stri, this->stopw);
    }
}

void Indexador::arq_pra_set(std::string caminho, String_Set &ans, String_Set &proibidos)
{
    std::ifstream arq(caminho);

    while (true)
    {
        Leitor_Termos lei(caminho, &proibidos);
        std::string palavra = lei.ler();
        if (!lei.ok())
            break;
        ans.add(palavra);
    }
}

int Indexador::quantos_termos(std::string corpus_path)
{
    return this->termos.size();
}