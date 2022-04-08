public class JogoFisico extends Jogo {
    private final double ADIC_DISCO = 15.0;
    private final double ACRESC_ESPECIAL = 0.10;

    private int quantDiscos;
    private boolean isEspecial;

    JogoFisico() {
        super();
    }

    JogoFisico(String nome, int anoLancamento, double precoBase, int quantDiscos, boolean isEspecial) {
        this();
        this.setNome(nome);
        this.setAnoLancamento(anoLancamento);
        this.setPrecoBase(precoBase);
        this.precoBase();
        this.setQuantDiscos(quantDiscos);
        this.setIsEspecial(isEspecial);

    }

    @Override
    public double precoVenda() {
        double precoBaseAntes = this.getPrecoBase();
        this.setPrecoBase(precoBase());
        double valor = super.precoVenda();
        this.setPrecoBase(precoBaseAntes);
        return valor;
    }

    @Override
    protected double precoBase() {
        double valor = this.getPrecoBase() + precoAdicionais();
        if (getIsEspecial()) {
            valor = valor * (1 + ACRESC_ESPECIAL);
        }
        if (this.getQuantDiscos() == 0)
            valor = 0.0;
        return valor;
    }

    private double precoAdicionais() {
        double valorDiscos = this.getADIC_DISCO() * this.getQuantDiscos();
        return (valorDiscos);
    }

    public double getADIC_DISCO() {
        return this.ADIC_DISCO;
    }

    public double getACRESC_ESPECIAL() {
        return this.ACRESC_ESPECIAL;
    }

    public int getQuantDiscos() {
        return this.quantDiscos;
    }

    public void setQuantDiscos(int quantDiscos) {
        if (quantDiscos >= 1)
            this.quantDiscos = quantDiscos;
    }

    public void setIsEspecial(boolean isEspecial) {
        this.isEspecial = isEspecial;
    }

    public boolean getIsEspecial() {
        return this.isEspecial;
    }

}