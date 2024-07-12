#include <iostream>
using namespace std;

class node
{
	int data;
	node *left;
	node *right;
	friend class bintree;
	friend class stack;
};
class stack
{
	node *st[20];
	int top;
	friend class bintree;
	public:
		stack()
		{
			top = -1;
		}
		void push(node *);
		node* pop();
		int empty(); 
		
};
void stack :: push(node *temp)
{
	top++;
	st[top] = temp;
}
node* stack :: pop()
{
	node *t;
	t = st[top];
	top--;
	return (t);
}
int stack :: empty()
{
	if(top == -1)
		return 0;
	else
		return 1;
}
class bintree
{
	node *root;
	public:
		void binary_tree_create();
		void create_r(node *root);		
		void recursive_create();
		void rec_create(node *root);
		void preorder(node *root);
		void inorder(node *root);
		void postorder(node *root);
		void preorder();
		void inorder();
		void postorder();
		void inorder_nonrec(node *root);
		void preorder_nonrec(node *root);
		void postorder_nonrec(node *root);
		void inorder_nonrec();
		void preorder_nonrec();
		void postorder_nonrec();
};
void bintree :: binary_tree_create()
{
	root = new node();
	cout<<"Enter the data for Root node \n";
	cin>>root->data;
	cout<<endl;
	root->left = root->right = NULL;
	create_r(root);
}
void bintree :: recursive_create()
{
	root = new node();
	cout<<"Enter root data\n";
	cin>>root->data;
	cout<<endl;
	root->left = root->right = NULL;
	rec_create(root);
}
void bintree :: rec_create(node *root)
{
	node *ptr;
	char c;
	cout<<"Do you want to attach node on Left? Yes(Y) or No(N)\n";
	cin>>c;
	cout<<endl;
	if(c == 'Y')
	{
		ptr = new node();
		cout<<"Enter data of node\n";
		cin>>ptr->data;
		ptr->left = ptr->right = NULL;
		root->left = ptr;
		rec_create(ptr);
	}
	cout<<"Do you want to attach node on Right? Yes(Y) or No(N)\n";
	cin>>c;
	cout<<endl;
	if(c == 'Y')
	{
		ptr = new node();
		cout<<"Enter data of node\n";
		cin>>ptr->data;
		ptr->left = ptr->right = NULL;
		root->right = ptr;
		rec_create(ptr);
	}
}
void bintree :: create_r(node *root)
{
	char choice;
	do
	{
		int flag=0;
		char ch;
		node *temp = root;
		node *curr = new node();
		cout<<"Enter the  data\n";
		cin>> curr->data;
		cout<<endl;
		curr->left = curr->right = NULL;
		while(flag == 0)
		{
			cout<<"Where do you want to enter the data: Right(R) or Left(L)"<<" "<<temp->data<<"\n";
			cin>>ch;
			cout<<endl;
			if(ch == 'L')
			{
				if(temp->left == NULL)
				{
					temp->left=curr;
					flag = 1;
				}
				else
				{
					temp=temp->left;
					flag=0;
				}
			}
			if(ch == 'R')
			{
				if(temp->right == NULL)
				{
					temp->right=curr;
					flag = 1;
				}
				else
				{
					temp=temp->right;
					flag=0;
				}
			}
		}
		cout<<"Do you want to add data to the tree? : Yes(Y) or No(N)\n";
		cin>>choice;
	}while(choice == 'Y');
}
void bintree :: preorder(node *root)
{
	if (root != NULL)
	{
		cout<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void bintree :: preorder()
{
	preorder(root);
}
void bintree :: inorder(node *root)
{
	if (root != NULL)
		{
			inorder(root->left);
			cout<<root->data;
			inorder(root->right);
		}
}
void bintree :: inorder()
{
	inorder(root);
}
void bintree :: postorder(node *root)
{
	if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout<<root->data;
		}
}
void bintree :: postorder()
{
	postorder(root);
}
void bintree :: inorder_nonrec(node *root)
{
	stack s;	
	node *temp = root;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp = temp->left;	
		}
		if(s.empty() == 0)
		{
			break;
		}
		temp = s.pop();
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}
void bintree :: inorder_nonrec()
{
	inorder_nonrec(root);
}




//anshuman joshi


void bintree :: preorder_nonrec(node *root)
{
	stack s;	
	node *temp = root;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";			
			s.push(temp);
			temp = temp->left;	
		}
		if(s.empty() == 0)
		{
			break;
		}
		temp = s.pop();
		temp=temp->right;
	}
}
void bintree :: preorder_nonrec()
{
	preorder_nonrec(root);
}
void bintree :: postorder_nonrec(node *root)
{
	stack s;	
	node *temp = root;
	while(1)
	{
		while(temp!=NULL)
		{			
			s.push(temp);
			temp = temp->left;	
		}
		if(s.empty() == 0)
		{
			break;
		}
		if(s.st[s.top]->right == NULL)
		{
			temp = s.pop();			
			cout<<temp->data<<" ";
		}
		while(s.st[s.top]->right == temp)
		{
			temp = s.pop();
			cout<<temp->data<<" ";
		}
		temp = s.st[s.top]->right;
	}
}
void bintree :: postorder_nonrec()
{
	postorder_nonrec(root);
}
int main()
{
	bintree b1;
	cout<<"Non-Recursive Creation of Binary Tree \n";
	b1.binary_tree_create();
	cout<<endl;
	cout<<"Recursive Creation of Binary Tree \n";	
	b1.recursive_create();
	cout<<endl;
	cout<<"Preorder Traversal of Binary Tree\n";
	b1.preorder();
	cout<<endl;
	cout<<"Non-Recursive Preorder Traversal of Binary Tree\n";
	b1.preorder_nonrec();
	cout<<endl;
	cout<<"Inorder Traversal of Binary Tree\n";
	b1.inorder();
	cout<<endl;
	cout<<"Non-Recursive Inorder Traversal of Binary Tree\n";
	b1.inorder_nonrec();
	cout<<endl;
	cout<<"Postorder Traversal of Binary Tree\n";
	b1.postorder();
	cout<<endl;
	cout<<"Non-Recursive Postorder Traversal of Binary Tree\n";
	b1.postorder_nonrec();
	cout<<endl;
}
