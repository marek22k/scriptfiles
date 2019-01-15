package modulo_gui;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.JOptionPane;

public class modulo_gui extends Frame {
	
	private static final long serialVersionUID = 1L;
	
	public static void main(String[] args){
		new modulo_gui();
	}
	
	public modulo_gui(){
		setTitle("Modulo GUI");
		setSize(500, 300);
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		
		// Set elements
		
		TextField m1 = new TextField();
		m1.setBounds(150, 75, 170, 20);
		m1.setText("");
		add(m1);
		
		TextField m2 = new TextField();
		m2.setBounds(150, 96, 170, 20);
		m2.setText("");
		add(m2);
		
		TextField r = new TextField();
		r.setBounds(150, 200, 170, 20);
		r.setText("");
		add(r);
		
		Button b = new Button("Get modulo");
		b.setBounds(215, 150, 100, 30);
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int mod1 = Integer.parseInt(m1.getText());
				int mod2 = Integer.parseInt(m2.getText());
				String res = "" + (mod1%mod2);
				r.setText(res);
				JOptionPane.showMessageDialog(null, m1.getText() + " mod " + m2.getText() + " = " + res, "Output", JOptionPane.INFORMATION_MESSAGE);
			}
		});
		add(b);
		
		Image icon = new ImageIcon("AppData/images/icon.png").getImage();
		setIconImage(icon);
		
		setLayout(null);
		setVisible(true);
	}
	
}
