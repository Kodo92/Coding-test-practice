package boj;

import java.util.Scanner;

public class boj_1074 {
    private static int r,c;

    private static int getType(final int range) {
        int yIndex = (r%(range*2))/range, xIndex = (c%(range*2))/range;
        while(yIndex > 1)
            yIndex/=range;
        while(xIndex > 1)
            xIndex /= range;

        if(yIndex == 0 && xIndex == 0)
            return 0;
        else if(yIndex == 0 && xIndex == 1)
            return 1;
        else if(yIndex == 1 && xIndex == 0)
            return 2;
        else
            return 3;
    }

    private static int recursive(final int N, final int range) {
        if(N==1) {
            return ((r%2)*2) + (c%2);
        }
        return range*range*getType(range) + recursive(N-1,range/2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();

        System.out.println(recursive(N,(int)Math.pow(2,N-1)));
    }
}
