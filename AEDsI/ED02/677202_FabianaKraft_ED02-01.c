/**
  Program v0.0 - ED02_01
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 01 Lista ED02

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- ler um valor inteiro do teclado (x)e
- dizer se é par ou ímpar.
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
     printf("%s\n", "Exercicio 01 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int x = 0;
      //Input valor
     printf("Insira um numero inteiro: ");
     scanf("%i", &x);
     //verificar valor e output
      if (x%2==0)
      {
       printf("\n%i%s\n", x," e numero par");
      }//fim if
      else if(x%2==1 || x%2==-1)
      {
         printf("\n%i%s\n",x, " e numero impar");
      } //fim else
      
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
Comentario: resto da divisão n%m; %d ou %i, igual   
---------------------------------------------- previsao de testes
a.) 10 (OK)
b.) 5 (OK)
c.) -7 (OK)
d.) -4 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_01

*/

