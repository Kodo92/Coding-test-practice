package programmers;

import java.util.LinkedList;

public class pro_84512 {
    private LinkedList<String> list;
    private char[] vowels = {'A','E','I','O','U'};

    private boolean recursive(final String word, int level, StringBuilder sb) {
        list.add(sb.toString());
        if(sb.toString().equals(word))
            return true;
        if(level > 4)
            return false;


        for(int i=0;i<5;i++) {
            sb.append(vowels[i]);
            if(recursive(word,level+1,sb))
                return true;
            sb.delete(sb.length()-1,sb.length());
        }
        return false;
    }

    public int solution(String word) {
        list = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<5;i++) {
            sb.append(vowels[i]);
            if(recursive(word,1,sb))
                break;
            sb.delete(sb.length()-1,sb.length());
        }
        return list.size();
    }

    public static void main(String[] args) {
        pro_84512 pro = new pro_84512();
        System.out.println(pro.solution("AAAE"));
    }
}

/*
[Wow Code]

    public int solution(String word) {
        int answer = 0, per = 3905;
        for(String s : word.split("")) answer += "AEIOU".indexOf(s) * (per /= 5) + 1;
        return answer;
    }
 */