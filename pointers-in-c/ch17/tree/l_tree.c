// 2020-12-23 created by Akson
// Code17.9 l_tree.c 链式二叉搜索树

// 一个使用动态分配的链式结构实现的二叉搜索树

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

// TreeNode结构包含了之和两个指向某个树节点的指针
typedef struct TREE_NODE
{
	TREE_TYPE value;
	struct TREE_NODE* left;
	struct TREE_NODE* right;
} TreeNode;

// 指向根节点的指针
static TreeNode* tree;

// insert
void insert(TREE_TYPE value)
{
	TreeNode* current;
	TreeNode** link;

	// 从根节点开始
	link = &tree;

	// 持续查找值，进入合适的子树。
	while((current = *link) != NULL)
	{
		// 根据情况，进入左子树还是右子树（确认没有重复出现的值）
		if(value < current -> value)
		{
			link = &current -> left;
		}
		else
		{
			assert(value != current -> value);
			link = &current -> right;
		}
	}

	// 分配一个新节点，使适当节点的link字段指向它。
	current = (TreeNode*)malloc(sizeof(TreeNode));
	assert(current != NULL);
	current -> value = value;
	current -> left = NULL;
	current -> right = NULL;
	*link = current;
}

// find
TREE_TYPE* find(TREE_TYPE value)
{
	TreeNode* current;

	// 从根节点开始，知道找到这个值，进入合适的子树。
	current = tree;

	while(current != NULL && current -> value != value)
	{
		// 根据情况，进入左子树还是右子树
		if(value < current -> value)
		{
			current = current -> left;
		}
		else
		{
			current = current -> right;
		}
	}

	if(current != NULL)
	{
		return &current -> value;
	}

	return NULL;
}

// 执行一层前序遍历。这个帮主函数用于保存我们当前正在处理的节点的信息。这个函数并不是用户接口的一部分。
static void do_pre_order_traverse(TreeNode* current, void (*callback)(TREE_TYPE value))
{
	if(current != NULL)
	{
		callback(current -> value);
		do_pre_order_traverse(current -> left, callback);
		do_pre_order_traverse(current -> right, callback);
	}
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
	do_pre_order_traverse(tree, callback);
}


// pe17.7
int findMax(struct TREE_NODE* root)
{
    int max = root -> value;
    if(root -> left != NULL)
    {
        int left_max = findMax(root -> left);
        if(max < left_max)
        {
            max = left_max;
        }
    }
    
    if(root -> right != NULL)
    {
        int right_max = findMax(root -> right);
        if(max < right_max)
        {
            max = right_max;
        }
    }
    
    return max;
}

// pe17.7
int findMin(struct TREE_NODE* root)
{
    int min = root -> value;
    if(root -> left != NULL)
    {
        int left_min = findMin(root -> left);
        if(min > left_min)
        {
            min = left_min;
        }
    }
    
    if(root -> right != NULL)
    {
        int right_min = findMin(root -> right);
        if(min > right_min)
        {
            min = right_min;
        }
    }
    
    return min;
}

// pe17.7
int isValidBST(){
    if(tree == NULL)
    {
        return 1;
    }
    
    if(tree -> left != NULL)
    {
        if(tree -> value == tree -> left -> value)
        {
            return 0;
        }
        
        if(!isValidBST(tree -> left))
        {
            return 0;
        }
        
        if(tree -> value <= findMax(tree -> left))
        {
            return 0;
        }
    }
    
    if(tree -> right != NULL)
    {
        if(tree -> value >= tree -> right -> value)
        {
            return 0;
        }
        
        if(!isValidBST(tree -> right))
        {
            return 0;
        }
        
        if(tree -> value >= findMin(tree -> right))
        {
            return 0;
        }
    }
    
    return 1;
}

// pe17.9
void destroy_tree(struct TREE_NODE* pnode)
{
	if(pnode != NULL)
	{
		destroy_tree(pnode -> left);
		destroy_tree(pnode -> right);
		
		free(pnode);
	}
}

// pe17.10
void delete_node(TREE_TYPE value)
{
	struct TREE_NODE* parent = NULL;
	struct TREE_NODE* current = tree;

	int left_flag = 0;

	while(current != NULL && current -> value != value)
	{
		if(current -> value < value)
		{
			left_flag = 0;
			parent = current;
			current = current -> right;
			continue;
		}

		left_flag = 1;
		parent = current;
		current = current -> left;
		continue;
	}

	assert(current != NULL);

	if(current -> left == NULL)
	{
		if(current -> right == NULL)
		{
			free(current);
			return;
		}
		else
		{
			if(parent == NULL)
			{
				tree = current -> right;
				return;
			}
			else
			{
				if(left_flag == 1)
				{
					parent -> left = current -> right;
				}
				else
				{
					parent -> right = current -> right;
				}

				free(current);

				return;
			}	
		}
	}
	else
	{
		if(current -> right == NULL)
		{
			if(parent == NULL)
			{
				tree = current -> right;
				return;
			}
			else
			{
				if(left_flag == 1)
				{
					parent -> left = current -> right;
				}
				else
				{
					parent -> right = current -> right;
				}

				free(current);

				return;
			}	
		}
		else
		{
			TreeNode* max = current -> left;
			while(max -> right != NULL)
			{
				max = max -> right;
			}

			current -> value = max -> value;
			max -> value = -1;

			delete_node(max -> value);

			return;
		}
	}
	

}

