package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class boj_1365 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] datas = br.readLine().split(" ");

        ArrayList<Integer> arrayList = new ArrayList<>();
        for(String str : datas) {
            if(arrayList.isEmpty()) {
                arrayList.add(Integer.parseInt(str));
                continue;
            }

            int lastValue = arrayList.get(arrayList.size()-1);
            int number = Integer.parseInt(str);

            if(lastValue > number) {
                int left = 0, right = arrayList.size() - 1;
                int mid;
                while (left < right) {
                    mid = (left + right) / 2;
                    int midValue = arrayList.get(mid);
                    if (midValue < number)
                        left = mid + 1;
                    else
                        right = mid;
                }
                arrayList.set(right,number);
            } else {
                arrayList.add(number);
            }
        }
        System.out.println(N-arrayList.size());
        return;
    }
}
