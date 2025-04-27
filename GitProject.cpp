#include<iostream>
#include<string>
using namespace std;
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
        Contact(){
            left=right=NULL;
        }
};
Contact* insert(Contact* root,string name,string number,string address,string email){
    if(root==NULL){
        return new Contact(name,number,address,email);
    }
    if(name<root->name){
        root->left=insert(root->left,name,number,address,email);
    }
    else if(name>root->name){
        root->right=insert(root->right,name,number,address,email);
    }
}
Contact* search(Contact* root,string name){
    if(root==NULL){
        return NULL;
    }
    if(name==root->name){
        return root;
    }
    if(name<root->name){
        return search(root->left,name);
    }
    else{
        return search(root->right,name);
    }
}
void display(Contact* root){
    if(root==NULL){
        return ;
    }
    cout<<"name:"<<root->name<<endl;
    cout<<"number:"<<root->number<<endl;
    cout<<"email:"<<root->email<<endl;
    cout<<"address:"<<root->address<<endl;
}
int main(){
    Contact* root=NULL;
    root=insert(root,"Mahesh","8701342678","Himayath Nagar","mahesh@gmail.com");
    root=insert(root,"Tarak","8379257836","Uppal","tarak@gmail.com");
    root=insert(root,"Arjun","8674569874","Kukatpally","arjun@gmail.com");
    root=insert(root,"prabhas","8764589864","prabhas@gmail.com","Secundrabad");
    string searchC;
    display(root);
    cout<<"enter the contact to be searched:\n";
    cin>>searchC;
    Contact* find=search(root,searchC);
    if(find==NULL){
        cout<<"the contact not found\n";
    }
    else{
        cout<<"the contact found details are:\n";
        display(find);
    }
    

}