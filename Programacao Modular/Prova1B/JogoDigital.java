public class JogoDigital extends Jogo {
    
    JogoDigital(){
        super();
    }


    JogoDigital (String nome, int anoLancamento, double precoBase) {
        super(nome, anoLancamento,precoBase);
    }

    @Override
    public double precoVenda(){
        return super.precoVenda();
    }

    @Override
    protected double precoBase(){
       return super.precoBase();        
    }
}
