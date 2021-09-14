package boj;

import java.util.Arrays;
import java.util.Scanner;

public class boj_1463 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        if(N==1) {
            System.out.println(0);
            return;
        }

        int[] dp = new int[1000001];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[1] = 0;
        dp[2] = dp[3] = 1;

        for(int i=4;i<=N;i++) {
            if(i%3 == 0) dp[i] = Math.min(dp[i],dp[i/3]+1);
            if(i%2 == 0) dp[i] = Math.min(dp[i],dp[i/2]+1);
            dp[i] = Math.min(dp[i],dp[i-1]+1);
        }

        System.out.println(dp[N]);
    }
}

/*
    N에서 /3, /2, -1한 것들 중 최소값이 정답이라는 보장이 없다.
 */