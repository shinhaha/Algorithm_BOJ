import java.util.Arrays;
import java.util.Scanner;

public class CodejamA {
	
	public void Code() {
		Scanner sc = new Scanner(System.in);
		String tmp = sc.nextLine();
		int T = Integer.parseInt(tmp);// ���ٹ������ΰ�
		int count = 0;
		int swap = 0;
		
		while (count < T) {
			String S = sc.nextLine();//+,-
			String[] H=S.split(" ");
			String[] a = new String[H[0].length()];//���� ���̸�ŭ�� �迭
			boolean visit[] = new boolean[a.length];
			Arrays.fill(a,"");
			Arrays.fill(visit,true);
			for (int x = 0; x <a.length; x++) {
				a[x] = S.substring(x,x+1);
			}//�迭�� �߶� ����.
			int K = Integer.parseInt(H[H.length-1]);
			for (int x=0; x<a.length; x++){
				if (a[x].equals("-")) {// ���ٰ� - ������
					if (((x + K)<=a.length)) {// �迭�ʰ����ƴϸ�
						swap++;
						for (int y = 0; y < K; y++) {// k�� �����´�
							if(a[x + y].equals("-")&&visit[x + y]) {
								a[x + y] = "+";
								visit[x + y] = false;
							}
							if(a[x + y].equals("+")&&visit[x + y]) {
								a[x + y] = "-";
								visit[x + y] = false;
							}
						}
						for (int y = 0; y<K; y++)
							visit[x + y] = true;
					}
					else break; // �迭�ʰ� break
				}
				if(a[x].equals("+"))// ���ٰ� +������
					continue;
			}
			for (int x = 0; x < a.length; x++) {
				if (a[x].equals("-")) {
					System.out.println("Case #" + (count + 1) + ": IMPOSSIBLE");
					break;
				}
				if (x == a.length - 1 && a[a.length - 1].equals("+"))
					System.out.println("Case #" + (count + 1) + ": " + swap);
			}
			swap = 0;
			count++;
		}
	}
	
	public static void main(String[] args) {
		CodejamA a = new CodejamA();
		a.Code();
	}
}
