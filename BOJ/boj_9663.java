package boj;

import java.util.Scanner;

public class boj_9663 {
    private static int N;
    private static int answer;
    private static int[] isUsed;

    private static boolean isCondition(final int yPos, final int xPos) {
        for(int i=0;i<N;i++) {
            if(isUsed[i] == -1) break;
            if(i == yPos) continue;
            if(xPos == isUsed[i] || Math.abs(yPos - i) == Math.abs(isUsed[i] - xPos))
                return false;

        }
        return true;
    }

    private static void DFS(final int yPos, final int count) {
        if(yPos == N) {
            if(count == N)
                answer++;
            return;
        }

        for(int i=0;i<N;i++) {
            if(isCondition(yPos,i)) {
                isUsed[yPos] = i;
                DFS(yPos+1,count+1);
                isUsed[yPos] = -1;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        isUsed = new int[N];
        for(int i=0;i<N;i++)
            isUsed[i] = -1;

        DFS(0,0);
        System.out.println(answer);

    }
}
