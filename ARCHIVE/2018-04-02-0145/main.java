import java.util.*;
class main{
	public static void main (String[] args){
		while (true){
		Scanner dado = new Scanner(System.in);
		double sqrt_5 = Math.sqrt(5.0);
		double numero_1 = (1 + sqrt_5) / 2;
		double numero_2 = (1 - sqrt_5) / 2;
		double resposta;
		double entrada = dado.nextInt();
		numero_1 = Math.pow(numero_1, entrada);
		numero_2 = Math.pow(numero_2, entrada);
		resposta = (numero_1 - numero_2) / sqrt_5;
		System.out.printf("%.1f\n", resposta);
		}
	}
}
