#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#EEL270 - Computacao II - Turma 2016/2
#Prof. Marcelo Luiz Drumond Lanza
#Autor: Felipe Claudio da Silva Santos
#
#$Author$
#$Date$
#$Log$ 

#$RCSfile$

#CC = O compilador utilizado
#LD = O linkeditor utilizado
#AR = compila a biblioteca
CC = gcc
LD = gcc
AR = ar

#CFLAGS = as flags utilizadas pelo compilador
#LFLAGS = as flags utilazadas pelo linkeditor
#AFLAGS = as flags utilazadas pelo compilador de bibliotecas
CFLAGS = -Wall
LFLAGS = -Wall
AFLAGS = -lncurses

ALL = $(EXECS)
EXECS = $(FCSSUMLEXECS)
OBJS = $(FCSSUMLOBJS)

FCSSUMLEXECS 	= fcssUml
FCSSUMLOBJS 	= fcssUml.o fcssUmlFunctions.o fcssUmlShowCliHelp.o fcssUmlRunNcursesInterface.o

#Regra implicita
.c.o:
	$(CC)	$(CFLAGS)	-c	$<

#Regra geral
#O $@ chama todos os .o necessarios paraera o executavel correspondentes
all:	$(ALL)

fcssUml: $(FCSSUMLOBJS)
	$(LD)	$(LFLAGS)	-o	$@	$(FCSSUMLOBJS)	$(AFLAGS)

clean:
	rm -f $(EXECS) $(OBJS)