package DynamicProgramming;
import java.util.*;

public class countPath {
	public static int countpath(int r, int c, List<List<String>> grid) {
		return countpath(0, 0, grid, new HashMap<>());
	}
	public static int countpath(int r, int c, List<List<String>> grid, HashMap<List<Integer>,Integer> memo) {
		if(r == grid.size() || c == grid.get(0).size()) {
			return 0;
		}
		if(grid.get(r).get(c).equals("X")) {
			return 0;
		}
		List<Integer> pos = List.of(r, c);
		if(memo.containsKey(pos)) {
			return memo.get(pos);
		}
		if(r == grid.size()-1 && c == grid.get(0).size()-1) {
			return 1;
		}
		int result = countpath(r+1, c, grid, memo) + countpath(r, c+1, grid, memo);
		memo.put(pos, result);
		return result;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the number of rows:");
		int rows = scanner.nextInt();
		System.out.println("Enter the number of columns:");
		int cols = scanner.nextInt();
		List<List<String>> grid = new ArrayList<>();
		System.out.println("Enter the grid elements (O for open path, X for obstacle):");
		for(int i=0; i<rows; i++) {
			List<String> row = new ArrayList<>();
			for(int j=0; j<cols; j++) {
				row.add(scanner.next());
			}
			grid.add(row);
		}
		scanner.close();
		int result = countpath(rows, cols, grid);
		System.out.println("Number of paths: " + result);
	}
}
