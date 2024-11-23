#pragma once

#include "definicoes.h"

#define LOG_ALERTA_ATIVO 1
#define LOG_INFORMACAO_ATIVO 1
#define LOG_DEBUG_ATIVO 1
#define LOG_TRACO_ATIVO 1

#if KRLEASE == 1
    #define LOG_DEBUG_ATIVO 0
    #define LOG_TRACO_ATIVO 0
#endif

typedef enum nivel_log {
    NIVEL_LOG_FATAL = 0,
    NIVEL_LOG_ERRO = 1,
    NIVEL_LOG_ALERTA = 2,
    NIVEL_LOG_INFORMACAO = 3,
    NIVEL_LOG_DEBUG = 4,
    NIVEL_LOG_TRACO = 5
} nivel_log;

b8 inicializar_logging();
void finalizar_logging();
KAPI void saida_log(nivel_log nivel, const char* mensagem, ...);

#define KFATAL(mensagem, ...) saida_log(NIVEL_LOG_FATAL, mensagem, ##__VA_ARGS__) 
#define KERRO(mensagem, ...) saida_log(NIVEL_LOG_ERRO, mensagem, ##__VA_ARGS__)

#if LOG_ALERTA_ATIVO == 1
    #define KALERTA(mensagem, ...) saida_log(NIVEL_LOG_ALERTA, mensagem, ##__VA_ARGS__)
#else
    #define KALERTA(mensagem, ...)
#endif

#if LOG_INFORMACAO_ATIVO == 1
    #define KINFORMACAO(mensagem, ...) saida_log(NIVEL_LOG_INFORMACAO, mensagem, ##__VA_ARGS__)
#else
    #define KINFORMACAO(mensagem, ...)
#endif

#if LOG_DEBUG_ATIVO ==1
    #define KDEBUG(mensagem, ...) saida_log(NIVEL_LOG_DEBUG, mensagem, ##__VA_ARGS__)
#else
    #define KDEBUG(mensagem, ...)
#endif

#if LOG_TRACO_ATIVO ==1
    #define KTRACO(mensagem, ...) saida_log(NIVEL_LOG_TRACO, mensagem, ##__VA_ARGS__)
#else
    #define KTRACO(mensagem, ...)
#endif