package programmers;

public class pro_12943 {
    public static void main(String[] args) {
        System.out.println(solution(626331));
    }

    public static int solution(long num) {
        int count = 0;
        while(count < 499) {
            if(num == 1)
                return count;
            count++;
            if(num%2 == 0)
                num/=2;
            else
                num = (num*3)+1;
        }
        return -1;
    }
}
