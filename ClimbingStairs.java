import java.util.Scanner;

public class ClimbingStairs {//��ܿ�����
	static int max(int a,int b){
		if(a>b)
			return a;		
		else
			return b;
	}
	static void Stair(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();//�
		int stairs[]=new int[n+1];
		int dp[][]=new int[301][3];
		stairs[0]=0;
		for(int i=1; i<=n; i++)
			stairs[i]=sc.nextInt();
		dp[1][1]=dp[1][2]=stairs[1];
		for(int i=2; i<=n; i++)
		{dp[i][1]=dp[i-1][2]+stairs[i];//i��° ��ܿ� 1��� �ö� �� ��� �� ���� �� ��� �ö�Դ�.
		dp[i][2]=max(dp[i-2][1],dp[i-2][2])+stairs[i];//�� �� ���� ��� �� �ִ�.
		}
		System.out.println(max(dp[n][1],dp[n][2]));
	}
	public static void main(String[] args) {
		Stair();
	}
}
