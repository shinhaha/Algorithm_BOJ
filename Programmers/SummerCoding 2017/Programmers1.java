public class Programmers1 {


	public int solution(int[] nums) {
		int answer = 0;
		int i,j,e;
		int temp;
		for(i=0; i<nums.length; i++)
			for(j=0; j<i; j++)
				for(e=0; e<j; e++){
					temp=nums[i]+nums[j]+nums[e];
					if(getPrime(temp)==true)
						answer++;
				}
		System.out.println(answer);
		return answer;
	}
	
	public static boolean getPrime(int num) {
		int i = num; // i : 나눌 대상
		boolean isPrime = true;
			for (int n = 2; n < i; n++) {
				if (i % n == 0) 
					return false;
				continue;
			}	
			return true;
	}

	public static void main(String[] args) {
		Programmers1 x= new Programmers1();
		int arr[]={1,2,7,6,4};
		x.solution(arr);
	}

}
