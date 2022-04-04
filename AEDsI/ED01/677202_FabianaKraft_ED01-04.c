/**
  Program v0.0 - ED01_04
  @author: Fabiana Kraft
  @version: v0.0
  @date: 21/08/2019
*/
//Identificação do programa
/*
  Exercício 04 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler dois valores inteiros do teclado;
  - supor que esses dois valores representem lados de um retângulo (a, b),calcular e mostrar a área (A) e o perímetro do mesmo (P).
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
     printf("%s\n", "Exercício 04 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int a = 0;
     int b = 0;
     int A = 0;
     int P = 0;
      //Input valor
     printf("Insira o valor inteiro da largura do retangulo:");
     scanf("%d", &a);
     printf("\n%s","Insira o valor inteiro do comprimento do retangulo:");
     scanf("%d", &b);
     //verificar valor
      if (a<0)
      {
       printf("\n%s\n", "Valor negativo da largura. Sera considerado o modulo.");
       a=a*(-1);
      }//fim if
       if (b<0)
      {
       printf("%s\n", "Valor negativo do comprimento. Sera considerado o modulo.");
       b=b*(-1);
      }//fim if
      //Operações
     A=a*b;
     P=2*(a+b);
      //Output
     printf("%s\t%d\te\t%d\n%s%d\n%s%d","Lados do retangulo=",a,b, "Area do retangulo=",A, "Perimetro do retangulo=", P);
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
a.) 3 e 4 (OK)
b.) 10 e -8 (OK)
c.) 300 e 555(OK)
d.) -7 e 5 (OK)
e.)-6 e -4 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 21/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_04

*/

