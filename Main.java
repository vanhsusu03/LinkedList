import java.util.Scanner;
import java.util.Random;
public class Main {
    /**
     * gcd of a&b.
     */
    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 0) {
            return Math.abs(b);
        }
        if (b == 0) {
            return Math.abs(a);
        }
        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return a;
    }

    public static int gcd2(int a, int b) {
        if(b==0) return Math.abs(a);
        return gcd(b,a%b);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        for(int i=0;i<10000;i++)
        {
            int a = rand.nextInt((100000-(-435662)) ) + (-435662);
            int b = rand.nextInt((100000-(-43562)) ) + (-43562);
            if (gcd(a,b) != gcd2(a,b)) System.out.println("DIFFFF");
//            System.out.println("gcd1: " + gcd(a,b));
//            System.out.println("gcd2-N: " + gcd2(a,b));
        }

//        int n = sc.nextInt();
//        List<Integer> llist = new LinkedList<>();
//        for(int i=0; i<n;i++) {
//            llist.add(sc.nextInt());
//        }
//        int y= sc.nextInt();
//        int x = sc.nextInt();
//        int tmp=y;
//        List<Integer> newList = new LinkedList<>();
//        int i=0;
//        while (y>0 && i < llist.size()) {
//            newList.add(llist.get(i));
//            i++;
//            y--;
//            if( y == 0) {
//                y=tmp;
//                for(int j=0;j<x;j++) i++;
//            }
//        }
//        for(int j=0;j<newList.size();j++) System.out.print(newList.get(j) + " ");
    }
}