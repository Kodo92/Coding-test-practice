package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;

public class boj_2143 {
    private static HashMap<Long,Integer> getSum(int length, int[] arr) {
        HashMap<Long,Integer> arrayMap = new HashMap<>();

        for(int i=0;i<length;i++) {
            long sum = 0;
            for(int j=i;j<length;j++) {
                sum += arr[j];
                if(arrayMap.containsKey(sum))
                    arrayMap.replace(sum,arrayMap.get(sum)+1);
                else
                    arrayMap.put(sum,1);
            }
        }
        return arrayMap;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long T;
        int N,M;
        T = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        String[] temp = br.readLine().split(" ");
        for(int i=0;i<N;i++)
            A[i] = Integer.parseInt(temp[i]);

        M = Integer.parseInt(br.readLine());
        int[] B = new int[M];
        String[] temp1 = br.readLine().split(" ");
        for(int i=0;i<M;i++)
            B[i] = Integer.parseInt(temp1[i]);

        HashMap<Long, Integer> ACount = getSum(N,A);
        HashMap<Long, Integer> BCount= getSum(M,B);

        // ACount의 key와 BCount의 key를 조합해서 T를 만들어낸다.
        long answer = 0;
        Iterator<Long> keys = ACount.keySet().iterator();
        while(keys.hasNext()) {
            Long key = keys.next();
            Integer value = ACount.get(key);
            Integer result = BCount.get(T-key);
            if(result != null) {
                answer += result * value;
            }
        }
        System.out.println(answer);
    }
}

/**
 * [Debug Log]
 *      1. int overflow - 경우의 수 범위 체크!
 */