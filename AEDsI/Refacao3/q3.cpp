#include <iostream>
#include <string>
/*
677262
FABIANA KRAFT
Q3 PROVA 3
AEDS1
T2 MANHA
*/

using namespace std;
int main ()
{
   cout<<"String: ";
      string s=" ";
   cin>>s;
   string p="";
   int x= s.length();
   int k=0;
   int i=0;
   bool indicador=0;
   bool texto=1;


   for(i=0; i<x; i++)
   {
      if(!((s[i]<='9' && s[i]>='0')|| s[i]=='+'))
      {
         texto=0;
         //cout<<s[i]<<" nao e numero"<<endl;
      }
   }

   if (texto)
   {
   //cout<<"e numero"<<endl;
      for(i=0; i<x; i++)
      {
         if(s[i]<='9' && s[i]>'0' && !indicador)
         {
            //p=p+s[i];
            p[k]=s[i];
            k=k+1;
            p[k]='\0';
            indicador=1;
           // cout<<"teste1.1 "<<i<<" "<<s[i]<<endl;
         }
         else{
         //cout<<"teste2 "<<i<<" "<<s[i]<<endl;
          if (indicador && s[i]<='9' && s[i]>='0')
         {
            p[k]=s[i];
            k=k+1;
            //cout<<"teste3 "<<endl;
         }
         }
      }
      cout<<"RESULTADO: "<<endl;
      cout<<s<<"->"<<p.c_str( )<<endl;
   }
   return(0);
   
}