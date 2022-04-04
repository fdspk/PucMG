/**
  Program v0.0 - ED02_08
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 08 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - ler dois valores reais do teclado (a,b) e
 -dizer se o primeiro é maior, menor ou igual ao segundo.
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
     printf("%s\n", "Exercicio 08 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double a = 0.0;
     double b = 0.0;
      //Input valor
     printf("Insira o primeiro numero real: ");
     scanf("%lf", &a);
     printf("\n%s", "Insira o segundo numero real: ");
     scanf("%lf", &b);
     //verificar valor e output
      if (a>b)
      {
       printf("\n%lf%s%lf", a," e maior que ",b);
      } //fim if
      else if (a<b)
      {
        printf("\n%lf%s%lf", a," e menor que ",b);
      } // fim else if
      else if (a==b)
      {
       printf("\n%lf%s%lf", a," e igual a ",b);
      }//fim else if
      
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
a.) 10.1234 e 20.5678 (OK)
b.) 600.54321 e 400.09876 (OK)
c.) 8.3 e 8.3 (OK)
d.)-300 e -1000(OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_08

*/

