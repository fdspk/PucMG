/**
  Program v0.1 - ED02_06
  @author: Fabiana Kraft
  @version: v0.1
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 06 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - ler dois valores inteiros do teclado (a, b) e
 - dizer se o primeiro é ímpar e o segundo é par.
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
     printf("%s\n", "Exercicio 06 - ED02: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int a = 0;
     int b = 0;
      //Input valor
     printf("Insira o primeiro numero inteiro: ");
     scanf("%i", &a);
     printf("\n%s", "Insira o segundo numero inteiro: ");
     scanf("%i", &b);
     //verificar valor e output
      if (a%2==1 || a%2==-1)
      {
       printf("\n%i%s", a," e um numero impar");
      } //fim if
      else
      {
          printf("\n%i%s", a," nao e um numero impar");
      } // fim else
      if (b%2==0)
      {
       printf("\n%i%s", b," e um numero par");
      }//fim if
      else
      {
          printf("\n%i%s", b," nao e um numero par");
      }
     
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
Obs1: esqueci virgula depois do "\n%i%s" no printf
---------------------------------------------- previsao de testes
a.) 2 e 3
b.) 3 e 2
c.) 10 e 10
d.) 11 e 13
e.)-11 e -11
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19
v.0.1 - 25/08/19 (ver Obs1)

---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED02_06

*/

