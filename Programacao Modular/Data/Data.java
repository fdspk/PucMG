class Data{
   private int ano;
   private int mes;
   private int dia;
   
   //construtores
   
   Data(){
      this(1,1,2022);
   }
   
   Data(int dia, int mes, int ano){
   
      this.dia=dia;
      this.mes=mes;
      this.ano=ano;
      if(!isData()){
         this.dia=1;
         this.mes=1;
         this.ano=2022;
      } 
      
   }
   
   //verificar se e data
   boolean isData (){
      return(isAno() && isMes() && isDia());  
   }
   
   boolean isAno(){
      return(ano>=1900);
   }
   
   boolean isMes(){
      return(mes>=1 && mes<=12);
   }
   
   boolean isDia(){
      int meses[]={31,0,31,30,31,30,31,31,30,31,30,31};
      boolean resp=false;
      if(mes!=2 && isMes() && dia>=1 && dia<=meses[mes-1])
         resp=true;
      
      else if (mes==2 && isBissexto() && dia>=1 && dia<=29)
         resp=true;
      
      else if(mes==2 && dia>=1 && dia<=28)
         resp=true;
      return resp;
   }
   
   boolean isBissexto(){
      return(ano % 400 == 0 || ((ano % 4 == 0) && (ano % 100 != 0)));
   }
   
   //imprimir
   void imprimeData(){
      System.out.println(dia+"/"+mes+"/"+ano);
   }
   
   //comparar duas datas e determinar a maior
   void verificaDuasDatas(Data data2){
      boolean emaior=false;
      boolean eigual=false;
      if(ano>data2.ano)
         emaior=true;
      else if(ano<data2.ano)
         emaior=false;
      else if(mes>data2.mes)
         emaior=true;
      else if (mes<data2.mes)
         emaior=false;
      else if(dia>data2.dia)
         emaior=true;
      else if(dia<data2.dia)
         emaior=false;
      else
         eigual=true;
         
      if(eigual)
         System.out.println("As datas sao iguais");
      else if (emaior)
         System.out.println("A primeira data e maior que a segunda");
      else
         System.out.println("A segunda data e maior que a primeira");
   }
   
   //acrescentar dias nas datas
   void adicionarDias(int d){
      if(d<0)
         System.out.println("Dias negativos");
      else{
         int meses[]={31,0,31,30,31,30,31,31,30,31,30,31};
         //definir dias para meses[1] = fevereiro
         if(isBissexto())
            meses[1]=29;
         else
            meses[1]=28;
           
         dia=dia+d;
         
         while(dia>meses[mes-1]){
         //muda o ano
            if(mes==12 && dia>31){
               ano++;
               mes=1;
            }
          //decrementa dias e muda o mes
            dia=dia-meses[mes-1];
            mes++;
            
         }
         imprimeData();
      }
   }
}

