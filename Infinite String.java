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
	static Set<String> targetSet = new HashSet<>();
	static List<String> result = new ArrayList<>();
	static boolean[] win;
	static int[] targetX;
	static int[] targetY;
	static int[] rookX;
	static int[] rookY;
	static int removeRook = -1;
	static int n;
	static Map<Integer,Integer> XSet = new HashMap<>();//第几行的棋子是第几个
	static Map<Integer,Integer> YSet = new HashMap<>();//第几列的棋子是第几个
	public static boolean Move(int i) {
		if(removeRook ==i) Put(i);
		int x = rookX[i];
		int y = rookY[i];
		int tx = targetX[i];
		int ty = targetY[i];
		if(tx>x) {
			MoveRight(i);
		}
		else if(tx<x) {
			MoveLeft(i); 
		}
		else if(ty>y) {
			MoveUp(i);
		}
		else {
			MoveDown(i);
		}
		return false;
	}
	public static boolean MoveRight(int i) {
		int x = rookX[i] + 1;
		if(XSet.containsKey(x)) {
			int num = XSet.get(x);
			if(win[num]) {
				queen.add(num);
				win[num] = false;
			}
			if(rookX[num]!=targetX[i] && rookY[num]!=targetY[i]) {
				if(removeRook==-1) {
					Remove(num);
				}
				else if(CheckPut()){
					Put(removeRook);
					Remove(num);
				}else {
					MoveRight(num);
				}
			}
			else {
				MoveRight(num);
			}
		}
		result.add(rookX[i]+" "+rookY[i]+" R");
		XSet.remove(rookX[i]);
		rookX[i] += 1;
		XSet.put(rookX[i],i);
		return true;
	}
	public static boolean MoveLeft(int i) {
		int x = rookX[i] - 1;
		if(XSet.containsKey(x)) {
			int num = XSet.get(x);
			if(win[num]) {
				queen.add(num);
				win[num] = false;
			}
			if(rookX[num]!=targetX[i] && rookY[num]!=targetY[i]) {
				if(removeRook==-1) {
					Remove(num);
				}
				else if(CheckPut()){
					Put(removeRook);
					Remove(num);
				}else {
					MoveLeft(num);
				}
			}
			else {
				MoveLeft(num);
			}
		}
		result.add(rookX[i]+" "+rookY[i]+" L");
		XSet.remove(rookX[i]);
		rookX[i] -= 1;
		XSet.put(rookX[i],i);
		return true;
	}
	public static boolean MoveDown(int i) {
		int y = rookY[i] - 1;
		if(YSet.containsKey(y)) {
			int num = YSet.get(y);
			if(win[num]) {
				queen.add(num);
				win[num] = false;
			}
			if(rookX[num]!=targetX[i] && rookY[num]!=targetY[i]) {
				if(removeRook==-1) {
					Remove(num);
				}
				else if(CheckPut()){
					Put(removeRook);
					Remove(num);
				}else {
					MoveDown(num);
				}
			}
			else {
				MoveDown(num);
			}
		}
		result.add(rookX[i]+" "+rookY[i]+" D");
		YSet.remove(rookY[i]);
		rookY[i] -= 1;
		YSet.put(rookY[i],i);
		return true;
	}
	public static boolean MoveUp(int i) {
		int y = rookY[i] + 1;
		if(YSet.containsKey(y)) {
			int num = YSet.get(y);
			if(win[num]) {
				queen.add(num);
				win[num] = false;
			}
			if(rookX[num]!=targetX[i] && rookY[num]!=targetY[i]) {
				if(removeRook==-1) {
					Remove(num);
				}
				else if(CheckPut()){
					Put(removeRook);
					Remove(num);
				}else {
					MoveUp(num);
				}
			}
			else {
				MoveUp(num);
			}
		}
		result.add(rookX[i]+" "+rookY[i]+" U");
		YSet.remove(rookY[i]);
		rookY[i] += 1;
		YSet.put(rookY[i],i);
		return true;
	}
	public static void Remove(int i) {
		result.add(rookX[i]+" "+rookY[i]+" T");
		XSet.remove(rookX[i]);
		YSet.remove(rookY[i]);
		removeRook = i;
	}
	public static void Put(int i) {
		result.add(rookX[i]+" "+rookY[i]+" P");
		XSet.put(rookX[i],i);
		YSet.put(rookY[i],i);
		removeRook = -1;
	}
	public static boolean CheckPut() {
		if(removeRook==-1) return true;
		int x = rookX[removeRook];
		int y = rookY[removeRook];
		if(!XSet.containsKey(x) && !YSet.containsKey(y)) return true;
		else return false;
	}
	static Queue<Integer> queen;
	public static long Sum(double q,long n) {
		double a = 1 + 1/(1-q)*q - (n+1/(1-q))*Math.pow(q, (double)n);
		double b = 1-q;
		return (long) (a/b*q);
	}
	public static void main (String[] args) throws java.lang.Exception {	
		int t = nextInt();
		for(int i=0;i<t;i++) {
			long num;
			long dis;
			int b = nextInt();
			long x = nextLong();
			long sum = 0;
			long presum = 0;
			long pow = 1;
			long[] list = new long[1000];
			if(b==1){
			    System.out.println('a');
			}else{
			for(int n=1;;n++) {
				if(b!=1) list[n-1] = pow;
				pow *= b;
				sum += pow*n;
				if(sum>=x) {
					num = n;
					dis = x - presum + 1;
					break;
				}
				presum = sum;
			}
			long id;
			if(dis%num==0) id = dis/num;
			else id = dis/num+1;
			long mod = dis % num;if(mod==0) mod=num;
			long count = num - mod;
			long tmp = (long) Math.pow(b,count);
			long t1;
			if(id%tmp==0) t1 = id/tmp - 1;
			else t1 = id/tmp;
			t1 = t1 % b;
			char c = (char) ('a' + t1);
			System.out.println(c);
			}
			
		}

	}
	
}