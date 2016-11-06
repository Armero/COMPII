/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe.santos $
* $Date: 2016/11/05 23:29:54 $
* $Log: aula0903.c,v $
* Revision 1.1  2016/11/05 23:29:54  felipe.santos
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include "aula0901.h"
#include <stdlib.h>
#include <stdio.h>


/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define EOS			'\0'


/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{
  /*Vetor com o conteudo introduzido por linha de comando*/
  char entrada[TAMANHO_CONTEUDO + 1];
  char saida[TAMANHO_TOTAL + 3]; /* Espaco para \r\n\0 */ 
  byte numerosTemporarios [TAMANHO_CONTEUDO + 2]; /*um byte a mais + EOS*/
  byte contadorAuxiliar, verificadorDigito, iterador, posicoesSaida; /*indices auxiliares*/
  unsigned numeroBytes;
  short int numIteracoes, indice, temporario; /*indices que precisam ser inteiros devido a possibilidade de ser 0*/
  tipoErros status;
  saida[0] = EOS; /*inicializando saida com EOS na primeira posicao para evitar caracteres nao esperados*/
  
  /*Caso tenha mais ou menos argumentos que NUMERO_ARGUMENTOS_INVALIDOS*/
  if ( argc != NUMERO_ARGUMENTOS_VALIDOS)
  {
    printf ("Uso %s: <numero-de-argumentos-invalidos>\n", argv[0]);
    printf ("Por favor insira: <texto-a-ser-codificado>\n");
    exit(NUMERO_ARGUMENTOS_INVALIDOS);
  }

  numIteracoes = (byte) strlen(argv[1]);
  
  printf ("Resultado:\n");
  indice = 0;
  contadorAuxiliar = 4; /* Comeca com 3, pois de qualquer forma a entrada sera representada como 3 caracteres */
  posicoesSaida = 0;
  while (indice < numIteracoes)
  {

    /* Caso onde eh possivel completar um grupo de 3 bytes */
    if ( (numIteracoes - indice) >= 4)
    {
      /* elimina os casos problematicos */
      for (verificadorDigito = indice; verificadorDigito < indice + 4; verificadorDigito++)
          entrada[verificadorDigito % 4] = argv[1][verificadorDigito];
      numeroBytes = 4;

      status = DecodificarBase64 (entrada, numerosTemporarios, &numeroBytes);
               
      saida [posicoesSaida++] = numerosTemporarios [0];
      saida [posicoesSaida++] = numerosTemporarios [1];
      saida [posicoesSaida++] = numerosTemporarios [2];

      contadorAuxiliar += 1; /*quinto bit*/

      if (status == OK)
        for (iterador = (posicoesSaida - 3); iterador < posicoesSaida; iterador++)
          printf("%c",saida[iterador]);     

      /* + 1 devido ao EOS que e concatenado tambem */
      if ( ( (contadorAuxiliar + 1) == TAMANHO_TOTAL) || ( (contadorAuxiliar + 1) > TAMANHO_TOTAL) )
      {
        /*zera o contador para que so seja colocado \r\n depois de mais 76 caracteres*/
        contadorAuxiliar = 0;
        saida[0] = EOS;
      }
    }

    /* Caso onde nao eh completado um grupo de 3 bytes */
    else if ( (indice - numIteracoes)  < TAMANHO_TOTAL )
    {
      for (temporario = (numIteracoes - indice); temporario >= 0; temporario-- )
        entrada[temporario] = argv[1][indice + temporario];

      numeroBytes = (byte)(numIteracoes - indice);
      status = DecodificarBase64 (entrada, numerosTemporarios, &numeroBytes);

      saida [posicoesSaida++] = numerosTemporarios [0];
      saida [posicoesSaida++] = numerosTemporarios [1];
      saida [posicoesSaida++] = numerosTemporarios [2];

      if (status == OK)
        for (iterador = (posicoesSaida - 3); iterador < posicoesSaida; iterador++)
          printf("%c",saida[iterador]);

    }
    indice += 4;
    contadorAuxiliar += 4;
  }

  
  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/
  return (OK);
} 
/* $RCSfile: aula0903.c,v $ */
