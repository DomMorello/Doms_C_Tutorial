#include <stdio.h>
#include <stdlib.h>

/*** 
 2���� ������ ����Ž��Ʈ�� Ž�� �˰���
 ***/

typedef struct TreeNode
{
    int key;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

/* circular version */
TreeNode *search1(TreeNode *node, int key)
{
    //ã���� �ϴ� ���� ã�ƺôµ� �ƿ� ������ ���
    //Ȥ�� ���ʿ� node ��ü�� NULL�̾��� ���
    if(!node)
        return NULL;
    
    //��ȯ���� Ž�� �� ���ϴ� ���� ã���� ��
    if(key == node->key)
        return node;    //�ش� ����� �ּҸ� ��ȯ

    //ã�� ������ ��ƮŰ���� ���� ���
    else if(key > node->key)
        search1(node->right, key);  //������ ����Ʈ���� �̵�
    
    //ã�� ������ ��ƮŰ���� ū ���
    else
        search1(node->left, key);   //���� ����Ʈ���� �̵�
}

/* repeating version */
TreeNode *search2(TreeNode *node, int key)
{
    /* ã���� �ϴ� ���� ã�ƺôµ� �ƿ� ������ ���
    Ȥ�� ���ʿ� node��ü�� NULL�̾��� ��� while�� Ż�� */
    
    while(node) //node�� NULL�� �ƴ϶�� �ϴ� Ž���� ����Ѵ�.
    {
        if(key == node->key)
            return node;
        //ã���� �ϴ� ������ ��ƮŰ���� �� ū ���
        else if(key < node->key)
            node = node->left;   //�� �� ����Ʈ���� �̵�
        //ã���� �ϴ� ������ ��ƮŰ���� �� ���� ���
        else
            node = node->right; //������ ����Ʈ���� �̵�
    }
    return NULL;
}

/*** 
 ����Ž��Ʈ�� ���� �˰���
 ***/

typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//key�� ����Ž��Ʈ�� root�� �����Ѵ�.
//key�� �̹� root�ȿ� ������ �������� �ʴ´�.
void insert_node(TreeNode **root, int key)
{
    //t�� Ž���� ���� �������̴�.
    TreeNode *parent;   //�θ��带 ����Ű�� ������
    TreeNode *current;    //���� ��� ������
    TreeNode *new;  //���ο� ��Ʈ ������

    current = *root;    //ó�� ���۽� ���� ���� root �� ��ü
    parent = NULL;  //root�� �θ���� ����. 

    //Ž���� ���� ����
    while(current)
    {
        if(key == current->key)
            return;

        parent = current;   //�θ� ��带 ���� ���� �����Ѵ�. ���ο� ��Ʈ���
        //����Ʈ���� ���ο� ��Ʈ��尡 �����ϴ� �Ͱ� ���� ����

        if(key < parent->key)
            current = parent->left; //���� ���� �θ��� �� �� ����Ʈ���� �ȴ�.
        else
            current = parent->right;    //���� ���� �θ�� ������ ����Ʈ���� �ȴ�.
    }
    //key�� Ʈ�� �ȿ� �����Ƿ� ������ �����ϴ�.

    //���� ���Ե� ��带 �����Ѵ�.
    new = (TreeNode*)malloc(sizeof(TreeNode));
    if(!new)
        return; //�����Ҵ� �������� ��� return
    
    //�����͸� �����Ѵ�.
    if(parent)  //�θ��尡 ������ ���
    {
        if(key < parent->key)
            parent->left = new;
        else
            parent->right = new;
    }
    else    //�θ� ��尡 ������ ���� ���� ��尡 ��Ʈ��尡 �ȴ�.
        *root = new;
}

/*** 
 ����Ž��Ʈ�� ���� �˰���
 ***/

void delete_node(TreeNode **root, int key)
{
	TreeNode *parent, *child, *suc, *suc_p, *t;

	// key�� ���� ��� t�� Ž���Ѵ�. parent�� t�� �θ����.
	parent = NULL; // ���ʰ� �Ǵ� root�� �θ�� ����.
	t = *root;

	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL && t->key != key)
	{
		parent = t; // �θ� t���� �����ϰ� �� �� t�� ���� Ž���Ѵ�.
					// t�� �����̳� key���� ���� �����̳� ���������� ��������.
		t = (key < parent->key) ? parent->left : parent->right;
	}

	// Ž���� ���� �������� ���� Ű ���� Ʈ���� �����ٸ� t�� NULL�� ���̴�.
	if (!t)
	{
		printf("key is not in the tree");
		return; // ���ϴ� ���� �����Ƿ� return �Ѵ�.
	}
	// ������ Ž���� ������ ��츦 �ٷ�� ������ �� �Ʒ����ʹ� Ž����
	// ���������� �̷�����ٴ� ���� �Ͽ� ����� ���� ������.

	// ù ��°: �ܸ���忴�� ���
	if (t->left == NULL && t->right == NULL)
	{
		if (parent) // �θ� ��尡 NULL�� �ƴ� ��, �� ������ ��
		{
			if (parent->left == t)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else // �θ� ��尡 NULL �̶��, �����Ϸ��� ��尡 ��Ʈ ����.
			*root = NULL;
	}
	// �� ��°: �ϳ��� ����Ʈ���� ������ ���
	else if ((t->left == NULL) || (t->right == NULL))
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (parent)
		{
			if (parent->left == t)
				parent->left = child;
			else
				parent->right = child;
		}
		else // �θ� ��尡 NULL�̶�� �����Ǵ� ��尡 ��Ʈ����.
			*root = child;
	}
	// �� ��°: �ΰ��� ����Ʈ���� ��� ������ ���
	else
	{
		// ������ ����Ʈ������ ���� ���� ���� ã�´�.
		suc_p = t;
		suc = t->right;
		while (suc->left != NULL)
		{
			suc_p = suc;
			suc = suc->left;
		}
		// �ļ����� �θ�� �ڽ��� ����
		if (suc_p->left == suc)
			suc_p->left = suc->right;
		// ���� ������ ���������� �� ���� ������ ����Ʈ���� ���� ���� �ִµ�,
		// �� ��츦 ����� suc->right ���� �����ϴ� ���̴�.
		// �׸��� �׷� ���� ���ϴ�. �����ÿ� �׸��� ÷���ϰڴ�.

		else
			suc_p->right = suc->right;

		// �Ʒ� �� ���� ������ �����ϴ� ������ �����ϱ�?
		// �����ÿ� �ڼ��� Ǯ�� �����غ��Ҵ�.
		t->key = suc->key;
		t = suc;
	}
	free(t);
}