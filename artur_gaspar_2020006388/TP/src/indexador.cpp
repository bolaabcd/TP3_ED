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
        std::string stri = dir_entry.path();
        Indice_Termos tmp(String_Hasher(), 0);
        int iddoc = tmp.getiddoc(stri);
        stri = std::to_string(iddoc) + ".txt";
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
        std::string stri = dir_entry.path();
        double Wd = 0;
        int iddoc = indice.getiddoc(stri);
        stri = std::to_string(iddoc) + ".txt";
        String_Set ja_lidos;
        Leitor_Termos lei(this->corpus + "/" + stri, &(this->stopw));
        while (1)
        {
            std::string termo = lei.ler();
            if (!lei.ok() || lei.eof())
                break;
            if (ja_lidos.is_in(termo))
                continue;
            ja_lidos.add(termo);
            double ft = indice.get_lista_id_freqs(termo)->size();
            double idf = log((double)this->ndocs / (double)ft);
            double ftd = indice.get_lista_id_freqs(termo)->get_freq(iddoc);
            Wd += (ftd * idf) * (ftd * idf);
        }
        Wd = sqrt(Wd);
        doc_data.set_id(i, iddoc);
        doc_data.set_Wd(i, Wd);
        i++;
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
        std::string stri = dir_entry.path();
        int iddoc = ans.getiddoc(stri);
        stri = std::to_string(iddoc) + ".txt";
        ans.add_documento(this->corpus, stri, this->stopw);
    }
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