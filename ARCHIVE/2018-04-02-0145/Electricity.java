import java.util.*;

public class Electricity{
	public static void main(String[] args){

		Scanner scanner = new Scanner(System.in);
		Date now, bef;
		int n = scanner.nextInt();
		while (n > 0){

			int qnt = 0;
			int val = 0, bef_cons = 0, now_cons;
			long bef_mili, now_mili;
			bef = new Date(1888, 10, 29);
			for (int i = 0; i < n; i++){

				int day = scanner.nextInt();
				int month = scanner.nextInt();
				int year = scanner.nextInt();
				now_cons = scanner.nextInt();

				now = new Date(year, month, day);
				bef_mili = bef.getTime();
				now_mili = now.getTime();
				if ((now_mili - bef_mili) > 86000000 && (now_mili - bef_mili) < 87000000){

					qnt++;
					val += now_cons - bef_cons;

				}

				bef_cons = now_cons;

				System.out.println(qnt + " " + val + " " + now_mili +" " +bef_mili + " " + ((now_mili - bef_mili)/(1000*3600)));
				bef = now;

			}

			System.out.println(qnt + " " + val);

			n = scanner.nextInt();
		}

	}

}
