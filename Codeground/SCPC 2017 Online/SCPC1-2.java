import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node{
	boolean key;
	int count;
	int day;
	public Node(boolean a,int b,int c){
		key=a;
		count=b;
		day=c;
	}
}
public class SCPC2{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();//숫자
		int daycount=1;
		int maxcount=0;
		while(T>0){
			Queue<Node> q=new LinkedList();
			int n=sc.nextInt();
			int arr[]=new int[n+3];
			for(int i=1; i<=n; i++)
				arr[i]=sc.nextInt();//주가 입력
			arr[n+1]=-1;
			if(arr[1]<arr[2])
				q.add(new Node(true,1,1));
			else
				q.add(new Node(false,0,1));
			while(!q.isEmpty()){
				Node temp=q.poll();
				boolean have=temp.key;
				int count=temp.count;
				int day=temp.day;
				if(arr[day]==-1)
					continue;
				if(have){//키가 있을때
					if(arr[day]<arr[day+1])//다음날 더 비싸면
						q.add(new Node(false,count+1,day+1));//판다
					else//다음날 더 싸면
						q.add(new Node(false,count,day+1));//가만히 있는다.
				}		
				if(!have){//키가 없을때
					if(n-day!=1){//짝수번이라 하루남았다면 사지않음,가만히 있는것도 count셀 필요없음.
						if(arr[day]>arr[day+1]&&arr[day+1]<arr[day+2])
							q.add(new Node(true,count+1,day+1));//산다
						else
							q.add(new Node(false,count,day+1));//가만히
					}
				}
				if(maxcount<count&&count%2==0)
					maxcount=count;
			}//while
			System.out.println("Case #"+(daycount++));
			System.out.println(maxcount);
			T--;
		}//while
	}
}