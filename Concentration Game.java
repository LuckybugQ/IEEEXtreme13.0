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
    public static double myPow(double x, long n) {
        if(x==0)return 0;
        if(n==1)return x;
        if(n==0)return 1;
        if(n==-1)return 1.0/x;
        
        if(n%2==0)
        {
            double temp=myPow(x,n/2);
            return temp*temp;
        }
        else 
        {
            double temp=myPow(x,(n-1)/2);
            return temp*temp*x;
        }
    }
	public static long Sum(double q,long n) {
		double a = 1 + 1/(1-q)*q - (n+1/(1-q))*myPow(q,n);
		double b = 1-q;
		return (long) (a/b*q);
	}
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		boolean win = false;
		int[] cards = {0,3,4,3,4,1,2,5,5,1,2};
		boolean[] removed = new boolean[2*n+1];
		Map<Integer,Integer> map = new HashMap<>();
		int match = 0;
		for(int i=1;i<2*n;i++){
		    for(int j=i+1;j<2*n+1;j++){
		    	//System.out.println(i+" "+j);
		    	if(!win && !removed[i] && !removed[j]) {
		        System.out.println(i+" "+j);
		        System.out.flush();
		        String s = in.next();
		        /*String s = "";
		        if(cards[i]==cards[j]) s = "MATCH";
		        else s = cards[i]+" "+cards[j];*/
		        if(s.equals("MATCH")){
		        	match += 1; if(match == n) win = true;
		            removed[i] = true;
		            removed[j] = true;
		        }else{
		            int a = Integer.valueOf(s);
		            String ss = in.next();
		            int b = Integer.valueOf(ss);
		            if(map.containsKey(a)) {
		            	int a2 = map.get(a);
		            	System.out.println(i+" "+a2);
				        System.out.flush();
				        String str = in.next();
				        //String str = "MATCH";
				        match += 1; if(match == n) win = true;
				        removed[i] = true;
			            removed[a2] = true;
		            }else {
		            	map.put(a,i);
		            	removed[i] = true;
		            }
		            
		            if(map.containsKey(b)) {
		            	int b2 = map.get(b);
		            	System.out.println(j+" "+b2);
				        System.out.flush();
				        String str = in.next();
				        //String str = "MATCH";
				        match += 1; if(match == n) win = true;
				        removed[j] = true;
			            removed[b2] = true;
		            }else {
		            	map.put(b,j);
		            	removed[j] = true;
		            }
		            
		        }
		        }
		    }
		}
		System.out.println(-1);
	}
	
}