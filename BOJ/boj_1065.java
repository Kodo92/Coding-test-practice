import java.util.*;

public class boj_1065 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        sc.close();

        if(n < 100)
            System.out.println(n);
        else
        {
            // n이 3자리인 경우
            int count = 0;
            for(int i=100;i<=n;i++) {
                int one, ten, hundred;
                one = i % 10;
                ten = (i%100) / 10;
                hundred = i / 100;
                if (hundred-ten == ten-one)
                    count++;
            }
            System.out.println(99+count);
        }
    }
}
