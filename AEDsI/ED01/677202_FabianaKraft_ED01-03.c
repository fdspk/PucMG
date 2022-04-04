/**
  Program v0.1 - ED01_03
  @author: Fabiana Kraft
  @version: v0.1
  @date: 21/08/2019
*/
//Identificação do programa
/*
  Exercício 03 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler dois valores inteiros do teclado;
  - supor que esses dois valores representem lados de um retângulo (a, b),calcular e mostrar a área do mesmo (A).
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
     printf("%s\n", "Exercício 03 - ED01: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int a = 0;
     int b = 0;
     int A = 0;
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
      //Output
     printf("%s\t%d\te\t%d\n%s%d","Lados do retangulo=",a,b, "Area do retangulo=",A);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
obs1:
Linhas 44 e 46 -> programa não rodou ao colocar "%d\n", logo, o \n foi retirado do scanf e colocado no printf
---------------------------------------------- previsao de testes
a.) 2 e 4 (OK)
b.) 7 e 3 (OK)
c.) 11 e 40(OK)
d.) -2 e 4 (OK)
e.)-2 e -4 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 21/08/19

v0.1 - 21/08/19 (ver obs1)


---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED01_03

*/

