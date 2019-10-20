// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
	
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tokenizer = new StringTokenizer("");
	static String nextLine() throws IOException{// 读取下一行字符串
		return reader.readLine();
	}
	static String next() throws IOException {// 读取下一个字符串
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	static int nextInt() throws IOException {// 读取下一个int型数值
		return Integer.parseInt(next());
	}
    static long nextLong() throws IOException {// 读取下一个int型数值
		return Long.parseLong(next());
	}
	static double nextDouble() throws IOException {// 读取下一个double型数值
		return Double.parseDouble(next());
	}
	static List<Long> list = new ArrayList<>();
	static boolean Search(long current){
		if(current > n) return false;
		if(current == n) return true;
		for(long i=b;i>=a;i--) {
			if(current+i<=n) {
			    current+=i;
			    if(Search(current)) 
			    {list.add(i);return true;}
		    	current-=i;}
			
		}
		return false;
	}
	static long a;
	static long b;
	static long n;
	public static boolean Exist(long a,long b,long n) {
		if(n<a) return false;
		if(n>=a && n<=b) return true;
		for(long i=1;;i++) {
			long a2 = a*(i+1);
			long b2 = b*i;
			if(n<a){return false;}
			if(n>b2 && n<a2) {return false;}
			if(a2<=b2+1) {return true;}
			if(b>=2*a){return true;}
		}
		
	}
	public static void main (String[] args) throws java.lang.Exception {
		n = nextLong();
		a = nextLong();
		b = nextLong();
		boolean exist = false;
		for(long i=1;;i++) {
			long a2 = a*(i+1);
			long b2 = b*i;
			if(n<a){exist=false;break;}
			if(n>b2 && n<a2) {exist = false;break;}
			if(a2<=b2+1) {exist = true;break;}
			if(b>=2*a){exist=true;break;}
		}
		
		if(exist) {
			for(long t=b;t>=a;t--) {
				if(Exist(a,t,n-t)) {
					b=t;
					break;
				}
			}
			for(long t=a;t<=b;t++) {
				if(Exist(t,b,n-t)) {
					a=t;
					break;
				}
			}
			boolean ans = Search(0);
			Collections.sort(list);
			System.out.println("YES");
			for(int i=0;i<list.size();i++) {
				System.out.print(list.get(i)+" ");
			}
		}else {
			System.out.println("NO");
		}
		

	}
	
}