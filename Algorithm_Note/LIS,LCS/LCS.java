import java.util.Scanner;
import java.util.Stack;
//boj 9252
public class LCS {
	static int count;
	static Stack s=new Stack();
	static void print(char[][] dp,String arr,int m,int n) {
		while(m!=0&&n!=0) {
			if(dp[m][n]=='u') {
				m--;
			}
			else if(dp[m][n]=='l') {
				n--;
			}
			else {
				count++;
				s.push(arr.charAt(m-1));
				m--; n--;
			}
		}
		System.out.println(count);
		for(int i=0; i<s.size(); i++)
			System.out.print(s.get(s.size()-i-1));
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String d=sc.next();
		int m = a.length();//첫번째 문장의 길이
		int n = d.length();//두번째 문장의 길이
		int c[][]=new int[m+1][n+1];
		char b[][]=new char[m+1][n+1];
		for (int i = 1; i <= m; i++)//초기화
			c[i][0] = 0;
		for (int j = 0; j <= n; j++)//초기화
			c[0][j] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (a.charAt(i-1) == d.charAt(j-1)) {//문자가 같으면
					c[i][j] = c[i - 1][j - 1] + 1;//+1
					b[i][j] = 'q';//대각선
				}
				else if (c[i - 1][j] >= c[i][j - 1]) {//max(이전 값)
					c[i][j] = c[i - 1][j];
					b[i][j] = 'u';//up
				}
				else {
					c[i][j] = c[i][j - 1];
					b[i][j] = 'l';//left
				}
			}
		}
		print(b,a,m,n);
	}
}
