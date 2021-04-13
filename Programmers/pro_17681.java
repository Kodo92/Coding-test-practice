package programmers;

import java.util.Arrays;

public class pro_17681 {
    public static void main(String[] args) {
        String[] retval = solution(6,new int[]{46, 33, 33, 22, 31, 50}, new int[]{27, 56, 19, 14, 14, 10});
        for (String s : retval) {
            System.out.println(s);
        }
    }

    public static String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for (int i=0 ; i<n ; i++) {
            answer[i] = Integer.toBinaryString(arr1[i] | arr2[i]);
            answer[i] = String.format("%"+n+"s",answer[i]);
            answer[i] = answer[i].replace("1","#");
            answer[i] = answer[i].replace("0"," ");
        }

        return answer;
    }
}

/*
예외 :
toBinaryString()의 return string length < n 인 경우 앞에 0 추가해줘야함
    ex) 11110 -> 011110


 */