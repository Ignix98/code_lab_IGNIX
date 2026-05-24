/*
 * aer_427_YoSoyTu.c
 *
 * Descripción: Solución al problema "Y Soy Tu" del AER (Acepta el Reto).
 * Autor: Ignacio Pérez Serra
 * Fecha: 19/05/2026
 * Versión: 1.0
 */

import java.util.Scanner;

public class aer_427_YoSoyTu_JAVA_2017 {

	public static void main(String[] args) {
		Scanner tec = new Scanner(System.in);
		int casos;
		String luke = "Luke", padr = "padre";
		casos = tec.nextInt();
		for(int i = 0; i < casos; i++){
			String A = tec.next();
			String B = tec.next();
			if (A.equals(luke)&&B.equals(padr)){
				System.out.println("TOP SECRET");
			}else{
				System.out.println(A+", yo soy tu " + B);
			}
		}

	}

}