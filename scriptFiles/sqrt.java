package sqrt;

import javax.swing.JOptionPane;

public class sqrt {
	public static void main(String[] args){
		double dou = Integer.parseInt(JOptionPane.showInputDialog(null, "Sqrt:", "Input", JOptionPane.QUESTION_MESSAGE));  // Get input
		double res = Math.sqrt(dou);  // Get result
		JOptionPane.showMessageDialog(null, "The result from sqrt(" + dou + ") is " + res, "Output", JOptionPane.INFORMATION_MESSAGE);  // Output result
		System.exit(0);  // Exit application
	}
}
