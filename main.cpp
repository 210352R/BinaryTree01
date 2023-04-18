#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

/*void insert(int data){
    struct Node* new_node =(struct Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL){
        root = new_node;
    }else{

        struct Node* temp = root;
        struct Node* y;
        while( temp != NULL){
            y = temp;
            if(data<= temp->data){
                temp = temp->left;

            }else{
                temp = temp->right;
            }
        }
        if(data <= y->data){
            y->left = new_node;
        }else{
            y->right = new_node;
        }
    }
}*/
struct Node* insert2(struct Node* node,struct Node* new_node);
struct Node* FindMin(struct Node* node);

struct Node* insert(int data){
    struct Node* new_node =(struct Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    root = insert2(root,new_node);

};


struct Node* insert2(struct Node* node,struct Node* new_node){

    if (node == NULL){
        node = new_node;
        return node;
    }else{
        if(new_node->data<= node->data){
            node->left = insert2(node->left,new_node);
            return node;
        }else{
            node->right = insert2(node->right,new_node);
            return node;
        }
    }
}


// DELETE A NODE IN BST ----
struct Node* Delete(struct Node *node, int data) {
	if(root == NULL) {
        return node;
	}
	else if(data < node->data){
        node->left = Delete(node->left,data);
	}
	else if (data > node->data) {
        node->right = Delete(node->right,data);
	}
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if(node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
		}
		//Case 2: One child
		else if(node->left == NULL) {
			struct Node *temp = node;
			node = node->right;
			delete temp;
		}
		else if(node->right == NULL) {
			struct Node *temp = node;
			node = node->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct Node *temp = FindMin(node->right);
			node->data = temp->data;
			node->right = Delete(node->right,temp->data);
		}
	}
	return node;
}



struct Node* FindMin(struct Node* node){
    struct Node* minNode = node;
    struct Node* temp = node;

    while(temp!= NULL){
        if(minNode->data > temp->data){
            minNode = temp;
        }
        temp = temp->left;
    }

    return minNode;

}


void inOrder(struct Node* node){
    if(node==NULL){
        return;
    }
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

 void preOrder(struct Node* node){
     if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
 }


 void postOrder(struct Node* node){
     if(node==NULL){
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
 }





int main()
{
    insert(10);
    insert(5);
    insert(25);
    insert(4);
    insert(7);
    insert(18);
    insert(27);
    //cout<<FindMin(root)->data<<endl;

    inOrder(root);
    cout<<endl;

    preOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;




    cout<< "Deletions -----"<<endl;
    cout<<"Delete-25"<<endl;

    Delete(root,25);

    inOrder(root);
    cout<<endl;

    preOrder(root);
    cout<<endl;

    postOrder(root);
    cout<<endl;

    return 0;
}
