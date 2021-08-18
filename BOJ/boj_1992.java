package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_1992 {
    private static int N;
    private static char[][] map;

    private static String compress(String[] str) {
        boolean isPossible = true;
        StringBuilder temp = new StringBuilder();
        temp.append('(');
        if(str[0].startsWith("("))
            isPossible = false;
        for(int i=0;i<4;i++) {
            if(!str[0].equals(str[i])) {
                isPossible = false;
            }
            temp.append(str[i]);
        }
        temp.append(')');
        if(isPossible)
           return str[0];
        return temp.toString();
    }

    private static String recursive(int yPos, int xPos, int range) {
        if(range == 2) {
            String[] temp = new String[4];
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++)
                    temp[(i*2)+j] = String.valueOf(map[yPos+i][xPos+j]);
            }
            return compress(temp);
        }
        String[] list = new String[4];
        range = range >> 1;
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                list[(i*2)+j] = recursive(yPos+(range*i),xPos+(range*j),range);
            }
        }
        String result = compress(list);
        if(result.length() == 1)
            return result;
        else
            return compress(list);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        map = new char[N][];
        for(int i=0;i<N;i++)
            map[i] = br.readLine().toCharArray();

        System.out.println(recursive(0,0,N));
    }
}

/*
    66% 틀림

    [TC]
    4
    0101
    0000
    0101
    0000
 */