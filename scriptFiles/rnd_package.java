package rnd;

public class rnd {
	
	static int RNDint() {
		return (int) RNDint(9);
	}
	
	static int RNDint(int t) {
		try {
			return (int) Math.round(Math.random() * t);
		} catch(Exception e) {
			return (int) 0;
		}
	}

	static double RNDdouble() {
		return (double) RNDdouble(9);
	}
	
	static double RNDdouble(int t) {
		try {
			return (double) Math.random() * t;
		} catch(Exception e) {
			return (double) 0;
		}
	}
	
	static boolean RNDboolean() {
		try {
			if(RNDint(1) == 0){
				return false;
			}else{
				return true;
			}
		} catch(Exception e) {
			return false;
		}
	}
	
	static byte RNDbyte() {
		return (byte) RNDbyte(9);
	}
	
	static byte RNDbyte(int t) {
		return (byte) RNDint(t);
	}
	
}
