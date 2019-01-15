package rnd_passwd;

import java.util.Random;
import java.awt.Frame;
import java.awt.TextField;
import java.awt.Button;
import java.awt.Image;
import java.awt.event.WindowEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;

public class rnd_passwd extends Frame {
	
	private static final long serialVersionUID = 1L;

	private static String rndString(int l){
		Random rnd = new Random();
		String a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		String str = "";
		for(int i = 1; i <= l; i++){
			str += a.charAt(rnd.nextInt(a.length()));
		}
		return str;
	}

	public rnd_passwd(){
		
		int x = 40;
		int y = 40;
		
		setTitle("Random password");
		setSize((x+320), (y+40));
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		
		TextField il = new TextField();
		il.setBounds(x, y, 30, 20);
		il.setText("7");
		add(il);
		
		TextField re = new TextField();
		re.setBounds((x+30), y, 160, 20);
		re.setText("");
		add(re);

		Button b = new Button("Get password");
		b.setBounds((x+190), (y-1), 95, 20);
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String rsr = rndString(Integer.parseInt(il.getText()));
				re.setText(rsr);
			}
		});
		add(b);
		
		Image icon = new ImageIcon("data/images/icon.png").getImage();
		setIconImage(icon);
		
		setLayout(null);
		setVisible(true);
	}
	
	public static void main(String[] args){
		new rnd_passwd();
	}
}
