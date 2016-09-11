#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#EEL270 - Computacao II - Turma 2016/2
#Prof. Marcelo Luiz Drumond Lanza
#Autor: Felipe Claudio da Silva Santos
#
#$Author: felipe $
#$Date: 2016/09/10 22:54:47 $ 
#$Log: Makefile,v $
#Revision 1.3  2016/09/10 22:54:47  felipe
#Aula01 consertado,
#tudo ok
#
#Revision 1.2  2016/09/10 21:59:35  felipe
#Divisao entre aula01 e aula0101 como pedido no relatorio
#
#Revision 1.1  2016/09/10 21:54:35  felipe
#Initial revision
#


#CC = O compilador utilizado
#LD = O linkeditor utilizado
CC = gcc
LD = gcc

#CFLAGS = as flags utilizadas pelo compilador
#LFLAGS = as flags utilazadas pelo linkeditor
CFLAGS = -Wall
LFLAGS = -Wall

#Nome dos executaveis
EXECS = aula0101\
        aula0102\
        aula0103

EXECSAULA01 = aula0101\
              aula0102\
              aula0103

#nome dos .objs
AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o

#todos os objs da aula01
AULA01OBJS = $(AULA0101OBJS)\
	     $(AULA0102OBJS)

#Regra implicita
.c.o:
	$(CC)	$(CFLAGS)	-c	$<

#Regra geral
#O $@ chama todos os .o necessarios paraera o executavel correspondentes
all:	$(EXECS)

#Regra para gerar todos os executaveis da aula 1
aula01:	$(EXECSAULA01)

#Regras para gerar somente um executavel
aula0101:	$(AULA0101OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0101OBJS)

aula0102:	$(AULA0102OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0102OBJS)

aula0103:	$(AULA0103OBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(AULA0103OBJS)

#Limpa a pasta
clean:
	rm -f *.o $(EXECS)

# $RCSfile: Makefile,v $
