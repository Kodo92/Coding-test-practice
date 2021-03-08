import java.util.*;

public class pro_12903 {
    public static void main(String[] args) {
        System.out.println(solution("ab"));
    }

    static String solution(String s) {
        return s.substring((s.length()-1)/2,s.length()/2+1);
    }
}
