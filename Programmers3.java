public class Programmers3 {

	static int max(int a,int b){
		return a>b?a:b;
	}

	public static int solution(int sticker[]){
		int n=sticker.length;
		int[][][] dp=new int[n][2][2];
		dp[0][1][1]=sticker[0];
		dp[0][0][0]=0; dp[0][1][0]=0;
		for(int i=1; i<n; i++){//i번째 스티커를 뽑으면 1 안 뽑으면0  처음 스티커를 뽑았다면1 안 뽑았다면 0
			dp[i][0][1]+=max(dp[i-1][0][1],dp[i-1][1][1]);
			if(i!=n-1)
				dp[i][1][1]+=dp[i-1][0][1]+sticker[i];
			if(i==n-1)
				dp[i][1][1]+=dp[i-1][0][1];
			dp[i][0][0]+=max(dp[i-1][1][0],dp[i-1][0][0]);
			dp[i][1][0]+=dp[i-1][0][0]+sticker[i];
		}
		int ret=max(max(dp[n-1][0][1],dp[n-1][1][1]),max(dp[n-1][0][0],dp[n-1][1][0]));
		System.out.println(ret);
		return ret;
	}

	public static void main(String[] args) {
		int[] array={14, 6, 5, 11, 3, 9, 2, 10};
		solution(array);
	}
}