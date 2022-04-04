/**
  Program v0.0 - ED01_05
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercício 05 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler dois valores reais do teclado;
  - supor que esses dois valores representem base (l) e altura (h) de um triângulo, calcular e mostrar a área do mesmo (A).
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
     printf("%s\n", "Exercício 05 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double l = 0.0;
     double h = 0.0;
     double A = 0.0;
      //Input valor
     printf("Insira o valor da base do triangulo:");
     scanf("%lf", &l);
     printf("\n%s","Insira o valor da altura do triangulo:");
     scanf("%lf", &h);
     //verificar valor
      if (l<0)
      {
       printf("\n%s\n", "Valor negativo da base. Sera considerado o modulo.");
       l=l*(-1);
      }//fim if
       if (h<0)
      {
       printf("%s\n", "Valor negativo da altura. Sera considerado o modulo.");
       h=h*(-1);
      }//fim if
      //Operações
     A=l*h/2;
      //Output
     printf("\n%s\t%lf\te\t%lf\n%s%lf","Base e altura do triangulo=",l,h, "Area do triangulo=",A);
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
a.) 10.87 e 11.33 (OK)
b.) 7.42 e -8.79 (OK)
c.) -60,01 e -30,99 (OK)
d.) -7 e 5 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_05

*/

