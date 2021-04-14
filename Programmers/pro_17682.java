package programmers;

public class pro_17682 {
    public static void main(String[] args) {
        System.out.println(solution("1D2S#10S"));
    }

    public static int solution(String dartResult) {
        int[] scores = new int[3];
        int scoreIndex = 0;

        String number = "";
        for(int i=0;i<dartResult.length();i++) {
            final char c = dartResult.charAt(i);
            if(Character.isDigit(c)) {
                number += c;
            } else {
                if(number.length() != 0) {
                    scores[scoreIndex++] = Integer.parseInt(number);
                    number = "";
                }
                if(c == '*') {
                    scores[scoreIndex-1] *= 2;
                    if(scoreIndex-2 >= 0)
                        scores[scoreIndex-2] *= 2;
                } else if (c == '#') {
                    scores[scoreIndex - 1] *= -1;
                } else if (c == 'D'){
                    scores[scoreIndex - 1] = (int) Math.pow(scores[scoreIndex-1],2);
                } else if (c == 'T'){
                    scores[scoreIndex - 1] = (int) Math.pow(scores[scoreIndex-1],3);
                }
            }
        }

        int answer = 0;
        for(int i : scores)
            answer += i;
        return answer;
    }
}
