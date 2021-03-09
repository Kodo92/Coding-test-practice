import java.util.function.*;

public class pro_12918 {
    public static void main(String[] args) {
        System.out.println(solution("1111121"));
    }

    static boolean solution(String s) {
        if(s.length() != 4 && s.length() != 6) return false;

        //Predicate<Character> predicate = (i) -> Character.isDigit(i);

        /*
        // max : 1.81ms
        for(char i : s.toCharArray()) {
            if(!predicate.test(i))
                return false;
        }
        */
        /*
        // max : 0.58ms
        char[] tmp = s.toCharArray();
        for(char i : tmp) {
            if(!predicate.test(i))
                return false;
        }
        return true;
         */

        // max : 0.7ms
        try {
            int retval = Integer.parseInt(s);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
