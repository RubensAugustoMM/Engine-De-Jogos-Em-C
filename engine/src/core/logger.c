#include "logger.h"
#include "assert.h"

//TODO: remover estas inclusões quando a camada de plataforma for implementada
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void reportar_assercao_falha(const char* expressao, const char* mensagem, const char* arquivo, i32 linha){
    saida_log(
        NIVEL_LOG_FATAL,
        "FALHA EM ASSERCAO: %s mensagem: %s no arquivo: %s linha: %d\n",
        expressao,
        mensagem,
        arquivo,
        linha
    );
}

//Inicializa o sistema de logging
b8 inicializar_logging(){
    // TODO: Criar arquivo de log
    return TRUE;
}

//Finaliza sistema de logging
void finalizar_logging(){
    // TODO: Limpar arquivos na pilha de log/escrita
}


 void saida_log(nivel_log nivel, const char* mensagem, ...){
    const char* strings_de_nivel_log[6] = {
        "[FATAL]: ", 
        "[ERRO]: ",
        "[ALERTA]: ",
        "[INFORMACAO]: ",
        "[DEBUG]: ",
        "[TRACO]: "
    };

    i32 tamanho_maximo = 32000;

    //TODO: tornar a alocação de memória para a mensagem_saida dinâmica
    char mensagem_saida[tamanho_maximo];
    memset(mensagem_saida, 0, sizeof(mensagem_saida));

    __builtin_va_list ponteiro_de_argumentos;
    va_start(ponteiro_de_argumentos, mensagem);
    vsnprintf(mensagem_saida,tamanho_maximo, mensagem, ponteiro_de_argumentos);
    va_end(ponteiro_de_argumentos);

    char mensagem_saida2[tamanho_maximo];
    sprintf(mensagem_saida2, "%s%s\n", strings_de_nivel_log[nivel], mensagem_saida);

    printf("%s",mensagem_saida2);
}