//---------------------------------------------------------------------
// Arquivo      : doc_data.hpp
// Conteudo     : arquivo de cabecalho para informacoes dos documentos.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef DOCUMENTOS_INFORMACOES_SOBRE
#define DOCUMENTOS_INFORMACOES_SOBRE

class Doc_Data
{
public:
    Doc_Data(int tamanho);
    int size();
    int get_id(int pos);
    double get_Wd(int pos);
    void set_id(int pos, int id);
    void set_Wd(int pos, double Wd);
    ~Doc_Data();

private:
    int *ids;
    double *Wds;
    int tamanho;
};

#endif