//---------------------------------------------------------------------
// Arquivo      : id_freq.hpp
// Conteudo     : arquivo de cabecalho para par ID-Frequencia de aparicao.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef ID_FEQUENCIA_DE_APARICAO
#define ID_FEQUENCIA_DE_APARICAO

class ID_Freq
{
public:
    ID_Freq(int id, int freq);
    ID_Freq();
    int id;
    int freq;
    bool operator<(ID_Freq &outro);
};

#endif