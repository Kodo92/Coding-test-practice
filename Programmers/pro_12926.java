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
            if(answer[i]==' ')
                continue;
            char temp = Character.isLowerCase(answer[i]) ? 'a' : 'A';
            answer[i] = (char)(temp + (answer[i] + n - temp)%26);
        }

        return String.valueOf(answer);
    }
}
