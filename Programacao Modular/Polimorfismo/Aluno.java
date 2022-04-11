public class Aluno {
    private double notas;
    private String nome;
    private String matricula;
    private String cpf;
    private String telefone;
    private String endereco; 
    private boolean[] presenca;
    private double frequencia;
    private boolean aprovado;
    private Turma turma;
    private int cont;
    private boolean viuMateriais;
    private boolean hasCertificado;

    Aluno(){
        presenca= new boolean[Presencial.getNumAulas()];
    }

    public double getNotas() {
        if(turma instanceof TurmaNotas)
        return this.notas;
        else return 0.0;
    }

    public void setNotas(double nota) {
        if(turma instanceof TurmaNotas && this.notas<=TurmaNotas.getPontos() && nota>=0 && nota<=((TurmaNotas) turma).getValorProvas())
        this.notas+=nota;    
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMatricula() {
        return this.matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String cpf) {
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
        if (turma instanceof Presencial && pos<Presencial.getNumAulas())
        return this.presenca[pos];
        else
        return false;
    }
    

    public void setPresenca(boolean presenca) {
        if(turma instanceof Presencial && this.cont<Presencial.getNumAulas()){
            this.presenca[this.cont++] = presenca;
            calculaFrequencia();
        }
    }

    public double getFrequencia() {
        this.frequencia= this.calculaFrequencia();
        return this.frequencia;
    }

    private double calculaFrequencia() {
        double freq=0.0;
        for(int i=0; i<Presencial.getNumAulas(); i++){
            if(this.presenca[i])
            freq++;
        }
        return (freq/Presencial.getNumAulas());
    }

    public void setViuMateriais(int resposta){
        if(turma instanceof CursoLivre && resposta==((CursoLivre) turma).getQuantMateriais())
        this.viuMateriais=true;
        else this.viuMateriais=false;
    }

    public boolean getViuMateriais(){
        return this.viuMateriais;
    }
    public boolean isAprovadoPresencial() {

        if(turma instanceof Presencial){
            if(this.getNotas()>=TurmaNotas.getMinPontos() && this.getFrequencia()>=Presencial.getMinFreq())
            this.aprovado=true;
            else this.aprovado=false;
        }

        return this.aprovado;
    }

    public boolean isAprovadoEad() {

        if( turma instanceof Ead){
            if(this.getNotas()>=TurmaNotas.getMinPontos())
            this.aprovado=true;
            else this.aprovado=false;
        }
        return this.aprovado;
    }

    public boolean isAprovadoCursoLivre() {
        if(turma instanceof CursoLivre){
            this.aprovado=getViuMateriais();
        }
        return this.aprovado;
    }

    public boolean isAprovado(){
        if(this.isAprovadoPresencial() || this.isAprovadoEad() || this.isAprovadoCursoLivre()){
            return true;
        }
        else return false;
    }

    public Turma getTurma() {
        return this.turma;
    }

    public void setTurma(Turma turma) {
        this.turma = turma;
    }

    public void setCertificado(){
        if(turma instanceof Presencial && isAprovadoPresencial()){
            this.hasCertificado=true;
        }
        else if(turma instanceof Ead && isAprovadoEad()){
            this.hasCertificado=true;
        }
        else{
            this.hasCertificado=false;
        }
    }

    public boolean getCertificado(){
        return this.hasCertificado;
    }

}
