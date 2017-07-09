import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class tomato {

	static int To() {
		Scanner sc=new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		int day=0;
		int dp[][]=new int[n][m];
		Queue<Node> q= new LinkedList();

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				dp[i][j]=sc.nextInt();
				if(dp[i][j]==1)
					q.offer(new Node(i,j));
			}

		int arrx[]={-1,1,0,0};//x좌우하상
		int arry[]={0,0,-1,1};//y좌우하상
		while(!q.isEmpty()){
			int qsize=q.size();
			for(int i=0; i<qsize; i++){
				Node temp=q.poll();
				int sx=temp.x;
				int sy=temp.y;
				for(int j=0; j<=3; j++){
					int tempx=sx+arrx[j];
					int tempy=sy+arry[j];
					if(tempx>=n||tempx<0||tempy<0||tempy>=m)//박스안의 범위가 아닐 경우
						continue;
					if(dp[tempx][tempy]==0)
						q.offer(new Node(tempx,tempy));
					if(dp[tempx][tempy]!=-1)//주변 토마토를 익힌다.
						dp[tempx][tempy]=1;			
				}
			}
			day++;
		}

		for(int i=0; i<n; i++)
			for(int j=0; j<m;j++)
				if(dp[i][j] == 0){
					System.out.println(-1); 
					return 0;}	     

		if(day == 0)System.out.println(0);
		else System.out.println(day-1);

		return (day-1);
	}

	static class Node{
		int x,y;
		public Node(int x,int y)
		{
			this.x=x;//x좌표
			this.y=y;//y좌표
		}
	}

	public static void main(String[] args){
		To();
	}
	
}