import java.util.*;

public class pro_1845 {
    public static void main(String[] args) {
        System.out.println(solution(new int[]{3,1,2,3}));
    }

    public static int solution(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for(int i =0; i<nums.length;i++) {
            set.add(nums[i]);
        }

        if(set.size()>nums.length/2)
            return nums.length/2;

        return set.size();
    }
}
