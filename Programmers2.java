import java.util.Arrays;

class Programmers2 {

	boolean visit[];
	int i, j, e;
	int answer = 0;

	public int solution(int n, int[] stations, int w) {
		// n����������
		// w�¿�� �
		visit = new boolean[n+1]; //1~n

		for (i = 1; i <=stations.length; i++) {
			int temp = stations[i-1];
			int to,from;
			from=temp-w>0?temp-w:1;
			to=temp+w<=n?temp+w+1:n+1;	
			Arrays.fill(visit,from,to,true);
		}

		for (i = 1; i <= n; i++) {// ��ü�迭����       
			if (visit[i] == false){// ó�� trueã������
				answer++;
				int to=(i +2*w <= n)?i+2*w+1:n+1;
				Arrays.fill(visit,i,to,true);
				i+=2*w+1;//�ð�����
			}
		}
		return answer;
	}
	public static void main(String[] args) {
	Programmers2 a=new Programmers2();
	int []arr={9};
	a.solution(16,arr,2);
	}
}