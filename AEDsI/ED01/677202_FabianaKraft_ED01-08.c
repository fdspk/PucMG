/**
  Program v0.0 - ED01_08
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercício 08 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - definir e ler três valores reais do teclado (a,b,c);
 - supor que esses valores informem o comprimento, a largura e a altura de um paralelepípedo, respectivamente;
 - calcular e mostrar o volume do sólido (V).
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
     printf("%s\n", "Exercício 08 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double a = 0.0;
     double b = 0.0;
     double c = 0.0;
     double V = 0.0;
     //Input valor
     printf("Insira o valor comprimento do paralelepipedo: ");
     scanf("%lf", &a);
     printf("Insira o valor da largura lado do paralelepipedo: ");
     scanf("%lf", &b);
     printf("Insira o valor da altura do paralelepipedo: ");
     scanf("%lf", &c);
     //verificar valor
      if (a<0)
      {
       printf("\n%s\n", "Valor negativo do comprimento. Sera considerado o modulo.");
       a=a*(-1);
      }//fim if
       if (b<0)
      {
       printf("\n%s\n", "Valor negativo da largura. Sera considerado o modulo.");
       b=b*(-1);
      }//fim if
       if (c<0)
      {
       printf("\n%s\n", "Valor negativo da altura. Sera considerado o modulo.");
       c=c*(-1);
      }//fim if
      //Operações
     V=a*b*c;
      //Output
     printf("\n%s\t%lf,\t%lf\te\t%lf\n%s%lf","Lados do paralelepipedo=",a,b,c,"Volume do paralelepipedo= ",V);
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
a.) 1,2 e 3 (OK)
b.) 5.678, 6.789 e 7.891 (OK)
c.) 0.1234567, .2345678 e .34567891 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_08

*/

