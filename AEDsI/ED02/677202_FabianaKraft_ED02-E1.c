/**
  Program v0.1- ED02_E1
  @author: Fabiana Kraft
  @version: v0.1
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Tarefa extra E1 Lista ED02

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- ler três valores literais (caracteres) do teclado (a,b,c) e
-dizer se o primeiro está entre os outros dois, ou se é igual a um dos limites.
  ------------------------------------------------------------------------------------------------------------------------------
*/

// lista de dependencias
#include <stdio.h>     // para entradas e saida
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo

//função principal

int main()
 {
     //ID
     printf("%s\n", "Tarefa extra E1 - ED02: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     char a = '_';
     char b = '_';
     char c = '_';
      //Input valor
     printf("Insira o primeiro caractere: ");
     scanf(" %c", &a);
      printf("Insira o segundo caractere: ");
     scanf(" %c", &b);
      printf("Insira o terceiro caractere: ");
     scanf(" %c", &c);
    
     //verificar valor
     
      if ((b>c && a<b && a>c) || (c>b && a<c && a>b) )
      {
       printf("\n%c%s%c%s%c", a," esta contido no intervalo entre ",b, " e ", c);
      } //fim if
      else if (a==b && a!=c)
      {
        printf("\n%s", "O primeiro caractere e o segundo sao iguais");
      } // fim else if
      else if (a==c && a!=b)
      {
        printf("\n%s", "O primeiro caractere e o terceiro sao iguais");
      } // fim else if
       else if (a==c && a==b)
      {
        printf("\n%s", "Todos os caracteres sao iguais");
      } // fim else if
      else
      {
          printf("\n%s\n%s"," Os caracteres inseridos nao satisfazem as condicoes do objetivo do exercicio", "Favor reinserir os dados");
      }
     
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------
Obs1: scanf("%c",, &b) lendo enter como caractere. --> solução scanf(" %c",, &b) por espaço antes do %c
---------------------------------------------- notas / observacoes / comentarios
N/A
---------------------------------------------- previsao de testes
a.) 'f', 'a' e 'z' (OK)
b.) 'f', 'f' e 'z'(OK)
c.) 'z', 'a' e 'c' (OK)
d.) 'b', 'a' e 'a'  (OK)
e.) 'h', 'm' e 'h' (OK)
f.)'p', 'p', 'p' (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19
v0.1 - 25/08/19 (ver Obs1)
---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED02_E1

*/

