import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;
public class Programmers5 {
	int V;
	int E;
	int start;
	int INF=Integer.MAX_VALUE;
	int solution(int N,int [][]road,int K){
		V=N;
		E=road.length;
		start=1;
		int dist[]=new int[V+1];
		int arr[][]=new int[V+1][V+1];
		Arrays.fill(dist,INF);
		for(int i=0; i<E; i++)
		{int x=road[i][0];
		int y=road[i][1];
		int z=road[i][2];
		int temp=arr[x][y];
		if(temp!=0)
		{	if(temp<z)
			z=temp;
		}
		arr[x][y]=z;
		arr[y][x]=z;
		}
		dist[start]=0;
		Queue<Node> q = new LinkedList<Node>();
		q.add(new Node(start,dist[start]));
		while(!q.isEmpty())
		{   
			Node temp=q.poll();
			int here=temp.index;
			int cost=temp.weight;
			if(cost>dist[here])
				continue;
			for(int x=0;x<=V;x++){
				if(arr[here][x]!=0 && dist[x] > dist[here]+arr[here][x]){//다이스트라
					dist[x] = dist[here]+arr[here][x];
					q.add(new Node(x,dist[x]));
				}
			}
		}
		int res=0;
		for(int i=1;i<=V;i++){
			if(dist[i]<=K)
				res++;
		}
		return res;
	}

	class Node{
		int weight;
		int index;
		public Node(int x,int y){
			index=x;
			weight=y;
		}
	}

	public static void main(String[] args) {
		Programmers5 q=new Programmers5();
		int a=5;
		int [][]b={{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
		int c=3;
		q.solution(a,b,c);
	}
}