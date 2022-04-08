
public class Jogo {
    private final int TEMPO_DESC = 2;
    private final double PCT_DESCONTO = 0.2;
    private final double MARGEM_LUCRO = 0.35;
    protected String nome;
    protected int anoLancamento;
    protected double precoBase;
    protected int[] avaliacoes;
    private int cont;

    Jogo() {
        this.avaliacoes = new int[100];
        this.cont = 0;
    }

    Jogo(String nome, int anoLancamento, double precoBase) {
        this();
        this.nome = nome;
        this.setAnoLancamento(anoLancamento);
        this.setPrecoBase(precoBase);
    }

    public double precoVenda() {
        if (this.descontoTempo()<1)
            return (this.getPrecoBase()*(1+MARGEM_LUCRO) - this.descontoTempo()); 
        else
            return (0.0);
    }

    protected double precoBase() {
        return this.getPrecoBase();
    }

    private double descontoTempo() {
        double desconto = PCT_DESCONTO * ((2022 - this.getAnoLancamento())/ TEMPO_DESC);
        return desconto;
    }

    public double avaliacaoMedia() {
        double avaliacaoMedia = 0.0;
        for (int i = 0; i < this.cont; i++) {
            avaliacaoMedia +=this.avaliacoes[i];
        }
        return (avaliacaoMedia / cont);
    }

    public void notaAvaliacao(int nota) {
        if (nota <= 5 && nota >= 1) {
            this.avaliacoes[cont] = nota;
            this.cont++;
        }

    }


    public int getAnoLancamento() {
        return this.anoLancamento;
    }

    public void setAnoLancamento(int anoLancamento) {
        if(anoLancamento>=1900 && anoLancamento<=2022)
        this.anoLancamento = anoLancamento;
        else
        this.anoLancamento=2022; //nao havera desconto caso nao seja informado um ano adequado
    }

    public double getPrecoBase() {
        return this.precoBase;
    }

    public void setPrecoBase(double precoBase) {
        if(precoBase>=0)
        this.precoBase = precoBase;
        else
        this.precoBase=-precoBase; //inverter valores negativos passados por parametro
    }


    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    
}
