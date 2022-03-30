public class Microondas{
    private int[] temporizador; //[0]=minutos; [1]=segundos
    private int[] temporizadorOriginal;//valor inicial
    private boolean isAberto; //status da porta
    private int statusTimer; //0=ligado; 1=pausado; 2=reiniciar; 3=desligado
    private int tempo; //tempo atual em segundos

    Microondas(){
        temporizador = new int [2];
        temporizadorOriginal = new int [2];
        isAberto=false;
        statusTimer=3;
        tempo=0;
    }

    Microondas(int[] temporizador, int statusTimer, boolean isAberto){
        this();
        this.statusTimer=statusTimer;
        if(temporizador.length==2 && temporizador[0]<=95 && temporizador[1]<60 && isAberto==false && isLigado()){
            this.temporizadorOriginal=temporizador.clone();
            this.temporizador=temporizador;
            this.statusTimer=statusTimer;
            TemporizadorToTempo();
        }
    }

    int getMinutos(){
        return temporizador[0];
    }

    int getSegundos(){
        return temporizador[1];
    }



    void abrirPorta(){
        if(isDesligado())
            isAberto=true;

    }

    void fecharPorta(){
        isAberto=false;
    }

    boolean getIsAberto(){
        return isAberto;
    }


    void ligar(){
        if(!isAberto)
            statusTimer=0;
        else
            statusTimer=3;
    }

    boolean isLigado(){
        if (statusTimer==0)
            return true;
        else
            return false;
    }

    void pausar(){
        statusTimer=1;
    }


    boolean isPausado(){
        if (statusTimer==1)
            return true;
        else
            return false;
    }

    void reiniciar(){
        statusTimer=2;
        temporizador[0]=temporizadorOriginal[0];
        temporizador[1]=temporizadorOriginal[1];
        TemporizadorToTempo();
    }


    void desligar(){
        statusTimer=3;
        temporizador[0]=0;
        temporizador[1]=1;
    }

    boolean isDesligado(){
        if (statusTimer==3)
            return true;
        else
            return false;
    }

    void TemporizadorToTempo(){
        tempo=temporizador[0]*60+temporizador[1];
    }



    int getTempo(){
        return tempo;
    }

    void passarTempo(){
        if(!isDesligado() && !isPausado() && tempo>0){
            tempo--;
            temporizador[0]=tempo/60;
            temporizador[1]=tempo%60;
            System.out.println(temporizadorToString());
        }
    }
    String temporizadorToString(){
        return String.format("%d:%d",temporizador[0],temporizador[1]);
    }


}
