package test;

/*
	Math m = new Math();
	System.out.println(m.modulo(5, 3)); // Output: 2
*/

public class Math {
	int max(int a, int b){
		if(a > b){
			return a;
		}else{
			return b;
		}
	}
	int min(int a, int b){
		if(a < b){
			return a;
		}else{
			return b;
		}
	}
	int add(int a, int b){
		return a+b;
	}
	int subtract(int a, int b){
		return a-b;
	}
	int multiply(int a, int b){
		return a*b;
	}
	int divide(int a, int b){
		return a/b;
	}
	int modulo(int a, int b){
		return a%b;
	}
}
