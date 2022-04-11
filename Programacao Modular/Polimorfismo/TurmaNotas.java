public abstract class TurmaNotas extends Turma {
    private static final double PONTOS = 100.0;
    private static final double MIN_PONTOS=60.0;

    private int quantProvas;
    private double valorProvas;

    public static double getPontos(){
        return PONTOS;
    }

    public static double getMinPontos(){
        return MIN_PONTOS;
    }

    public int getQuantProvas() {
        return this.quantProvas;
    }

    public void setQuantProvas(int quantProvas) {
        this.quantProvas = quantProvas;
    }

    public double getValorProvas() {
        if (this.getQuantProvas() > 0)
            this.valorProvas = PONTOS / this.getQuantProvas();
        return this.valorProvas;
    }

    public double getMediaNotasTurma() {
        double soma = 0.0;
        for (int i = 0; i < this.getCont(); i++)
            soma += this.alunos[i].getNotas();
        return (soma / this.getCont());
    }

    public int getMelhorAlunoPos(){
        double melhor=0.0;
        int melhorpos=0;
        for (int i = 0; i < this.getCont(); i++){
            if(this.alunos[i].getNotas()>melhor){
                melhor=this.alunos[i].getNotas();
                melhorpos=i;
            }
        }
        return melhorpos;
    }

    public String getMelhorAlunoNome(){
        int pos=this.getMelhorAlunoPos();
        return(this.alunos[pos].getNome());
    }

    public double getMelhorAlunoNota(){
        int pos=this.getMelhorAlunoPos();
        return(this.alunos[pos].getNotas());
    }

    @Override
    public void geraRelatorio(){
        Aluno [] relatorio= this.getOrdemAlfabetica();
        for(int i=0; i<this.getCont(); i++){
            System.out.println(relatorio[i].getNome());
            System.out.println(relatorio[i].getNotas());
            System.out.println(relatorio[i].isAprovado());
        }
    }

}
