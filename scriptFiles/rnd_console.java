package rnd_console;

import java.util.Random;

public class rnd_console {
	public static void main(String[] args){
		Random rnd = new Random();
		int num = rnd.nextInt(9);
		System.out.println(num);
	}
}
