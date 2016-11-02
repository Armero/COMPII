/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date
* $Log: aula0701.h,v $
* Revision 1.2  2016/10/25 01:34:32  felipe
* Foi definido um novo tipo de erro
*
* Revision 1.1  2016/10/22 15:09:02  felipe
* Initial revision
*
*/


#ifndef _aula0701_
#define _aula0701_ "@(#)aula0701.h$Revisions$"

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#define		APAGADO				'0'	
#define		ACESO				'1'	

#define		NUMERO_MAXIMO_LINHAS		25
#define		NUMERO_MAXIMO_COLUNAS		80
 
#define		NUMERO_VALIDO_ARGUMENTOS	9
#define		T_SLEEP						1 /*infelizmente so aceita int -> nao da para diminuir o tempo*/

typedef enum	
{
	OK							= 0,
	NUMERO_INVALIDO_ARGUMENTOS 	= 1,
	ARGUMENTO_INVALIDO 			= 2,
    EXCEDE_LIMITES				= 3,
    PONTO_FORA_DOS_LIMITES		= 4,
    TAMANHO_NEGATIVO			= 5,
    POLIGONO_EXCEDE_LIMITES		= 6,
    PONTO_NAS_BORDAS			= 7,
}tipoErros;

typedef enum	
{
	apagado 			= APAGADO,
	aceso   			= ACESO,
}tipoPixel;

tipoErros
MostrarMonitor ( tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS], unsigned maximoLinhas, unsigned maximoColunas );

tipoErros
LimparMonitor ( tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                unsigned maximoLinhas, unsigned maximoColunas );

tipoErros
DesenharRetangulo ( tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], 
                    unsigned maximoLinhas, unsigned maximoColunas, unsigned linhaCantoSuperiorEsquerdo,
                    unsigned colunaCantoSuperiorEsquerdo, unsigned linhaCantoInferiorDireito, 
                    unsigned colunaCantoInferiorDireito );

tipoErros
PreencherPoligono ( tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS],
				    unsigned maximoLinhas, unsigned maximoColunas, unsigned linha, unsigned coluna);

#endif
