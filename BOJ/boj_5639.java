package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_5639 {

  private static Node root;
  private static StringBuilder sb;

  private static Node insert(final int number, Node node) {
    if(node == null) {
      return new Node(number);
    }

    if(node.number > number) {
      Node retVal = insert(number, node.left);
      if(retVal != null)
        node.left = retVal;
    }
    else {
      Node retVal = insert(number, node.right);
      if(retVal != null)
        node.right = retVal;
    }

    return null;
  }

  // left- right - root
  private static void printPostorder(Node node) {
    if(node.left != null)
      printPostorder(node.left);
    if(node.right != null)
      printPostorder(node.right);
    sb.append(node).append('\n');
  }

  /**
   * 입력값을 정수로 반환한다.
   * 반환값의 범위는 10^6보다 작은 양의 정수이다.
   * @return EOF인 경우 0을 반환한다.
   */
  private static int read(BufferedReader br) throws IOException {
    String input = br.readLine();
    if(input == null)
      return 0;
    return Integer.parseInt(input);
  }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int number = read(br);
    if(number == 0)
      return;
    root = insert(number,root);

    while (true) {
      number = read(br);
      if(number == 0)
        break;
      insert(number,root);
    }

    sb = new StringBuilder();
    printPostorder(root);
    sb.deleteCharAt(sb.length()-1);
    System.out.println(sb);
  }

  private static class Node {
    private int number;
    private Node left, right;

    public Node(int number) {
      this.number = number;
      this.left = null;
      this.right = null;
    }

    @Override
    public String toString() {
      return String.valueOf(number);
    }
  }

}
