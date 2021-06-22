package boj;

import java.util.*;

public class boj_1697 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N,K;
        N = sc.nextInt();
        K = sc.nextInt();

        boolean[] isUsed = new boolean[100001];
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(0,N));
        isUsed[N] = true;

        while(!queue.isEmpty()) {
            Node now = queue.poll();
            int nowCost = now.getCost();
            int nowPosition = now.getPosition();

            if(nowPosition == K) {
                System.out.println(nowCost);
                break;
            }

            int nextCost = nowCost+1;
            if(nowPosition-1 >= 0 && !isUsed[nowPosition-1]) {
                isUsed[nowPosition-1] = true;
                queue.add(new Node(nextCost, nowPosition - 1));
            }
            if(nowPosition+1 <= 100000 && !isUsed[nowPosition+1]) {
                isUsed[nowPosition+1] = true;
                queue.add(new Node(nextCost, nowPosition + 1));
            }
            if(nowPosition*2 <= 100000 && !isUsed[nowPosition*2]) {
                isUsed[nowPosition*2] = true;
                queue.add(new Node(nextCost, nowPosition * 2));
            }
        }
    }


}

class Node implements  Comparable<Node> {
    private int cost;
    private int position;

    public Node(int cost, int position) {
        this.cost = cost;
        this.position = position;
    }

    public int getCost() {
        return cost;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    @Override
    public int compareTo(Node o) {
        return this.cost > o.getCost() ? 1 : -1;
    }
}