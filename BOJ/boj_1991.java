package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1991 {

  private int N;
  private Map<String, List<String>> tree = new HashMap<>();

  private void read() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    for (int i = 0; i < N; i++) {
      String[] temp = br.readLine().split(" ");
      tree.put(temp[0] , new ArrayList<>(Arrays.asList(temp[1],temp[2])));
    }
  }

  private void preorder(StringBuilder sb, String root) {
    sb.append(root);
    List<String> nodes = tree.get(root);
    if(!nodes.get(0).equals(".")) {
      preorder(sb,nodes.get(0));
    }
    if(!nodes.get(1).equals(".")) {
      preorder(sb,nodes.get(1));
    }
  }

  private void inorder(StringBuilder sb, String root) {
    List<String> nodes = tree.get(root);
    if(!nodes.get(0).equals(".")) {
      inorder(sb,nodes.get(0));
    }
    sb.append(root);
    if(!nodes.get(1).equals(".")) {
      inorder(sb,nodes.get(1));
    }
  }

  private void postorder(StringBuilder sb, String root) {
    List<String> nodes = tree.get(root);
    if(!nodes.get(0).equals(".")) {
      postorder(sb,nodes.get(0));
    }
    if(!nodes.get(1).equals(".")) {
      postorder(sb,nodes.get(1));
    }
    sb.append(root);
  }
  public static void main(String[] args) throws IOException {
    boj_1991 sol = new boj_1991();
    sol.read();

    // preorder
    StringBuilder sb = new StringBuilder();
    sol.preorder(sb,"A");
    System.out.println(sb);

    // Inorder
    sb = new StringBuilder();
    sol.inorder(sb,"A");
    System.out.println(sb);

    // Postorder
    sb = new StringBuilder();
    sol.postorder(sb,"A");
    System.out.println(sb);
  }
}
