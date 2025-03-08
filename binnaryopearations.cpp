#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int value){
        data=value;
        left=right=nullptr;

    };
};

node* insertion(node* root,int value){
    if(root==nullptr){
        return new node(value);
    }
    else{
        if(value<root->data){
            root->left = insertion(root->left,value);
        }
        else if(value>root->data){
            root->right = insertion(root->right,value);
        }
    }
    return root;
}

void preorder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void inorder(node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


node* deletenode(node* root, int value){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data>value){
        root->left = deletenode(root->left,value);
    }
    else if(root->data<value){
        root->right = deletenode(root->right,value);
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left==nullptr){
            node* temp = root->right;
            delete root;
            root->data=temp->data;
        }
        else if(root->right==nullptr){
            node* temp = root->right;
            delete root;
            root->data=temp->data;
        }

        node* temp = root->right;
        while(temp && temp->left!=nullptr){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right= deletenode(root->right,temp->data);
    }

    return root;

}

int main(){
    node* root=nullptr;

    while(true){
        cout<<endl;
        cout<<"Here is the operations are."<<endl;
        cout<<"create a tree-> type 1."<<endl;
        cout<<"Delete a node-> type 2."<<endl;
        cout<<"Show the preorder-> type 3."<<endl;
        cout<<"Show the postorder-> type 4"<<endl;
        cout<<"Show the inorder-> type 5."<<endl;
        cout<<"End-> 6."<<endl;
        cout<<endl;
        cout<<"Enter your option: ";
        int operation;
        cin>>operation;

        if(operation==1){
            cout<<"How many values you want to insert? ";
            int count;
            cin>>count;
            cout<<"Insert the values:"<<endl;
            int i=0;
           
            while(i<count){
                int key;
                cin>>key;
                root=insertion(root,key);
                i++;
            }
        }

        else if(operation==2){
            cout<<"Enter the value which you want to delete: ";
            int delnum;
            cin>>delnum;
            
            root = deletenode(root,delnum);
        }

        else if(operation==3){
            cout<<"Here is your output: ";
            
            preorder(root);
        }

        else if(operation==4){
            cout<<"Here is your output: ";
            
            postorder(root);
        }

        else if(operation==5){
            cout<<"Here is your output: ";
            
            inorder(root);
        }
        else if(operation==6){
            break;
        }

        else{
            cout<<"Invalid operation.";
        }

        cout<<endl;


    }

    


    
    

}