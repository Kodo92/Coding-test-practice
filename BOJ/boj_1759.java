package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1759 {
    private static int L,C;
    private static String[] inputs;
    private static StringBuilder sb;
    private static String vowels = "aeoiu";
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        inputs = br.readLine().split(" ");
        Arrays.sort(inputs);
        sb = new StringBuilder();

        combination(-1,0,0);

        System.out.print(sb);
    }

    private static void combination(final int index, int flag, int level) {
        if(level == L) {
            StringBuilder temp = new StringBuilder();
            int vowelCount = 0;
            int consonantCount = 0;
            for(int i=0;i<C;i++) {
                if((flag & (1 << i)) != 0) {
                    temp.append(inputs[i]);
                    if(vowels.contains(inputs[i]))
                        vowelCount++;
                    else
                        consonantCount++;
                }
            }
            if(vowelCount >= 1 && consonantCount >= 2)
                sb.append(temp).append('\n');
            return;
        }

        for(int i=index+1;i<C;i++) {
            if((flag & (1 << i)) != 0) continue;
            flag |= 1 << i;
            combination(i,flag,level+1);
            flag -= 1 << i;
        }
    }
}
