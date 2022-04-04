import java.util.*;

public class Turma {
    public static final int MAX_ALUNOS = 20;
    public static final int MIN_NIVEL = 1;
    public static final int MAX_NIVEL = 5;
    public static final int MIN_DIA = 2;
    public static final int MAX_DIA = 5;
    public static final int MIN_TURNO = 1;
    public static final int MAX_TURNO = 3;
    public static final double PESO_NOTA = 0.8;
    public static final double PESO_FREQ = 0.2;

    private int codigo;
    private int nivel;
    private int diaSemana;
    private int turno;
    private Aluno[] alunos;
    private int cont;

    public Turma() {
        alunos = new Aluno[MAX_ALUNOS];
        cont = 0;
    }

    public int getCodigo() {
        this.geraCodigo(this.getNivel(), this.getDiaSemana(), this.getTurno());
        return this.codigo;
    }

    private void geraCodigo(int nivel, int diaSemana, int turno) {
        this.codigo = (nivel * 100 + diaSemana * 10 + turno);
    }

    public int getNivel() {
        return this.nivel;
    }

    public void setNivel(int nivel) {
        if (nivel >= MIN_NIVEL && nivel <= MAX_NIVEL)
            this.nivel = nivel;
    }

    public int getDiaSemana() {
        return this.diaSemana;
    }

    public void setDiaSemana(int diaSemana) {
        if (nivel >= MIN_DIA && nivel <= MAX_DIA)
            this.diaSemana = diaSemana;
    }

    public int getTurno() {
        return this.turno;
    }

    public void setTurno(int turno) {
        if (nivel >= MIN_TURNO && nivel <= MAX_TURNO)
            this.turno = turno;
    }

    public void setAluno(Aluno aluno) {
        this.alunos[cont] = aluno;
        cont++;
    }

    public int getCont() {
        return this.cont;
    }

    public String getNomeAluno(int pos) {
        if (pos > 0 && pos <= this.getCont())
            return (this.alunos[--pos].getNome());
        else
            return ("Numero na lista invalido");
    }

    public String[] getOrdemAlfabetica() {
        String[] ordenado = new String[this.getCont()];
        for (int i = 0; i < this.getCont(); i++)
            ordenado[i] = String.valueOf(this.alunos[i].getNome());

        Arrays.sort(ordenado);
        return (ordenado);
    }

    public double getMediaNotas() {
        double soma = 0.0;
        for (int i = 0; i < this.getCont(); i++)
            soma += this.alunos[i].getTotal();
        return (soma / this.getCont());
    }

    public double getMediaFrequencia(){
        double soma = 0.0;
        for (int i = 0; i < this.getCont(); i++)
            soma += this.alunos[i].getFrequencia();
        return (soma / this.getCont());
    }

    public int getMelhorAlunoPos(){
        int posMelhor=0;
        double melhorScore=0.0;
        double score=0.0;
        for(int i=0; i< this.getCont(); i++){
            score=((PESO_NOTA*this.alunos[i].getTotal()/100.0) + PESO_FREQ*this.alunos[i].getFrequencia());
            if(score>melhorScore){
                melhorScore=score;
                posMelhor=i;
            }
        }
        return(posMelhor);
    }

    public String getMelhorAlunoNome(){
        return(this.alunos[this.getMelhorAlunoPos()].getNome());
    }

    public double getMelhorAlunoNota(){
        return(this.alunos[this.getMelhorAlunoPos()].getTotal());
    }

    public double getMelhorAlunoFrequencia(){
        return(this.alunos[this.getMelhorAlunoPos()].getFrequencia());
    }

}