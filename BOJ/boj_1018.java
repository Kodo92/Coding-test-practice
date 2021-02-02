import java.util.*;

public class boj_1018 {
    static char[] compared = {'W','B'};
    static String[] board;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int y = sc.nextInt(), x = sc.nextInt();

        board = new String[y];
        for(int i=0;i<y;i++)
            board[i] = sc.next();

        int answer = 64;

        for(int i=0;i<= y-8;i++)
        {
            for(int j=0;j<=x-8;j++) {
                int temp = Slove(i, j);
                answer = (answer > temp) ? temp : answer;
            }
        }
        System.out.println(answer);
    }

    static int Slove(final int y, final int x)
    {
        int retval = 64;
        for(int startIndex = 0 ; startIndex < 2 ; startIndex++) {
            int count = 0;
            for (int i = 0; i < 8; i++) {
                startIndex = (startIndex + 1) % 2;
                for (int j = 0; j < 8; j++) {
                    if (board[y + i].charAt(j + x) != compared[(startIndex + j) % 2])
                        count++;
                }
            }
            retval = (retval > count) ? count : retval;
        }
        return retval;
    }
}
