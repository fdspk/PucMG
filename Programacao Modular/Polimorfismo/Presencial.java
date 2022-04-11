public class Presencial extends TurmaNotas {
   
    private final static int MAX_ALUNOS=20;
    private final static double MIN_FREQUENCIA=0.75;
    private final static int NUM_AULAS=20;

    Presencial(){
        super();
    }

    @Override
    public void geraCodigo(){
        this.codigo=Integer.toString(this.getNivel()*100+this.getDiaSemana()*10+this.getNivel());
    }

    public static int getNumAulas(){
        return NUM_AULAS;
    }
    public static double getMinFreq(){
        return MIN_FREQUENCIA;
    }

    public double getMediaFrequencia(){
        double soma=0.0;
        for(int i=0; i<this.getCont(); i++){
            soma+=this.alunos[i].getFrequencia();
        }
        return(soma/this.getCont());
    }

    @Override
    public int getMelhorAlunoPos(){
        double valorNota=0.0;
        double valorFreq=0.0;
        double score=0.0;
        double maxScore=0.0;
        int melhorPos=0;
        for(int i=0; i<this.getCont(); i++){
            valorNota=this.alunos[i].getNotas()/100.0;
            valorFreq=this.alunos[i].getFrequencia();
            score=0.8*valorNota*0.2*valorFreq;
            if(score>maxScore){
                melhorPos=i;
                maxScore=score;
            }

        }
        return melhorPos;
    }

    public double getMelhorAlunoFrequencia(){
        return(this.alunos[this.getMelhorAlunoPos()].getFrequencia());
    }

    @Override
    public void setAluno(Aluno aluno) {
        if(this.getCont()<=MAX_ALUNOS)
        super.setAluno(aluno);
    }

  

}
