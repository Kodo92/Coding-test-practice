package programmers;

import java.util.Arrays;

public class pro_42889 {
    public static void main(String[] args) {
        solution(5,new int[]{2,1,2,6,2,4,3,3});
    }

    public static int[] solution(int N, int[] stages) {
        Node[] array = new Node[N];
        for(int i=0;i<N;i++)
            array[i] = new Node();
        Arrays.sort(stages);
        int peopleCount = stages.length;
        int index = 0;
        for(int i=1; i<= N;i++) {
            int c = 0;
            for(int j=index;j<stages.length;j++) {
                if(stages[j] == i) c++;
                if(stages[j] > i) {
                    index = j;
                    break;
                }
            }
            if(peopleCount == 0) {
                array[i-1].failureRate = 0;
                array[i-1].index = i;
            } else {
                array[i - 1].failureRate = (float) c / peopleCount;
                array[i - 1].index = i;
            }
            peopleCount -= c;
        }

        int[] answer = new int[N];
        Arrays.sort(array);
        for(int i=0;i<array.length;i++) {
            answer[i] = array[i].index;
        }

        return answer;
    }
}

class Node implements Comparable<Node>{
    float failureRate;
    int index;

    @Override
    public int compareTo(Node o) {
        if(this.failureRate == o.failureRate) {
            return (this.index < o.index) ? -1 : 1;
        }
        return (this.failureRate > o.failureRate) ? -1 : 1;
    }
}