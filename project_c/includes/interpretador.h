/**
* @file interpretador.h
* \brief Ficheiro que suporta a interpretação de uma sequência de um ou mais comandos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib-2.0/glib.h>
#include "paginacao.h"
#include "auxiliares.h"
#include "sgr.h"

typedef enum{
    LT,
    EQ,
    GT
} OPERATOR;

typedef struct var *VAR;

/**
 * @brief
 * @param
 * @return
 */
char ** doRegex (const gchar *string);


/**
 * @brief Função que visualiza o valor de uma variável num formato visual, sob a forma de uma tabela
 * @param table table
 */
void show (TABLE table);


/**
 * @brief  Função que envia o conteúdo de uma variável para um ficheiro de formato csv
 * @param table table
 * @param delim separador
 * @param path ficheiro a formatar
 */
void toCSV(TABLE table, char delim, char path[]);


/**
 * @brief Função que atribui a uma variável o conteúdo de um ficheiro csv 
 * @param filepath ficheiro csv
 * @param delim separador
 * @return table que contém o conteúdo do ficheiro csv
 */
TABLE fromCSV(char filepath[] ,char *delim);


/**
 * @brief Função que compara o conteúdo de uma table, numa dada coluna, com o valor de comparação que é dado
 * @param content conteúdo da table recebida, numa dada coluna
 * @param value valor de comparação 
 * @param oper operador de comparação
 * @return zero se tiver sucesso, 1 caso contrário
 */ 
int compare(char* content, char* value, OPERATOR oper);


/**
 * @brief Função que filtra dados de uma tabela, dada uma coluna, um valor de comparação e um operador de comparação
 * @param table table
 * @param columName nome da coluna especifica cujos conteúdos serão comparados ao value
 * @param value valor de comparação
 * @param oper operador de comparação
 * @return table filtrada
 */
TABLE filter(TABLE table, char columName[], char* value, OPERATOR oper);


/**
 * @brief Função que obtém um subconjunto de colunas de uma tabela
 * @param table table
 * @param cols primeiras cols colunas
 * @return table com apenas o subconjunto de colunas
 */
TABLE proj(TABLE table, int cols);


/**
* @brief Função que acede a valores/registos contidos numa determinada posição da tabela
* @param table table 
* @param linha linha em que se encontra o valor/registo da tabela dada
* @param coluna coluna em que se encontra o valor/registo da tabela dada
* @return table com apenas o valor/registo contido numa determinada posição da tabela dada
*/
TABLE indexa (TABLE table, int linha, int coluna);


/**
 * @brief Funçaõ que retorna o máximo valor de uma dada coluna
 * @param table table
 * @param columName coluna da tabela dada
 * @return table com o maximo valor da coluna
 */
TABLE max(TABLE table, char columName[]);


/**
 * @brief Função que retorna o mínimo valor de uam dada coluna
 * @param table table
 * @param columName coluna da tabela dada
 * @return table com o m+inimo valor da coluna
 */ 
TABLE min(TABLE table, char columName[]);


/**
 * 
 */
int isAssignment(char *linha);


/**
 * 
 */
int interpretador();


