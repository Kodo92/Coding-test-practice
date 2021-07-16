package boj;

import java.io.*;
import java.util.ArrayList;

public class boj_12015 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] inputLine = br.readLine().split(" ");

        ArrayList<Integer> list = new ArrayList<>();

        int number;
        list.add(0);
        for(int i=0;i<inputLine.length;i++) {
            number = Integer.parseInt(inputLine[i]);
            if(list.get(list.size()-1) < number)
                list.add(number);
            else {
                int left = 0, right = list.size()-1;
                int mid = 0;
                while(left < right) {
                    mid = (left + right)/2;
                    if(list.get(mid) < number) {
                        left = mid+1;
                    }
                    else
                        right = mid;
                }
                list.set(right,number);
            }
        }
        System.out.println(list.size()-1);
    }
}
