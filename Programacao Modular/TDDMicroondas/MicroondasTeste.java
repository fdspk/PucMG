import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

class MicroondasTeste{
     Microondas microondas;

    @BeforeEach
    void init(){
        microondas= new Microondas(new int[] {2,1}, 0 ,false );
    }

    @Test
    void testePortaAberta(){
        microondas.desligar();
        microondas.abrirPorta();
        assertTrue(microondas.getIsAberto());
    }
    @Test
    void testePortaFechada(){
        microondas.fecharPorta();
        assertFalse(microondas.getIsAberto());
    }

    @Test
    void testeLigado(){
        microondas.ligar();
        assertTrue(microondas.isLigado());
    }

    @Test
    void testePausado(){
        microondas.pausar();
        assertTrue(microondas.isPausado());
    }

    @Test
    void testeReiniciar(){
        microondas.reiniciar();
        assertEquals("2:1", microondas.temporizadorToString());
    }
    @Test
    void testeDesligado(){
        microondas.desligar();
        assertTrue(microondas.isDesligado());
    }

    @Test
    void converterTempo(){
        microondas.TemporizadorToTempo();
        assertEquals(121, microondas.getTempo());
    }

    @Test
    void passarOTempoUm(){
        microondas.passarTempo();
        assertEquals(2, microondas.getMinutos(), "Teste minutos - erro");
        assertEquals(0, microondas.getSegundos(), "Teste segundos - erro");
    }

    @Test
    void passarOTempoDois(){
        microondas.passarTempo();
        microondas.passarTempo();
        assertEquals(1, microondas.getMinutos(), "Teste minutos - erro");
        assertEquals(59, microondas.getSegundos(), "Teste segundos - erro");
    }
}