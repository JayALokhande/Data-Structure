class node 
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        if(first == null)
        {
            System.out.println("Linked List is empty");
            return;
        }

        node temp = null;

        temp = first;
        System.out.print("<=>");
        do
        {
            System.out.print("| " + temp.data + " |<=>");
            temp = temp.next;
        }while(temp != first);
        System.out.println("");
    }
    public int Count()
    {
        return iCount;
    }
    public void InsertFirst(int iNo)
    {
        node newn = new node (iNo);
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        last.next = first;
        first.prev = last;
        iCount ++;
    }
    public void InsertLast(int iNo)
    {
        node newn = new node (iNo);

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.prev = last;
            last.next = newn;
            last = newn;
        }
        last.next = first;
        first.prev = last;
        iCount++;
    }
    public void InsertAtPos(int iNo,int iPos)
    {
        node temp = null;
        int i = 0;

        if((iPos < 1 ) || (iPos > iCount +1))
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if (iPos == iCount+1)
        {
            InsertLast(iNo);
        }
        else
        {
            node newn = new node(iNo);

            temp = first;
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }
    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }
        iCount--;
    }
    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }
        iCount--;
        
    }
    public void DeleteAtPos(int iPos)
    {
        node temp = null;
        int i = 0;

        if((iPos < 1 ) || (iPos > iCount ))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if (iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;
            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
            iCount--;
        }
    }

}

class program460
{
    public static void main(String A[]) 
    {
        int iRet = 0;
        DoublyCL dobj = new DoublyCL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Node Are : "+iRet);

        dobj.DeleteFirst();

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Node Are : "+iRet);

        dobj.DeleteLast();

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Node Are : "+iRet);

        dobj.InsertAtPos(105,4);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Node Are : "+iRet);

        dobj.DeleteAtPos(4);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println("Number of Node Are : "+iRet);
    }
}


/*
|--------------------------------------------------------------------------------|
|Language                   C        C++         JAVA        PYTHON      TYPEDEF |
|--------------------------------------------------------------------------------|
|Singly LL                 DONE       DONE        DONE        --          DONE   |
|--------------------------------------------------------------------------------|
|Singly CL                 DONE       DONE        DONE        --          DONE   |
|--------------------------------------------------------------------------------|
|Doubly LL                 DONE       DONE        DONE        --          DONE   |
|--------------------------------------------------------------------------------|
|Doubly CL                 DONE       DONE        DONE        --          DONE   |
|--------------------------------------------------------------------------------|






*/