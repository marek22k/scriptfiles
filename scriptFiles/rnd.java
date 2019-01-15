package rnd;

import java.util.Random;
import javax.swing.JOptionPane;

public class rnd {
	public static void main(String[] args){
		Random rand = new Random();  // Created a new Random element
		int num = rand.nextInt(9);  // Created a random number from 0 to 9
		JOptionPane.showMessageDialog(null, num, "Output", JOptionPane.INFORMATION_MESSAGE);  // Output the random number
	}
}
