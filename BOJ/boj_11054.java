package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * [백준 11054] 제일 긴 바이토닉 부분 수열
 *  출처 : https://www.acmicpc.net/problem/11054
 */
public class boj_11054 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int[] numbers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    Node[] increase = new Node[N];
    Node[] decrease = new Node[N];
    increase[0] = new Node(numbers[0]);
    decrease[N-1] = new Node(numbers[N-1]);

    // decrease
    for (int i = N-2; i >= 0; i--) {
      if(numbers[i] > decrease[i+1].getLastValue()) {
        decrease[i] = new Node(decrease[i+1].add(numbers[i]));
      } else {
        decrease[i] = new Node(decrease[i+1].upperBound(numbers[i]));
      }
    }

    // increase
    for (int i = 1; i < N; i++) {
      if(numbers[i] > increase[i-1].getLastValue()) {
        increase[i] =  new Node(increase[i-1].add(numbers[i]));
      } else {
        increase[i] = new Node(increase[i-1].upperBound(numbers[i]));
      }
    }

    int answer = 1;
    for (int i = 0; i < N; i++) {
      if(i+1 >= N) break;
      int count = increase[i].getSize();
      int val = increase[i].getLastValue();
      for (int j = i+1; j < N; j++) {
        if(decrease[j].getLastValue() != val) {
          count += decrease[j].getSize();
          break;
        }
      }
      answer = Math.max(answer, count);
    }

    System.out.println(answer);
  }

  private static class Node {
    private ArrayList<Integer> list;
    private int lastValue;

    public Node(int val) {
      this.list = new ArrayList<>();
      this.list.add(val);
      this.lastValue = val;
    }

    public Node(ArrayList<Integer> list) {
      this.list = list;
      this.lastValue = list.get(list.size()-1);
    }

    public ArrayList<Integer> add(int val) {
      ArrayList<Integer> newList = new ArrayList<>(this.list);
      newList.add(val);
      return newList;
    }

    public ArrayList<Integer> upperBound(int val) {
      Integer[] temp = list.toArray(new Integer[list.size()]);
      int left = 0, right = temp.length, mid;
      while(left < right) {
        mid = (left + right) / 2;

        if(temp[mid] < val) {
          left =  mid + 1;
        } else {
          right = mid;
        }
      }
      temp[right] = val;
      return new ArrayList<>(Arrays.asList(temp));
    }

    public int getSize() {
      return list.size();
    }

    public int getLastValue() {
      return this.lastValue;
    }
  }
}
