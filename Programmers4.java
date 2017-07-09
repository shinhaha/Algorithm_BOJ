public class Programmers4 {
	int n;
	int count;
	int solution(int n){
		if(n==1)
			return count+1;
		if(n%2==0)
			return solution(n/2);
		else {
			count++;
			return solution(n-1);
		}
	}
	public static void main(String[] args) {
		Programmers4 q=new Programmers4();
		System.out.println(q.solution(3));
	}
}