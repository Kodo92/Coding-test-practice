package programmers;

import java.util.Arrays;

public class pro_12932 {
    public static void main(String[] args) {
        System.out.println( Arrays.toString(solution(12345)));
    }

    private static int[] solution(long n) {
        String[] str = String.valueOf(n).split("");
        int[] answer = new int[str.length];
        int length  = str.length-1;
        for(int i=0;i<=length;i++) {
            answer[i] = Integer.valueOf(str[length-i]);
        }
        return answer;
    }
}
