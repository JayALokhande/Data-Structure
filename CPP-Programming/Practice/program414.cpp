#include <iostream>
using namespace std;

#pragma pack(1)
struct node 
{
    int data ;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    private:
        PNODE first ;
        int iCount ;
    public :
        SinglyLL ();

        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

SinglyLL::SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

void SinglyLL :: Display()
{
    PNODE temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp ->next;
    }
    cout<<"NULL"<<endl;
}

int SinglyLL :: Count()
{
    return this->iCount;
}

void SinglyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn ->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->iCount++;                   //IMPORTANT
}
void SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn ->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while (temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;                   //IMPORTANT
}
void SinglyLL:: InsertAtPos(int iNo, int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Postion\n";
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if (iPos == iCount+1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;

        temp = this->first;
        for(i = 1; i < iPos-1; i++ )
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}
void SinglyLL:: DeleteFirst()
{
    PNODE temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = first->next;
        delete temp;  
    }
    this->iCount--;
}
void SinglyLL:: DeleteLast()
{
    PNODE temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}
void SinglyLL:: DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Postion\n";
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if (iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(i = 1; i < iPos-1; i++ )
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

int main()
{
    SinglyLL sobj;
    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;
    int iPostion = 0;

    while (iChoice != 9)               //Unconditional LOOP   run until use break() key word
    {
        cout<<"--------------------------------------\n";
        cout<<"Enter Your Choice : \n";
        cout<<"--------------------------------------\n";

        cout<<"1 : Insert Node At First Position\n";
        cout<<"2 : Insert Node At Last Position\n";
        cout<<"3 : Insert Node At Given Position\n";
        cout<<"4 : Delete Node At First Position\n";
        cout<<"5 : Delete Node At Last Position\n";
        cout<<"6 : Delete Node At Given Position\n";
        cout<<"7 : Display the Elements\n";
        cout<<"8 : Count the NUmber of Elements\n";
        cout<<"9 : Insert Node At Given Position\n";
        cout<<"--------------------------------------\n";

        cin>>iChoice;

        switch (iChoice)
        {
        case 1 : 
            cout<<"Enter the Value : \n";
            cin>>iValue;
            sobj.InsertFirst(iValue);
            break;

        case 2 :
            cout<<"Enter the Value : \n";
            cin>>iValue;
            sobj.InsertLast(iValue);
            break;

        case 3 :
            cout<<"Enter the Value : \n";
            cout<<"Enter the POsition : \n";
            cin>>iValue;
            cin>>iPostion;
            sobj.InsertAtPos(iValue,iPostion);
            break;
        
        case 4 :
            sobj.DeleteFirst();
            break;

        case 5 :
            sobj.DeleteLast();
            break;

        case 6 :
            cout<<"Enter the POsition : \n";
            cin>>iPostion;
            sobj.DeleteAtPos(iPostion);
            break;

        case 7 :
            cout<<"Elements of The Linked-List are :\n ";
            sobj.Display();
            break;
        
        case 8 :
            iRet=sobj.Count();
            cout<<"Number of Elements are :\n ",iRet;
            break;
        
        case 9 :
            cout<<"Thank You for Using Marvellous Infosystem Application .\n ";
            break;

        default:
            cout<<"Ivalide Choice \n ";
            break;
        }
    }

    return 0;
}

//Menu Driven