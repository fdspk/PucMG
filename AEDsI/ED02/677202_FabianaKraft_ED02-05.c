/**
  Program v0.0 - ED02_05
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 05 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- ler um valor inteiro do teclado (x) e
- dizer se pertence aos intervalos fechados [25:45] ou [33:99], ou a apenas a um deles.
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
     printf("%s\n", "Exercicio 05 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int x = 0;
     int i = 0;
      //Input valor
     printf("Insira um numero inteiro: ");
     scanf("%i", &x);
     //verificar valor
      if (x>=25 && x<=45)
      {
       i=1;
      }//fim if
      else if (x>=33 && x<=99)
      {
          i=2;
      } //fim else if
      if (x>=25 && x<=45 && x>=33 && x<=99)
      {
          i=3;
      } //fim if
     
      //Output
        switch (i)
      {
      case 0:
      printf("\n%i%s", x," nao pertence aos intervalos pre-estabelecidos");
      break;
      case 1:
      printf("\n%i%s", x," pertence apenas ao intervalo [25:45]");
      break;
      case 2:
      printf("\n%i%s", x," pertence apenas ao intervalo [33:99]");
      break;
      case 3:
      printf("\n%i%s", x," pertence a ambos intervalos [25:45] e [33:99]");
      break;
      }// fim switch
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
N/A 
---------------------------------------------- previsao de testes
a.) 24 (OK)
b.) 25 (OK)
c.) 30 (OK)
d.) 33 (OK)
e.) 45 (OK)
f.) 50 (OK)
g.) 99 (OK)
h.) 100 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_05

*/

