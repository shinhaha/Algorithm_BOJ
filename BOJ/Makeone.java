package floor;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Makeone {
	static void one(){
		int QSize;
		int temp=0;
		int count=0;
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();//¼ýÀÚ
		Queue q= new LinkedList();
		q.offer(n);
		while(!q.isEmpty()&&temp!=1){//BFS
			QSize=q.size();
			for(int i=0; i<QSize; i++)
			{temp=(int)q.poll();
			if(temp==1)
				break;
			if(temp%3==0)
				q.add(temp/3);
			else if(temp%2==0)
				q.add(temp/2);
			q.add(temp-1);
			}		
			if(temp==1)
				break;
			count++;
		}
		System.out.println(count);
	}
	public static void main(String[] args) {
		one();
	}
}