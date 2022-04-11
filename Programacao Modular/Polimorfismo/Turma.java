import java.util.Arrays;

public abstract class Turma {
    private final static int MIN_NIVEL = 1;
    private final static int MAX_NIVEL = 5;
    private final static int MIN_DIA = 2;
    private final static int MAX_DIA = 5;
    private final static int MIN_TURNO = 1;
    private final static int MAX_TURNO = 3;

    protected String codigo;
    private int nivel;
    private int diaSemana;
    private int turno;
    protected Aluno[] alunos;
    private int cont;

    Turma(){
        alunos=new Aluno[100];
    }

    public String getCodigo() {
        return this.codigo;
    }

    public abstract void geraCodigo();

    public int getNivel() {
        return this.nivel;
    }

    public void setNivel(int nivel) {
        if (nivel <= MAX_NIVEL && nivel >= MIN_NIVEL)
            this.nivel = nivel;
    }

    public int getDiaSemana() {
        return this.diaSemana;
    }

    public void setDiaSemana(int diaSemana) {
        if (diaSemana <= MAX_DIA && diaSemana >= MIN_DIA)
            this.diaSemana = diaSemana;
    }

    public int getTurno() {
        return this.turno;
    }

    public void setTurno(int turno) {
        if (turno >= MIN_TURNO && turno <= MAX_TURNO)
            this.turno = turno;
    }

    public void setAluno(Aluno aluno) {
        this.alunos[this.cont++] = aluno;
    }

    public int getCont() {
        return this.cont;
    }

    public String getNomeAluno(int pos) {
        if (pos < cont)
            return this.alunos[pos].getNome();
        else
            return ("Posicao invalida");
    }

    public Aluno[] getOrdemAlfabetica() {
        Aluno[] ordenado = new Aluno[cont];
        for (int i = 0; i < cont; i++)
            ordenado[i] = alunos[i];
        Arrays.sort(ordenado);
        return ordenado;
    }

    public abstract void geraRelatorio();

}
