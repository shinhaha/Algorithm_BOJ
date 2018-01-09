import java.util.Scanner;

public class ClimbingStairs {//계단오르기
	static int max(int a,int b){
		if(a>b)
			return a;		
		else
			return b;
	}
	static void Stair(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();//몇개
		int stairs[]=new int[n+1];
		int dp[][]=new int[301][3];
		stairs[0]=0;
		for(int i=1; i<=n; i++)
			stairs[i]=sc.nextInt();
		dp[1][1]=dp[1][2]=stairs[1];
		for(int i=2; i<=n; i++)
		{dp[i][1]=dp[i-1][2]+stairs[i];//i번째 계단에 1계단 올라 온 경우 그 전에 두 계단 올라왔다.
		dp[i][2]=max(dp[i-2][1],dp[i-2][2])+stairs[i];//그 전 밟은 계단 중 최댓값.
		}
		System.out.println(max(dp[n][1],dp[n][2]));
	}
	public static void main(String[] args) {
		Stair();
	}
}
