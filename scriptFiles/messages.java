package test;

import javax.swing.JOptionPane;

public class messages {
	static void showMessage(String msg){
		JOptionPane.showMessageDialog(null, msg, "Output", JOptionPane.INFORMATION_MESSAGE);
	}
	String showInput(String msg){
		String r = JOptionPane.showInputDialog(null, msg, "Input", JOptionPane.QUESTION_MESSAGE);
		return r;
	}
}
