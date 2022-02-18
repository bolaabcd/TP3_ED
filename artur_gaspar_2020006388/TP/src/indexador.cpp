//---------------------------------------------------------------------
// Arquivo      : indexador.cpp
// Conteudo     : arquivo de implementacao para indexador de termos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "indexador.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

Indexador::Indexador() {}

void Indexador::cria_indice(std::string corpus_path, std::string stopwords_path, Indice_Termos &ans)
{
    Stopwords_Set stopw;
    pega_stopwords(stopwords_path, stopw);

    std::filesystem::path caminho(corpus_path);

    for (const std::filesystem::directory_entry &dir_entry :
         std::filesystem::directory_iterator(caminho))
    {
        // std::cout << dir_entry << '\n';
        std::string stri;
        std::stringstream strstream(stri);
        strstream << dir_entry;
        ans.add_documento(stri, stopw);
    }
}

void Indexador::pega_stopwords(std::string stopwords_path, Stopwords_Set &ans)
{
    std::ifstream arq(stopwords_path);

    while (true)
    {
        std::string palavra;
        arq >> palavra;
        limpa_pontuacao(palavra);
        to_lowercase(palavra);

        // Pode ser que tenham surgido varias palavras
        std::stringstream stream(palavra);
        std::string plvra;
        while (stream >> plvra)
        {
            if (plvra.length() > 0)
                ans.add(plvra);
        }
    }
}

void Indexador::limpa_pontuacao(std::string &palavra)
{
    for (int i = 0; i < palavra.length(); i++)
        if (
            palavra[i] == ',' ||
            palavra[i] == '.' ||
            palavra[i] == ';' ||
            palavra[i] == ':' ||
            palavra[i] == '?' ||
            palavra[i] == '!' ||
            palavra[i] == '(' ||
            palavra[i] == ')' ||
            palavra[i] == '[' ||
            palavra[i] == ']' ||
            palavra[i] == '{' ||
            palavra[i] == '}' ||
            palavra[i] == '=' ||
            palavra[i] == '-' ||
            palavra[i] == '+' ||
            palavra[i] == '_' ||
            palavra[i] == "'"[0] ||
            palavra[i] == '"' ||
            palavra[i] == '@' ||
            palavra[i] == '#' ||
            palavra[i] == '$' ||
            palavra[i] == '%' ||
            palavra[i] == '&' ||
            palavra[i] == '|' ||
            palavra[i] == '\\' ||
            palavra[i] == '/' ||
            palavra[i] == 'º' ||
            palavra[i] == '°' ||
            palavra[i] == 'ª' ||
            palavra[i] == '<' ||
            palavra[i] == '>' ||
            palavra[i] == '~' ||
            palavra[i] == '*' ||
            palavra[i] == '^')
            palavra[i] = ' ';
}

void to_lowercase(std::string &palavra)
{
    for (int i = 0; i < palavra.length(); i++)
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
}