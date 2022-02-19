//---------------------------------------------------------------------
// Arquivo      : indexador.cpp
// Conteudo     : arquivo de implementacao para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "indexador.hpp"
#include "leitor_termos.hpp"
#include <cmath>
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
    this->ndocs = 0;

    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        this->ndocs++;
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        arq_pra_set(corpus_path + "/" + stri, this->termos, this->stopw);
    }

    this->ndocs = ndocs;
}

void Indexador::cria_doc_data(Doc_Data &doc_data, Indice_Termos &indice)
{
    int i = 0;
    std::filesystem::path caminho(this->corpus);
    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        this->ndocs++;
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        double Wd = 0;
        int iddoc = indice.getiddoc(stri);
        while (1)
        {
            Leitor_Termos lei(this->corpus + "/" + stri, &(this->stopw));
            std::string termo = lei.ler();
            if (!lei.ok() || lei.eof())
                break;
            double ft = indice.get_lista_id_freqs(termo)->size();
            double idf = log((double)this->ndocs / (double)ft);
            double ftd = indice.get_lista_id_freqs(termo)->get_freq(iddoc);
            Wd += (ftd * idf) * (ftd * idf);
        }
        Wd = sqrt(Wd);
        doc_data.set_id(i, iddoc);
        doc_data.set_Wd(i, Wd);
    }
}

int Indexador::quantos_docs()
{
    return ndocs;
}

String_Set &Indexador::get_stopw()
{
    return this->stopw;
}

void Indexador::cria_indice(Indice_Termos &ans)
{
    std::filesystem::path caminho(this->corpus);

    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        ans.add_documento(this->corpus, stri, this->stopw);
    }

    ans.ordena_tudo();
}

void Indexador::arq_pra_set(std::string caminho, String_Set &ans, String_Set &proibidos)
{
    std::ifstream arq(caminho);

    Leitor_Termos lei(caminho, &proibidos);
    while (true)
    {
        std::string palavra = lei.ler();
        if (!lei.ok() || lei.eof())
            break;
        ans.add(palavra);
    }
}

int Indexador::quantos_termos(std::string corpus_path)
{
    return this->termos.size();
}