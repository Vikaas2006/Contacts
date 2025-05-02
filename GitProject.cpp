#include<iostream>
#include<string>
using namespace std;
class ContactLog;
class Contact{
    public:
        string number;
        string name;
        string address;
        string email;
        Contact* left;
        Contact* right;
        Contact(string name,string number,string address,string email){
            this->name=name;
            this->number=number;
            this->address=address;
            this->email=email;
            left=NULL;
            right=NULL;
        }
        friend class ContactLog;   
        Contact(){
            left=right=NULL;
        }
        void display(){
            cout<<" Name:  "<<name<<"\n";
            cout<<"number: "<<number<<"\n";
            cout<<"email "<<email<<"\n";
            cout<<"address "<<address<<"\n";
        }
};

class ContactLog{
    public:
        Contact* root;
        Contact* insert(Contact* root,string name,string number,string address,string email);
        void addContact();
        ContactLog(){
            root=NULL;
        }
        void inorder(Contact* node);
        Contact* deleteNode(Contact* node,const string& name);
        void search();
        void viewContacts();
        void display();
        Contact* searchContact(Contact* root,string name);
        void deleteContact();

};
void ContactLog::deleteContact(){
    string name;
    cout<<"enter the name to delete:\n";
    cin>>name;
    if(searchContact(root,name)==NULL){
        cout<<"Contact not found\n";
        return;
    }
    root=deleteNode(root,name);
    cout<<"contact deleted\n";
}
void ContactLog::viewContacts(){
    if(root==NULL){
        cout<<"no contacts availabel\n";
        return;
    }
    cout<<"all contacts\n";
    inorder(root);
}
void ContactLog::search(){
    string name;
    cout<<"enter name to search:\n";
    cin>>name;
    Contact* result=searchContact(root,name);
    if(result==NULL){
        cout<<"no contact found with that name\n";
    }
    else{
        cout<<"Contact found:\n";
        result->display();
    }
}

void ContactLog::inorder(Contact* node){
    if(node==NULL){
        return;
    }
    inorder(node->left);
    node->display();
    inorder(node->right);
}
Contact* ContactLog::deleteNode(Contact* node,const string& name){
    if(node==NULL){
        return NULL;
    }
    if(name<node->name){
        node->left=deleteNode(node->left,name);
    }
    else if(name> node->name){
        node->right=deleteNode(node->right,name);
    }
    else{
        if(node->left==NULL && node->right==NULL){
            delete node;
            return NULL;
        }
        else if(node->left==NULL){
            Contact* temp=node->right;
            delete node;
            return temp;
        }
        else if(node->right==NULL){
            Contact* temp=node->left;
            delete node;
            return temp;
        }
        else{
            Contact* successor=node->right;
            while(successor->left){
                successor=successor->left;
            }
            node->name=successor->name;
            node->number=successor->number;
            node->address=successor->address;
            node->email=successor->email;
            node->right=deleteNode(node->right,successor->name);

        }
    }
    return node;
}
void ContactLog::addContact(){
    string name,number,address,email;
    cout<<"enter name:";
    cin>>name;
    cout<<"\n";
    cout<<"enter phone:";
    cin>>number;
    cout<<"\n";
    cout<<"enter email:";
    cin>>email;
    cout<<"\n";
    cout<<"enter address:";
    cin>>address;
    cout<<"\n";
    root=insert(root,name,number,address,email);
    cout<<"contact added successfully\n";
}

Contact* ContactLog::insert(Contact* root,string name,string number,string address,string email){
    if(root==NULL){
        return new Contact(name,number,address,email);
    }
    if(name<root->name){
        root->left=insert(root->left,name,number,address,email);
    }
    else if(name>root->name){
        root->right=insert(root->right,name,number,address,email);
    }
    return root;
}

Contact* ContactLog::searchContact(Contact* root,string name){
    if(root==NULL){
        return NULL;
    }
    if(name==root->name){
        return root;
    }
    if(name<root->name){
        return searchContact(root->left,name);
    }
    else{
        return searchContact(root->right,name);
    }
}

int main(){
    ContactLog log;
    int choice;
    do{
        cout<<"menu for contacts : \n";
        cout<<"1 Add Contact\n";
        cout<<"2.View Contact\n";
        cout<<"3.Search Contact\n";
        cout<<"4.Delete Contact\n";
        cout<<"5.Exit\n";
        cin>>choice;
        switch (choice){
            case 1:
            log.addContact();
            break;
            case 2:
            log.viewContacts();
            break;
            case 3:
            log.search();
            break;
            case 4:
            log.deleteContact();
            break;
            case 5:
            cout<<"exiting\n";
            break;
            default:
            cout<<"invalid choice\n";
        }
}while (choice!=5);

}
