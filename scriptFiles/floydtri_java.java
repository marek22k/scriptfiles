package floytri_java;

import java.util.Scanner;

public class floytri_java {

	public static void main(String[] args) {
		System.out.print("Please enter a number: ");
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.close();
		
		System.out.println("\nFloyd's triangle:");
		
		int j;
		
		for(int i = 1, num = 1; i <= n; i++)
		{
			for(j = 0; j < i; j++, num++)
				System.out.print(num + " ");
			
			System.out.println("");
		}
	}

}
