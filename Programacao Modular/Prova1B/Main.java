public class Main {
    public static void main(String[] args) throws Exception {
        Cliente cliente1 = new Cliente();
        Jogo jogo1 = new Jogo("Snake do Nokia v3.0", 2022, 10);
        cliente1.setNome("Fulano");
        cliente1.incluirJogo(jogo1);
        System.out.println(jogo1.precoVenda());
        jogo1.setAnoLancamento(2019);
        System.out.println(jogo1.precoVenda());

    }
}
