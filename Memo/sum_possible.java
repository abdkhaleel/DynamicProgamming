package DynamicProgramming;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
public class sum_possible {
	public static boolean sumPossible(int amount, List<Integer> numbers) {
		return sumPossible(amount, numbers, new HashMap<>());
	}
	public static boolean sumPossible(int amount, List<Integer> numbers, HashMap<Integer, Boolean> memo) {
		if(amount==0) {
			return true;
		}
		if(amount<0) {
			return false;
		}
		if(memo.containsKey(amount)) {
			return memo.get(amount);
		}
		for(int num: numbers) {
			int subAmount = amount-num;
			if(sumPossible(subAmount, numbers)) {
				memo.put(amount, true);
				return true;
			}
		}
		memo.put(amount, false);
		return false;
	}
	public static void main(String[] args) {
		List<Integer> numbers = new ArrayList<Integer> ();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the amount: ");
		int amount= sc.nextInt();
		System.out.println("Enter the size of integers: ");
		int n = sc.nextInt();
		int s;
		System.out.println("Enter the Integers: ");
		for(int i=0;i<n;i++) {
			s = sc.nextInt();
			numbers.add(s);
		}
		if(sumPossible(amount, numbers)) {
			System.out.println("Sum Exists");
		}
		else {
			System.out.println("Sum doesn't Exists");}
		}
}
