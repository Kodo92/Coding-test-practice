import java.util.Arrays;

public class pro_12926 {
    public static void main(String[] args) {
        System.out.println(solution("z",25));
    }

    public static String solution(String s, int n) {
        char[] answer = new char[s.length()];
        for(int i=0;i<s.length();i++)
        {
            answer[i] = s.charAt(i);
            char temp = answer[i];
            if(answer[i] == ' ') continue;
            answer[i] += n;
            if(temp >= 'a' && temp <= 'z' && answer[i] > 'z') {
                answer[i] = (char)((answer[i] % 'z') + 'a'-1);
            } else if(temp <= 'A' && temp >= 'Z'&& answer[i] > 'Z'){
                answer[i] = (char)((answer[i] % 'Z') + 'A'-1);
            }
        }

        return String.valueOf(answer);
    }
}
