package programmers;

public class pro_12947 {
    public static void main(String[] args) {
        System.out.println(solution(10));
    }

    public static boolean solution(int x) {
/*
        String str = ""+x;
        int sum = 0;
        char[] chars = str.toCharArray();
        for(char c : chars) {
            sum +=  c - '0';
        }
*/
        String[] str = String.valueOf(x).split("");
        int sum = 0;
        for(String s : str)
            sum += Integer.parseInt(s);

        return (x%sum == 0) ? true : false;
    }
}
