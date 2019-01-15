package PI;

import java.lang.Math;
import javax.swing.JOptionPane;

public class PI {
	public static void main(String[] args){
		double dou = Math.PI;
		String str = "" + dou;
		System.out.println(str);
		JOptionPane.showMessageDialog(null, str, str, JOptionPane.INFORMATION_MESSAGE);
	}
}
