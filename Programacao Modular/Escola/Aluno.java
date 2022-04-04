public class Aluno {
    private static final double VALOR_PROVA = 25.0;
    private static final double MIN_PONTOS = 60.0;
    private static final double MIN_FREQUENCIA = 0.75;
    private static final int QUANT_PROVAS = 4;
    private static final int NUM_AULAS = 20;

    private double[] provas;
    private String nome;
    private int matricula;
    private String cpf;
    private String telefone;
    private String endereco;
    private boolean[] presenca;
    private double frequencia;

    Aluno() {
        provas = new double[QUANT_PROVAS];
        presenca = new boolean[NUM_AULAS];
    }

    public double getNota(int pos) {
        if ((pos>0 && pos <= QUANT_PROVAS))
            return this.provas[--pos];// quero prova 1, logo pegar na posicao 0
        else
            return 0.0;
    }

    public void setProvas(double nota, int pos) {
        if ((nota >= 0 && nota <= VALOR_PROVA) && (1 <= pos && pos <= QUANT_PROVAS))
            this.provas[--pos] = nota;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return this.matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String cpf) {
        if (cpf.length() == 14)
            this.cpf = cpf;
    }

    public String getTelefone() {
        return this.telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getEndereco() {
        return this.endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public boolean getPresenca(int pos) {
        if (pos > 0 && pos <= NUM_AULAS)
            return this.presenca[--pos];
            else
        return false;
    }

    public void setPresenca(int pos, boolean isPresente) {
        if (pos > 0 && pos <= NUM_AULAS)
            this.presenca[--pos] = isPresente;
        

    }

    public double getFrequencia() {
        this.CalculaFrequencia();
        return this.frequencia;
    }

    private void CalculaFrequencia() {
        double soma=0.0;
        for (int i=0; i<NUM_AULAS; i++){
            if(this.presenca[i]==true)
            soma+=1;
        }        
        this.frequencia = (soma/NUM_AULAS);
    }

    public boolean isAprovado(){
        if(getFrequencia()>=MIN_FREQUENCIA && getTotal()>=MIN_PONTOS)
        return true;
        else return false;
    }

    public double getTotal(){
        double soma=0.0;
        for(int i=0; i<QUANT_PROVAS; i++)
        soma+=this.provas[i];
        return (soma);
    }


}
