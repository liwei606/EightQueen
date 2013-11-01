import static java.lang.Math.*;

public class EightQueen
{
	// Eight Queen so n is set to 8
	static int n = 8;
	static int[] a = new int[8];
	static int answers = 0;
	
	public static boolean ok(int r, int c) {
		for (int i = 0; i < r; ++i) {
			if (a[i] == c || (abs(c - a[i]) == abs(r - i))) return false;
		}
		return true;
	}
	
	public static void search(int r) {
		if (r == n) {
			++answers;
			System.out.printf("\nThe NO. %d answer\n", answers);
			System.out.printf("row\tcolumn\n");
			for (int i = 0; i < n; ++i) {
				System.out.printf("%d:\t%d\n", i, a[i]);
			}
		}
		for (int c = 0; c < n; ++c) {
			if (ok(r, c)) {
				a[r] = c;
				search(r + 1);
				a[r] = -1;
			}
		}
	}

	public static void main(String[] args) {
		for (int i = 0; i < n; ++i) {
			a[i] = -1;
		}
		search(0);
	}
}
