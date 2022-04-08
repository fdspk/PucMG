public class Cliente {
    public String nome;
    private Jogo[] historico;
    private double proxDesconto;
    private int cont;
    private int ultimoDescontoPos;

    Cliente() {
        this.historico = new Jogo[100];
    }

    Cliente(String nome, Jogo jogo) {
        this.nome = nome;
        this.incluirJogo(jogo);

    }

    public void incluirJogo(Jogo novo){
        if(this.verificarDesconto()){
            ultimoDescontoPos++;
            this.setProxDesconto(0.2*novo.precoVenda());
        }
        else{
            this.setProxDesconto(0.0);
        }
        this.historico[cont]=novo;
        cont++;
        
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    private boolean verificarDesconto() {
        double soma = 0.0;
        for (int i = ultimoDescontoPos; i < this.cont; i++) {
            soma += historico[i].precoVenda();
            if (soma >= 500.0){
                this.ultimoDescontoPos=i;
                return true;
            }
        }
        return false;

    }


    public double getProxDesconto() {
        return this.proxDesconto;
    }

    public void setProxDesconto(double proxDesconto) {
        this.proxDesconto = proxDesconto;
    }
    

    public int getUltimoDescontoPos() {
        return this.ultimoDescontoPos;
    }

   


}
