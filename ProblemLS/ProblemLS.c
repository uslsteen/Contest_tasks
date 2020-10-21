#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct tree_t
{
	struct tree_t* left;
	struct tree_t* right;
	int data;
};

const int is_search = 1;
const int isnt_search = 0;

struct tree_t* read_tree();

int Is_Search_Tree(struct tree_t* node, struct tree_t* left, struct tree_t* right);

struct tree_t* read_tree_structure(struct tree_t** nodes, int n);


int main()
{
	struct tree_t* head = NULL;
	struct tree_t* left = NULL;
	struct tree_t* right = NULL;
	int result = -1;

	head = read_tree();

	result = Is_Search_Tree(head, left, right);
	printf("%d", result);

	return 0;
}

int Is_Search_Tree(struct tree_t* node, struct tree_t* left, struct tree_t* right)
{
	if (node == NULL)
	{
		return is_search;
	}

	if (left != NULL && left->data >= node->data)
	{
		return isnt_search;
	}

	if (right != NULL && right->data <= node->data)
	{
		return isnt_search;
	}


	return (Is_Search_Tree(node->left, left, node) && Is_Search_Tree(node->right, node, right));
}


struct tree_t* read_tree_structure(struct tree_t** nodes, int n)
{
	int i = 0;
	struct tree_t* head = NULL;
	int* nodemarks;

	assert(nodes != NULL);

	nodemarks = (int*)calloc(n, sizeof(int));
	assert(nodemarks != NULL);

	for (; ;)
	{
		int res, parent, left, right;

		res = scanf("%d %d %d", &parent, &left, &right);
		if (res != 3)
			break;

		assert(parent >= 0);

		assert(parent < n && left < n && right < n);

		nodemarks[parent] += 1;

		if (left != -1)
		{
			nodes[parent]->left = nodes[left];
			nodemarks[left] -= 1;
		}

		if (right != -1)
		{
			nodes[parent]->right = nodes[right];
			nodemarks[right] -= 1;
		}
	}

	for (i = 0; i < n; ++i)
		if (nodemarks[i] > 0)
		{
			assert(head == NULL);
			head = nodes[i];
		}

	free(nodemarks);
	return head;
}

struct tree_t* read_tree()
{
	int res = 0, i = 0, n = 0;
	struct tree_t* head = NULL;
	struct tree_t** nodes;

	res = scanf("%d", &n);
	assert(res == 1);

	nodes = (struct tree_t**) calloc(n, sizeof(struct tree_t*));
	assert(nodes != NULL);

	for (i = 0; i < n; ++i) {
		nodes[i] = (struct tree_t*) calloc(1, sizeof(struct tree_t));
		assert(nodes[i] != NULL);
		nodes[i]->data = i;
	}

	head = read_tree_structure(nodes, n);

	free(nodes);
	assert(head != NULL);
	return head;
}
