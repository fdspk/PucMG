/**
  Program v0.0 - ED02_10
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 10 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - ler três valores reais do teclado (a,b,c) e
 - dizer se o primeiro não está entre os outros dois e todos são diferentes entre si.
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
     printf("%s\n", "Exercicio 10 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double a = 0.0;
     double b = 0.0;
     double c = 0.0;
      //Input valor
     printf("Insira o primeiro numero real: ");
     scanf("%lf", &a);
     printf("\n%s", "Insira o segundo numero real: ");
     scanf("%lf", &b);
       printf("\n%s", "Insira o terceiro numero real: ");
     scanf("%lf", &c);
     //verificar valor e output
      if ((c>b && a<=c && a>=b)|| (c<b && a<=b && a>=c) || a==b || a==c || b==c)
      {
       printf("\n%s", "Os dados nao satisfazem as condiçoes exigidas pelos objetivos");
       printf("\n%s", "Favor reler os objetivos e reinserir os dados");
      } //fim if
      else 
      {
        printf("\n%lf%s%lf%s%lf%s", a," nao esta entre ", b,  " e ", c, " e todos sao diferentes ente si");
      } // fim else if
      
      
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
a.) 1, 2 e 3 (OK)
b.) 2.567, 1.002 e 3.888 (OK)
c.) 9.888, 9.888 e 3.02 (OK)
d.)-3.1238, -2098 e -50.213897(OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_10

*/

