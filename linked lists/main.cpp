#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
    node()
    {
        next=NULL;
    }
};

node *root=NULL,*temp,*tail,*current;

void append(int val)
{
    if(root==NULL)
    {
        root= new node();
        root->val=val;
        tail=root;
    }
    else
    {
        current=root;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        temp=new node();
        temp->val=val;
        tail=temp;
        current->next=temp;
    }
}

void append1(int val)
{
    if(root==NULL)
    {
        root=new node();
        root->val=val;
        tail=root;
    }
    else
    {
        tail->next=new node();
        tail->next->val=val;
        tail=tail->next;
    }
}

void delete_node(int val)
{
    current=root;
    node *prev=NULL;
    while(current)
    {
        if(current->val==val)
        {
            if(current==root)
            {
                root=current->next;
                delete(current);
                break;
            }
            prev->next=current->next;
            delete(current);
            break;
        }
        prev=current;
        current=current->next;
    }
}

void print()
{
    current = root;
    int i=0;
    while(current!=NULL)
    {
        printf("%d ",current->val);
        current=current->next;

        i++;
        if(i==15)
            break;
    }
    cout<<endl;
}

void make_cycle(int n)
{
    int i=1;
    current = root;
    while(i<n)
    {
        if(current==NULL)
        {
            cout<<"Not a valid index\n";
            break;
        }
        current=current->next;
        i++;
    }
    tail->next=current;
    tail=current;
}

node* find_cycle()
{
    node *hare=root,*tort=root;
    while(hare)  ///******** EDIT
    {
        if(hare->next && hare->next->next)
            hare=hare->next->next;
        else
            return NULL;
        tort=tort->next;
        if(hare==tort)
            break;
    }
    node *tort1=root;
    while(tort1!=tort)
    {
        tort1=tort1->next;
        tort=tort->next;
    }
    return tort;
}

int main()
{
    int i,j,k;
    cout<<"1: append(val)\n2: print()\n3: make_cycle(index)\n4: find_cycle()\n5: delete(val)\n\n";
    while(1)
    {
        cin>>k;
        if(k==0)
            break;
        if(k==1)
        {
            cin>>j;
            append1(j);
        }
        if(k==2 )
            print();
        if(k==3)
        {
            cin>>j;
            make_cycle(j);
        }
        if(k==4)
        {
            temp = find_cycle();
            if(temp==NULL)
                cout<<"No Cycle Exists!\n";
            else
                cout<<"Exists at point : "<<temp->val<<endl;
        }
        if(k==5)
        {
            cin>>j;
            delete_node(j);
        }
    }
    return 0;
}
/*
1 1
1 2
1 3
1 4
1 5
2
3 3
2
4
*/
