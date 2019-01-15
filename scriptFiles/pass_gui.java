// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
	
*/

package pass_gui;

import java.awt.Frame;
import java.awt.Label;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.awt.geom.Line2D;
import javax.swing.JOptionPane;

public class pass_gui extends Frame {
	
	private static final long serialVersionUID = 1L;

	public static void main(String[] args) {
		new pass_gui();
		helpMessage();
	}
	
	private Label la = new Label("--> ");
	private boolean edit = false;
	private int len = 7;
	
	private int x = 400;
	private int y = 206;
	
	private static void helpMessage() {
		String helpString = "Press 'r'(random) for random number.\n\nPress 's'(set) and type a length for random number.\nExample: 's' '20' 's' = Set a length from 20\n\nPress 'h'(help) for help message\n\nPress e(exit) for quit application.";
		JOptionPane.showMessageDialog(null, helpString, "Help", JOptionPane.INFORMATION_MESSAGE);
	}
	
	private static void exitApp() {
		int s = JOptionPane.showConfirmDialog(null, "Exit application?");
		if(s == 0){
			System.exit(0);
		}
	}
	
	public pass_gui() {
		
		setTitle("Password GUI");
		setSize(x, y);
		setLayout(new FlowLayout(FlowLayout.LEFT, 60, 60));
		
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				exitApp();
			}
		});
		
		addKeyListener(new KeyListener() {
			
			@Override
			public void keyTyped(KeyEvent e) {
				try {
			        //System.out.println("'" + e.getKeyChar() + "'");
			        if(edit == false) {
			        	if(e.getKeyChar() == '\n' || e.getKeyChar() == 'r') {
			        		try {
				        		String a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
				        		String b = "";
				        		for(int i = 1; i <= len; i++){
				        			b += (String) "" + a.charAt( (int) Math.round( Math.random() * a.length() ) );
				        		}
				        		la.setText("--> " + b);
			        		} catch(Exception ex) {
			        			keyTyped(e);
			        		}
			        	}
			        	if(e.getKeyChar() == 's') {
			        		len = 0;
			        		edit = true;
			        	}
			        }else{
			        	try {
				        	if(e.getKeyChar() == 's'){
				        		edit = false;
				        	}else{
				        		if(len == 0) {
				        			len = Integer.parseInt(("" + e.getKeyChar()));
				        		}else{
				        			len = Integer.parseInt(("" + len + e.getKeyChar()));
				        		}
				        		System.out.println(len);
				        	}
			        	} catch(Exception ex) {
			        		edit = false;
			        	}
			        }
					} catch(Exception ex) {
						JOptionPane.showMessageDialog(null, ex.toString(), "Error", JOptionPane.ERROR_MESSAGE);
					}
			        setVisible(true);
			        if(e.getKeyChar() == 'h') {
			        	helpMessage();
			        }else if(e.getKeyChar() == 'e') {
			        	exitApp();
			        }
			}
			
			public void keyReleased(KeyEvent e) {}
			public void keyPressed(KeyEvent e) {}
		});

		add(la);
		
		//setLayout(null);
		setVisible(true);
		
	}



	public void paint(Graphics g){
	  Line2D l = new Line2D.Double();
      Graphics2D gd = (Graphics2D) g;
      
      l.setLine(50, 50, (x-50), 50);
      gd.draw(l);
      
      l.setLine(50, (y-50), (x-50), (y-50));
      gd.draw(l);
      
      l.setLine(50, 50, 50, (y-50));
      gd.draw(l);
      
      l.setLine((x-50), 50, (x-50), (y-50));
      gd.draw(l);
	}
}
