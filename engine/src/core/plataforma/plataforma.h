#pragma once

#include "definicoes.h"

typedef struct estado_da_plataforma{
    void* estado_da_plataforma;
} estado_da_plataforma;

b8 inicializar_plataforma(
    estado_da_plataforma* estado,
    const char* nome_da_aplicacao,
    i32 x,
    i32 y,
    i32 largura,
    i32 altura);

void finalizar_plataforma(estado_da_plataforma* estado);

b8 enviar_mensagens_da_plataforma(estado_da_plataforma* estado);

void* alocar_memoria(u64 tamanho, b8 alinhado);
void* liberar_memoria(void* bloco, b8 alinhado);
void* zerar_memoria(void* bloco, u64 tamanho);
void* copiar_memoria(void* destino, void* fonte, u64 tamanho);
void* definir_memoria(void* destiono, i32 valor, u64 tamanho);

void escrever_no_console(const char* mensagem, u8 cor);
void ecrever_erro_no_console(const char* mensagem, u8 cor);

f64 retornar_tempo_absoluto();