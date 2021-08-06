package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_2477 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());

        int[] distances = new int[6];
        int maxHeight = 0;
        int heightIndex = 0;
        int maxWidth = 0;
        int widthIndex = 0;
        for(int i=0;i<6;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int dir = Integer.parseInt(st.nextToken())-1;
            distances[i] = Integer.parseInt(st.nextToken());
            if(dir==0 || dir == 1) {
                if(maxWidth >= distances[i]) continue;
                maxWidth = distances[i];
                widthIndex = i;
            }
            else {
                if(maxHeight >= distances[i]) continue;
                maxHeight = distances[i];
                heightIndex = i;
            }
        }

        int referenceIndex = -1;
        if((heightIndex+1)%6 != widthIndex) {
            referenceIndex = heightIndex;
        } else {
            referenceIndex = widthIndex;
        }

        int diff = distances[(referenceIndex+2)%6] * distances[(referenceIndex+3)%6];
        System.out.println(((maxHeight*maxWidth)-diff)*K);
    }
}

/*
    1. 중복된 방향 처음 나오면 2번째, 두번째는 1번째 좌표가 빈공간이라고 판단 ->
        ┛ 일 때 시작 좌표를 파인곳 꼭지점에서 시작하면 성립하지 않음.
    2.  Full height, width 는 마주하고 있다. 반시계 방향이니까 제일 마지막에 나온 가장 긴 길이 + 2,3index **
 */