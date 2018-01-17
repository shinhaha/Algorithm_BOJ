//boj 1197
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Kruskals {
	static Scanner sc;
	private int parent[];
	private int size;
	private long minCost=0;
	static PriorityQueue<Edge> pq;
	public Kruskals(int n) {
		this.size=n;
		this.parent=new int[size];
		Arrays.fill(parent,-1);
		int e=sc.nextInt();
		pq=new PriorityQueue<Edge>();
		for(int i=0; i<e; i++) 
			pq.add(new Edge(sc.nextInt()-1,sc.nextInt()-1,sc.nextInt()));
		kruskal();
	}
	public static void main(String[] args) {
		sc=new Scanner(System.in);
		int n=sc.nextInt();
		Kruskals x=new Kruskals(n);
	}

	public void weightedUnion(int i,int j){
		int x=collapsingFind(i);
		int y=collapsingFind(j);
		int newsize = parent[x] + parent[y];
		if (parent[x] >= parent[y]) {
			parent[x] = y;
			parent[y] = newsize;
		}
		else { 
			parent[y] = x;
			parent[x] = newsize;
		}
	}

	public int collapsingFind(int i){
		if(parent[i]<0)
			return i;
		return parent[i]=collapsingFind(parent[i]);
	}

	public void kruskal() {
		int mstSize=0;
		while(!pq.isEmpty()) {
			Edge x=pq.poll();
			if(collapsingFind(x.v)!=collapsingFind(x.w)) {
				weightedUnion(x.v,x.w);
				mstSize++;
				minCost+=x.weight;
				if(mstSize==size-1)
					break;
			}
		}
		System.out.println(minCost);
	}

	public static class Edge implements Comparable<Edge>{
		int v;
		int w;
		int weight;
		boolean selected;
		public Edge(int v,int w,int weight) {
			this.v=v;
			this.w=w;
			this.weight=weight;
		}
		@Override
		public int compareTo(Edge o) {
			if(this.weight-o.weight!=0)
				return this.weight-o.weight;
			else {
				if(this.v-o.v!=0)
					return this.v-o.v;
				else return this.w-o.w;
			}
		}
	}

}