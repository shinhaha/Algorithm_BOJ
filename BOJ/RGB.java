import java.util.Scanner;
public class RGB {
	static int min(int a,int b){
		if (a<b)
			return a;
		else
			return b;
	}
	static int min3(int a,int b,int c){
		int min;
		if (a>b)
			min=b;
		else
			min=a;
		if(c<min)
			min=c;
		return min;
	}
	static void Rgb(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();//몇줄
		int dp[][]=new int[n+1][4];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++)
				dp[i][j]=sc.nextInt();
		
		for(int i=n; i>=1; i--)//최솟값을 뒤 부터 더해온다.
		{dp[i-1][1]+=min(dp[i][2],dp[i][3]);
		dp[i-1][2]+=min(dp[i][1],dp[i][3]);
		dp[i-1][3]+=min(dp[i][1],dp[i][2]);
		}	
		System.out.println(min3(dp[1][1],dp[1][2],dp[1][3]));	
	}
	public static void main(String[] args) {
		Rgb();
	}
}
