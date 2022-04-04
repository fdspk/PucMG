/**
  Program v0.0 - ED01_06
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercício 06 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler um valor real do teclado;
  - supor que esse valor represente o lado de um triângulo equilátero (l) ,calcular e mostrar a altura (h), área (A) e o perímetro (P) do mesmo.
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
     printf("%s\n", "Exercício 06 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double l = 0.0;
     double h = 0.0;
     double A = 0.0;
     double P = 0.0;
      //Input valor
     printf("Insira o valor do lado do triangulo equilátero:");
     scanf("%lf", &l);
     //verificar valor
      if (l<0)
      {
       printf("\n%s\n", "Valor negativo do lado. Sera considerado o modulo.");
       l=l*(-1);
      }//fim if
      //Operações
     h=l*sqrt(3)/2;
     A=h*l/2;
     P=3*l;
      //Output
     printf("\n%s%lf\n%s%lf\n%s%lf\n%s%lf","Lado do triangulo=",l,"Altura do triangulo=",h,"Area do triangulo=",A,"Perimetro do triangulo=",P);
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
a.) 4 (OK)
b.) -4.123 (OK)
c.) 7077.05 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_06

*/

