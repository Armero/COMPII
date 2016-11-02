/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/10/25 01:34:01 $
* $Log: aula0702.c,v $
* Revision 1.2  2016/10/25 01:34:01  felipe
* Arrumado alguns bugs
*
* Revision 1.2  2016/10/25 03:01:32  felipe.santos
* Corrigido o print de erro
*
* Revision 1.1  2016/10/22 15:09:02  felipe
* Initial revision
*
*/

/*Espaco reservado para os includes*/

#include <stdlib.h>
#include <stdio.h>
#include "aula0701.h"

/*Fim dos includes*/


/*Espaco reservado para definir as macros*/

#define EOS			'\0'

/*Fim do espaco reservado para definir as macros*/

int
main ( int argc, char *argv[] )
{

  char *verificacao;
  unsigned linhas, colunas,linhaCantoSuperiorEsquerdo, colunaCantoSuperiorEsquerdo, linhaCantoInferiorDireito, colunaCantoInferiorDireito, linhaPontoDentroPoligono, colunaPontoDentroPoligono;

  unsigned indice, maximoLinhas, maximoColunas;  

  tipoErros dadoErro;
  tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

  /*Caso o usuario digite menos ou mais que dois argumentos */
  if ( argc != NUMERO_VALIDO_ARGUMENTOS )
  {
    printf ("\n\nUso: %s <numero-errado-de-argumentos>\n", argv[0]); 
    printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas> <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo> <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito> \n");
    exit (NUMERO_INVALIDO_ARGUMENTOS);
  }	

  for ( indice = 1; indice < argc; indice++ )
  {
    if ( argv [indice][0] == '-' )
    {
      printf ("\n\nUso: %s <argumento-%d-invalido>\n", argv[0], indice); 
      printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas> <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo> <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito> \n");
      exit (NUMERO_INVALIDO_ARGUMENTOS);
    }
    
    switch (indice)
    {
      case 1:
        linhas = (unsigned) strtoul (argv[indice], &verificacao, 10); 
        break;
      case 2:
        colunas = (unsigned) strtoul (argv[indice], &verificacao, 10);      
        break;
      case 3:
        linhaCantoSuperiorEsquerdo = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
      case 4:
        colunaCantoSuperiorEsquerdo = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
      case 5:
        linhaCantoInferiorDireito = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
      case 6:
        colunaCantoInferiorDireito = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
      case 7:
        linhaPontoDentroPoligono = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
      case 8:
        colunaPontoDentroPoligono = (unsigned) strtoul (argv[indice], &verificacao, 10);
        break;
    }

    if ( *verificacao != EOS ) 
    {
      printf ("\n\nUso: %s <argumento-%d-invalido>\n", argv[0], indice); 
      printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas>\
       <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo>\
        <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito>\
         <coordenada-da-linha-de-um-ponto-dentro-do-poligono> <coordenada-da-coluna-de-um-ponto-dentro-do-poligono>\n");
      exit (NUMERO_INVALIDO_ARGUMENTOS);
    }
  } 

    maximoLinhas =  (unsigned) linhas;
    maximoColunas = (unsigned) colunas; 
    // dadoErro = MostrarMonitor ( monitor, maximoLinhas, maximoColunas );

    dadoErro  = LimparMonitor ( monitor, maximoLinhas, maximoColunas );

    if ( dadoErro == OK )
      dadoErro = DesenharRetangulo (monitor, maximoLinhas, maximoColunas, 
                                    linhaCantoSuperiorEsquerdo, colunaCantoSuperiorEsquerdo, 
                                    linhaCantoInferiorDireito, colunaCantoInferiorDireito);

    if ( (linhaPontoDentroPoligono == linhaCantoSuperiorEsquerdo) || (linhaPontoDentroPoligono == linhaCantoInferiorDireito) )
      dadoErro = PONTO_NAS_BORDAS;

    if ( (colunaPontoDentroPoligono == colunaCantoSuperiorEsquerdo) || (colunaPontoDentroPoligono == colunaCantoInferiorDireito) )
      dadoErro = PONTO_NAS_BORDAS;    

    if ( dadoErro == OK )
      dadoErro = PreencherPoligono ( monitor, maximoLinhas, maximoColunas, (linhaPontoDentroPoligono - 1), (colunaPontoDentroPoligono - 1));

    if ( dadoErro == EXCEDE_LIMITES ) 
    {
      printf ("\n\nUso: %s <os-valores-de-linha-e/ou-coluna-execedem-o-maximo-do-programa> \n", argv[0]);       
      printf ("\n\nUso: %s <MAXIMO_DE_LINHAS: %u> <MAXIMO_DE_COLUNAS: %u> \n", argv[0], NUMERO_MAXIMO_LINHAS, NUMERO_MAXIMO_COLUNAS);
      printf ("\n\nO indice das linhas e colunas deve ser positivo");  
      printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas>\
       <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo>\
        <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito>\
         <coordenada-da-linha-de-um-ponto-dentro-do-poligono> <coordenada-da-coluna-de-um-ponto-dentro-do-poligono>\n");
      exit (EXCEDE_LIMITES);
    }

    if ( dadoErro == TAMANHO_NEGATIVO )
    {
      printf ("\n\nUso: %s <o-poligo-tem-tamanho-negativo> \n", argv[0]);
      printf ("Por favor insira os argumentos na ordem correta\n");       
      printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas>\
       <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo>\
        <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito>\
         <coordenada-da-linha-de-um-ponto-dentro-do-poligono> <coordenada-da-coluna-de-um-ponto-dentro-do-poligono>\n");
      exit (TAMANHO_NEGATIVO);
    }

    if ( dadoErro == POLIGONO_EXCEDE_LIMITES )
    {
      printf ("\n\nUso: %s <as-dimensoes-do-poligono-excedem-os-limites-do-programa> \n", argv[0]);       
      printf ("\n\nUso: %s <MAXIMO_DE_LINHAS: %u> <MAXIMO_DE_COLUNAS: %u> \n", argv[0], NUMERO_MAXIMO_LINHAS, NUMERO_MAXIMO_COLUNAS); 
      printf ("Por favor insira os argumentos no formato: <numero-de-linhas> <numero-de-colunas>\
       <coordenada-da-linha-do-canto-superior-esquerdo> <coordenada-da-coluna-do-canto-superior-esquerdo>\
        <coordenada-da-linha-do-canto-inferior-direito> <coordenada-da-coluna-do-canto-inferior-direito>\
         <coordenada-da-linha-de-um-ponto-dentro-do-poligono> <coordenada-da-coluna-de-um-ponto-dentro-do-poligono>\n");      
      exit (POLIGONO_EXCEDE_LIMITES);
    }

    if ( dadoErro == PONTO_FORA_DOS_LIMITES )
    {
      printf("\n\nUso: %s <ponto-fora-dos-limites-do-poligono>\n", argv[0]);
      printf("\n\nPor favor insira um ponto dentro dos limites do poligono\n");
      exit (PONTO_FORA_DOS_LIMITES);
    }

    if ( dadoErro == PONTO_NAS_BORDAS)
    {
      printf("\n\nUso: %s <ponto-nas-bordas-do-poligono>\n", argv[0]); 
      printf("\n\nPor favor insira um ponto dentro dos limites do poligono\n");
      exit (PONTO_FORA_DOS_LIMITES);
    }

  /* Caso o programa o input do usuario tenha sido feito de maneira correta*/
  return (OK);
} 
