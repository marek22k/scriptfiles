// The author of this program is Marek Küthe
// Website: mk16.de
// E-Mail: m.k@mk16.de

package good_bad;

import java.util.Scanner;

public class good_bad {
	public static void main(String args[])
	{
		System.out.println("Hello User! Enter a number:");
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		s.close();
		
		if(num < 0)
		{
			System.out.println("The number is crazy!");
		}
		else if(num%2 == 0)
		{
			System.out.println("The number is good!");
		}
		else
		{
			System.out.println("The number is bad!");
		}
	}
}
