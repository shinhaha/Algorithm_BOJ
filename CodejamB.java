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
			String S=sc.nextLine();//문자
			int[] a=new int[S.length()];//문자길이만큼 길이의 배열만듬
			Arrays.fill(a,0);
			for(int x=0; x<a.length; x++){
				a[x]=Integer.parseInt(S.substring(x,x+1));
			}//배열에 잘라서 넣음.
			
			for(int i=a.length-1; i>0; i--){
				if(a[i-1]<=a[i]&&a[i]!=0&&a[i-1]!=0)//오름차순이면
					continue;
				else if (a[i]==-1){
					a[i]=9;
					a[i-1]--;
					i=i+1;}
				else if (a[i-1]==-1){
					a[i-1]=9;
					i=i+1;}
				else if (a[i-1]>a[i]||a[i-1]==0||a[i]==0){//오름차순아니면
					if(i==1&&a[0]==0)
						break;
					if(a[i]!=0){//0이아니면
						a[i]--;
						i=a.length;
					}
					else{//a[i]0이면
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
