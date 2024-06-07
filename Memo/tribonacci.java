package DynamicProgramming;

import java.util.HashMap;
import java.util.Scanner;

public class tribonacci {
	public static int tribo(int n) {
		return tribo(n, new HashMap<>());
		
	}
	public static int tribo(int n, HashMap<Integer, Integer> memo) {
		if(n==0||n==1) {
			return 0;
		}
		else if(n==2) {
			return 1;
		}
		if(memo.containsKey(n)) {
			return memo.get(n);
		}
		int result = tribo(n-1, memo)+tribo(n-2, memo)+tribo(n-3, memo);
		memo.put(n, result);
		return result;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a position:");
		int n = sc.nextInt();
		System.out.println("tribonacci number is "+tribo(n));
		sc.close();
	}
}
