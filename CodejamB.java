import java.util.Arrays;
import java.util.Scanner;

public class CodejamB {
	public void Code(){
		Scanner sc=new Scanner(System.in);
		String T=sc.nextLine();
		int X=Integer.parseInt(T);
		int count=0;
		int swap=0;
		
		while(count<X){
			String S=sc.nextLine();//����
			int[] a=new int[S.length()];//���ڱ��̸�ŭ ������ �迭����
			Arrays.fill(a,0);
			for(int x=0; x<a.length; x++){
				a[x]=Integer.parseInt(S.substring(x,x+1));
			}//�迭�� �߶� ����.
			
			for(int i=a.length-1; i>0; i--){
				if(a[i-1]<=a[i]&&a[i]!=0&&a[i-1]!=0)//���������̸�
					continue;
				else if (a[i]==-1){
					a[i]=9;
					a[i-1]--;
					i=i+1;}
				else if (a[i-1]==-1){
					a[i-1]=9;
					i=i+1;}
				else if (a[i-1]>a[i]||a[i-1]==0||a[i]==0){//���������ƴϸ�
					if(i==1&&a[0]==0)
						break;
					if(a[i]!=0){//0�̾ƴϸ�
						a[i]--;
						i=a.length;
					}
					else{//a[i]0�̸�
						a[i]=9;
						a[i-1]--;
						i=a.length;
					}
				}
			}
			for(int p=0; p<a.length; p++)
				if(a[p]!=0)
					break;
			System.out.print("Case #"+(count+1)+": ");
			for(int p=0; p<a.length; p++)
				System.out.print(a[p]);
			System.out.println();
			count++;
		}
	}

	public static void main(String[] args) {
		CodejamB a=new CodejamB();
		a.Code();
	}
}
