package DynamicProgramming;

import java.util.HashMap;
import java.util.Scanner;

public class fibonacci_memo {
	
	public static int fib(int n) {
		return fib(n, new HashMap<>());
	}
	
	public static int fib(int n, HashMap<Integer, Integer> memo) {
		
		if(n == 1 || n == 0) {
			return n;
		}
		
		if(memo.containsKey(n)) {
			return memo.get(n);
		}
		
		int result = fib(n-1, memo) + fib(n-2, memo);
		memo.put(n, result);
		return result;
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a position:");
		int n = sc.nextInt();
		System.out.println("Fibonnaci number is "+fib(n));
		sc.close();
	}

}
