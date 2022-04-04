/**
  Program v0.0 - ED02_07
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 07 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - ler dois valores inteiros do teclado (a,b) e
 - dizer se o primeiro é ímpar e positivo, e se o segundo é par e negativo.
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
     printf("%s\n", "Exercicio 07 - ED02: v0.0" );
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
      if (a%2==1 || a%2==-1 && a>0)
      {
       printf("\n%i%s", a," e um numero impar e positivo");
      } //fim if
      else
      {
          printf("\n%i%s", a," nao se encaixa na definicao <impar e positivo>");
      } // fim else
      if (b%2==0 & b<=0)
      {
       printf("\n%i%s", b," e um numero par e negativo ");
      }//fim if
      else
      {
          printf("\n%i%s", b," nao se encaixa na definicao <par e negativo>");
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
Nota 1 : um número x é considerado positivo se  x = 0  e estritamente positivo se  x > 0.
Analogamente, um número x é negativo se  x = 0  e estritamente negativo se  x < 0.
---------------------------------------------- previsao de testes
a.) 3 e -2 (OK)
b.) -2 e 3 (OK)
c.) -3 e 2 (OK)
d.) 0 e 0 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_07

*/

