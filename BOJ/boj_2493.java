package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_2493 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();


        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        LinkedList<Integer> array = new LinkedList<>();
        LinkedList<Integer> stack = new LinkedList<>();
        array.add(Integer.parseInt(st.nextToken()));
        stack.add(0);
        sb.append("0 ");
        for(int i = 1;i<N;i++) {
            array.add(Integer.parseInt(st.nextToken()));
            while(!stack.isEmpty() && array.get(stack.getLast()) < array.get(i))
                stack.pollLast();
            if(stack.isEmpty())
                sb.append("0 ");
            else
                sb.append((stack.getLast()+1)+" ");
            stack.add(i);
        }
        System.out.println(sb);
    }
}
//
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//class Tower {
//    int num; // 탑 번호
//    int height;
//
//    Tower(int num, int height) {
//        this.num = num;
//        this.height = height;
//    }
//
//}
//
//public class boj_2493 {
//
//    public static void main(String[] args) throws Exception {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//
//        // 탑 개수
//        int N= Integer.parseInt(br.readLine());
//        Stack<Tower> tower = new Stack<>();
//        StringTokenizer st = new StringTokenizer(br.readLine()," ");
//        for (int i = 1; i <= N; i++) {
//            int height = Integer.parseInt(st.nextToken());
//            // System.out.println("탑높이 : " + height);
//            while (!tower.empty() && tower.peek().height < height) {
//                tower.pop();
//            }
//            if(tower.empty()) {
//                sb.append("0 ");
//            } else {
//                sb.append(tower.peek().num+" ");
//            }
//            tower.push(new Tower(i, height));
//        }
//        System.out.println(sb);
//    }
//}