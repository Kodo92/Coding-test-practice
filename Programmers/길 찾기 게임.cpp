#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> answer;

typedef struct node {
	int num;
	int x;
	struct node *left;
	struct node *right;
};
typedef struct qnode {
	int x;
	int y;
	int num;
};

struct cmp {
	bool operator()(qnode a, qnode b) {
		if (a.y == b.y)
			return a.x > b.x;
		return a.y < b.y;
	}
};

node *root;

void find(node *curr, node *newNode) {

	if (curr->x > newNode->x && curr->left != NULL) { //���� ��庸�� �����ε� �̹� ���� �ڽ� ��� ����
		find(curr->left, newNode);
	}
	else if (curr->x > newNode->x && curr->left == NULL) {
		curr->left = newNode;
	}
	else if (curr->x < newNode->x && curr->right != NULL) {
		find(curr->right, newNode);
	}
	else {
		curr->right = newNode;
	}
}

void preorder(node *curr) {
	if (curr == NULL)
		return;
	answer[0].push_back(curr->num);
	preorder(curr->left);
	preorder(curr->right);
}
void postorder(node *curr) {
	if (curr == NULL)
		return;
	postorder(curr->left);
	postorder(curr->right);
	answer[1].push_back(curr->num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

	priority_queue< qnode, vector<qnode>, cmp> nodes;
	//y���� Ŭ���� x���� �������� �켱������ �ǵ���
	qnode input;
	answer.resize(2);

	for (int i = 0; i<nodeinfo.size(); i++) {
		input.x = nodeinfo[i][0];
		input.y = nodeinfo[i][1];
		input.num = i + 1;
		nodes.push(input);
	}

	qnode curr, before;
	node *newNode, *tmp;

	newNode = (node *)malloc(sizeof(node));
	curr = nodes.top();
	nodes.pop();
	newNode->num = curr.num;
	newNode->x = curr.x;
	newNode->left = newNode->right = NULL;
	root = newNode;

	while (!nodes.empty()) {
		curr = nodes.top();
		nodes.pop();
		newNode = (node *)malloc(sizeof(node));
		newNode->num = curr.num;
		newNode->x = curr.x;
		newNode->left = newNode->right = NULL;
		find(root, newNode);
	}

	preorder(root);
	postorder(root);

	return answer;
}
void main()
{
	solution({ {5,3},{11,5},{13,3},{3,5 },{6,1},{1,3},{8,6},{7,2},{2,2} });
}