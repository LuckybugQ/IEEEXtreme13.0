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
	public static int Search(int x ,int y,int count,boolean[][] visited) {
		//System.out.println(x+" "+y);
		visited[x][y] = true;
		int[] xs = new int[7];
		int[] ys = new int[7];
		if(x%2==0) {
			xs[1] = x-1; ys[1] = y;
			xs[2] = x-1; ys[2] = y+1;
			xs[3] = x; ys[3] = y-1;
			xs[4] = x; ys[4] = y+1;
			xs[5] = x+1;ys[5] = y;
			xs[6] = x+1; ys[6] = y+1;	
		}else {
			xs[1] = x-1; ys[1] = y-1;
			xs[2] = x-1; ys[2] = y;
			xs[3] = x; ys[3] = y-1;
			xs[4] = x; ys[4] = y+1;
			xs[5] = x+1;ys[5] = y-1;
			xs[6] = x+1; ys[6] = y;	
		}
		for(int i=1;i<=6;i++) {
			
			if(xs[i]<=0 || xs[i]>=n+1 || ys[i]<=0 || ys[i]>=m+1) {
				count+=1;
				continue;
			}
			if(!visited[xs[i]][ys[i]]) {
			if(act[xs[i]][ys[i]]) {
				count = Search(xs[i],ys[i],count,visited);
			}else {
				count+=1;
			}}
		}
		
		return count;
	}
	static boolean[][] act;
	static int n;
	static int m;
	public static boolean Check(String s) {
		 for(int j=1;j<s.length();j++) {
			   char c1 = s.charAt(j-1);
			   char c2 = s.charAt(j);
			   if(c2<c1) {
				   String s1 = s.substring(0,j);
				   String s2 = s.substring(j,s.length());
				   if(s1.compareTo(s2)>0) {
					   return false;
				   }else {
					boolean b1 = Check(s1);
					boolean b2 = Check(s2);
					if(b1 && b2) return true;
					else return false;
				   }
			   }
		   }
		 return true;
	}
	public static void main (String[] args) throws java.lang.Exception {
	   int q = nextInt();
	   for(int i=0;i<q;i++) {
		   String s = nextLine();
		   if(Check(s)) System.out.print('1');
		   else System.out.print('0');
	   }
	}
	
}