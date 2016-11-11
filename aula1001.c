/* 
* Universidade Federal do Rio de Janeiro
* Escola Politecnica
* Departamento de Eletronica e de Computacao
* EEL270 - Computacao II - Turma 2016/2
* Prof. Marcelo Luiz Drumond Lanza
* Autor: Felipe Claudio da Silva Santos

* $Author: felipe $
* $Date: 2016/11/11 01:32:29 $
* $Log: aula1001.c,v $
* Revision 1.1  2016/11/11 01:32:29  felipe
* Initial revision
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define		NUMERO_ARGUMENTOS_VALIDOS	   2
#define		TAMANHO_LINHA			           1024
#define 	EOS				                   '\0'
#define		TAMANHO_NOME_ARQUIVO		     55 /*50 caracteres + .bak + EOS*/

/*Espaco reservado para os includes*/

typedef enum
{
  OK,
  NUMERO_ARGUMENTOS_INVALIDOS,
  IMPOSSIVEL_ABRIR_ARQUIVO_ENTRADA,
  IMPOSSIVEL_CRIAR_ARQUIVO_TEMPORARIO,
  IMPOSSIVEL_ABRIR_ARQUIVO_TEMPORARIO,
  IMPOSSIVEL_CRIAR_ARQUIVO,
  ARQUIVO_CORROMPIDO,
} tipoErros;

int
main (int argc, char *argv[])
{
  FILE *entrada, *temporario;
  int tempNumero;
  unsigned indice, linhas;
  char nomeTemporario[7];
  char conteudoLinha [TAMANHO_LINHA + 3];
  char novoNome [TAMANHO_NOME_ARQUIVO];
  enum {falso, verdadeiro} possivelErro;
  
  if (argc != NUMERO_ARGUMENTOS_VALIDOS)
  {
    printf ("Uso: %s <numero-argumentos-invalidos>\n", argv[0]);
    printf ("Por favor insira <nome-do-arquivo-a-ser-convertido>\n");
    exit (NUMERO_ARGUMENTOS_VALIDOS);
  }
  
  if ( !( entrada = fopen(argv[1], "r") ) )
  {
    printf ("Uso: %s <arquivo-inexistente> \"%s\"\n", argv[0], argv[1]);
    printf ("Por favor insira <nome-do-arquivo-a-ser-convertido>\n");
    exit (IMPOSSIVEL_ABRIR_ARQUIVO_ENTRADA);
  }
  
  strcpy (nomeTemporario, "XXXXXX");
  if ( (tempNumero = mkstemp(nomeTemporario)) == -1)
  {
    printf ("Nao foi possivel criar o arquivo temporario\n");
    #ifdef _MY_DEBUG_
      printf ("Erro (#%d): %s", errno, strerror(errno));
    #endif
    fclose (entrada);
    exit (IMPOSSIVEL_CRIAR_ARQUIVO_TEMPORARIO);
  }
  
  if ( !( temporario = fdopen(tempNumero, "w")) )
  {
    printf ("Nao foi possivel abrir o arquivo temporario\n");
    #ifdef _MY_DEBUG_
      printf ("Erro (#%d): %s", errno, strerror (errno));
    #endif
    fclose (entrada);
    exit (IMPOSSIVEL_ABRIR_ARQUIVO_TEMPORARIO);
  }
  
  linhas = 0;
  possivelErro = verdadeiro;
  while ( fgets (conteudoLinha, TAMANHO_LINHA, entrada) )
  {
    indice = strlen (conteudoLinha);
    if ( (conteudoLinha[indice - 1] != '\n') && (!possivelErro) )
    {
      printf ("Arquivo \"%s\" corrompido - linha muito longa\n", argv[1]);
      fclose (entrada);
      fclose (temporario);
      remove (nomeTemporario); /*testar para ver se esta removendo certo */
      exit (ARQUIVO_CORROMPIDO);
    }
    
    if ( conteudoLinha[indice - 1] == '\n')
    {
      conteudoLinha[indice - 1] = EOS;
      possivelErro = verdadeiro;
    }
    else
      possivelErro = falso;

    if (!linhas)
      fprintf (temporario, "%s", conteudoLinha);
    else
      fprintf (temporario, "\r\n%s", conteudoLinha);

    linhas++;
    printf("linha: %d\n", linhas);
  }

  if (possivelErro && ferror(temporario))
  {
    printf ("Arquivo corrompido\n");
    fclose (entrada);
    fclose (temporario);
    remove (nomeTemporario);
    exit (ARQUIVO_CORROMPIDO);
  }
  
  fclose (entrada);
  fclose (temporario);
  
  snprintf (novoNome, (TAMANHO_NOME_ARQUIVO - 5), "%s%s", argv[1], ".bak");
  rename (argv[1], novoNome);
  rename (nomeTemporario, argv[1]);
  
  return (OK);
}

/* $RCSfile: aula1001.c,v $ */