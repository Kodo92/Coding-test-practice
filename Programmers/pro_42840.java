import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class pro_42840 {
    public static void main(String[] args) {
        System.out.println(solution(new int[] {1,2,3,4,5}).toString());
    }

    public static int[] solution(int[] answers) {
        // Class pair 사용 : 20.08ms
        /*
        ArrayList<ArrayList> members = new ArrayList<>();
        members.add(new ArrayList(Arrays.asList(1,2,3,4,5)));
        members.add(new ArrayList(Arrays.asList(2,1,2,3,2,4,2,5)));
        members.add(new ArrayList(Arrays.asList(3,3,1,1,2,2,4,4,5,5)));

        Pair[] counts = new Pair[3];

        for(int i=0;i<3;i++)
            counts[i] = new Pair(i+1,0);

        for(int i=0;i<answers.length;i++)
        {
            for(int j=0;j<3;j++)
            {
                ArrayList temp = members.get(j);
                int length = temp.size();
                if(answers[i] == (int)temp.get(i%length))
                    counts[j].addValue();
            }
        }
        Arrays.sort(counts);
        ArrayList<Integer> answer = new ArrayList();
        answer.add(counts[0].getKey());
        int max = counts[0].getValue();
        for(int i=1;i<3;i++) {
            if(counts[i].getValue() == max)
                answer.add(counts[i].getKey());
            else
                break;
        }
        return answer.stream().mapToInt(i->i).toArray();
        */

        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};

        int[] count = new int[3];

        for(int i=0;i<answers.length;i++) {
            if ((answers[i] == one[(i % one.length)])) count[0]++;
            if ((answers[i] == two[(i % two.length)])) count[1]++;
            if ((answers[i] == three[(i % three.length)])) count[2]++;
        }

        int max = Math.max(count[0],Math.max(count[1],count[2]));
        ArrayList<Integer> answerList = new ArrayList();
        if(count[0] == max) answerList.add(1);
        if(count[1] == max) answerList.add(2);
        if(count[2] == max) answerList.add(3);

        int[] answer = new int[answerList.size()];
        int i = 0;
        for(int j : answerList)
            answer[i++] = j;
        // max : 9.99ms
        //return answerList.stream().mapToInt(a->a).toArray();

        // max : 0.89ms
        return answer;
    }
}

class Pair implements  Comparable<Pair>{
    private int key;
    private int value;

    public Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public void addValue() {
        this.value++;
    }

    @Override
    public int compareTo(Pair o) {
        return o.getValue() - this.value;
    }
}