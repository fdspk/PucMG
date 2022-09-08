public class Veiculo{
//atributos
    private String placa;
    private Data data;
    private double ConsumoPorLitro;
    private double KmTotal;
    private int quantidadeRotas;
    private double[] valores= new double[9]; // 3 para cada rota, maximo de 3 rotas, logo 9 valores
    private static int contador=0;
    private static final double PRECO_COMBUSTIVEL=4.378; //R$/L

    //construtor padrao
    Veiculo(){
        this.placa="XXX.1234";
        this.ConsumoPorLitro=2.0;
        this.data= new Data(1,1,2000);
        this.KmTotal=200;
        this.quantidadeRotas=0;
        
    }

//gets e sets
    public void setData(int dia, int mes, int ano){
        this.data= new Data(dia,mes,ano);
    }

    public String getData(){
        return this.data.dataFormatada();
    }

    public void setPlaca(String placa){
        this.placa=placa;
    }

    public String getPlaca(){
        return this.placa;
    }
    

    public void setQuilometrosPorLitro(double KmL){
        if(KmL>0)
            this.ConsumoPorLitro=KmL;
        else
            this.ConsumoPorLitro=0;
    }

    public double getQuilometrosPorLitro(){
        return this.ConsumoPorLitro;
    }

    public void setKmTotal(double KmTotal){
        if(KmTotal>0)
            this.KmTotal=KmTotal;
        else
            this.KmTotal=0;
    }

    public double getKmTotal(){
        return this.KmTotal;
    }

    public void setQuantidadeRotas(int quantidade){
        if(quantidade>0 && quantidade<=3)
            this.quantidadeRotas=quantidade;
        else
            this.quantidadeRotas=0;
    }

    public int getQuantidadeRotas(){
        return this.quantidadeRotas;
    }

    public void setValores(double valor){
        
        if(contador<3*this.quantidadeRotas && valor>0){
            this.valores[contador]=valor;
            contador++;
        }
    }

    public String getValores(){
        String s = new String();
        for(int i=0; i<9; i++){
            s+=this.valores[i]+" ";
        }
        return s;
    }

    //calcula media de uma rota
    public double media(int rota){
        double soma=0.0;
        double media=0.0;
        int i=0;
        int max=0;
        
        if (rota>=1 && rota<=this.quantidadeRotas){
            i = rota*3-3;
            max=i+3;
            for(int j=i; j<max; j++){
                soma+=this.valores[i];
            }
            media=soma/3.0;
        }  
        return media;
        
    }

    //calcula gasto com abastecimento em reais
    public double gastoAbastecimento(){
        double soma= media(1)+media(2)+media(3);
        return soma*PRECO_COMBUSTIVEL/getQuilometrosPorLitro();
    }




}