import java.util.*;
import java.util.function.IntPredicate;
import java.util.function.Predicate;

public class pro_12910 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(solution(new int[] {5,9,7,10},11)));
    }

    static int[] solution(int[] arr, int divisor) {
        /*
        // max : 17.08ms
        int[] answer = Arrays.stream(arr).filter(i -> i % divisor==0).sorted().toArray();
        return (answer.length==0) ? new int[] {-1} : answer;
        */

        /*
        max : 3.61ms
        ArrayList<Integer> temp = new ArrayList<>();
        for(int i : arr) {
            if (i % divisor == 0)
                temp.add(i);
        }
        int[] answer = new int[temp.size()];
        for(int i=0;i<answer.length;i++)
            answer[i] = temp.get(i);
        Arrays.sort(answer);
        return (answer.length==0)?new int[]{-1}:answer;
         */

        //max : 14.02ms
        ArrayList<Integer> temp = new ArrayList<>();
        for(int i : arr) {
            if (i % divisor == 0)
                temp.add(i);
        }
        int[] answer = temp.stream().sorted().mapToInt(i->i).toArray();
        return (answer.length==0)?new int[]{-1}:answer;
    }

}