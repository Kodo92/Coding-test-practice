package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_5052 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (; T > 0; T--) {
            int N = Integer.parseInt(br.readLine());
            String[] lists = new String[N];
            for (int i = 0; i < N; i++) {
                lists[i]=br.readLine();
            }

            Arrays.sort(lists);

            String answer = "YES";
            for (int i = 1; i < N; i++) {
                if(lists[i].startsWith(lists[i-1])) {
                    answer = "NO";
                    break;
                }
            }
            System.out.println(answer);
        }
    }
}
