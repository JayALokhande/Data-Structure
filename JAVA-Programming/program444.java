class node
{
    public int data;
    public node next;
}

class program444
{
    public static void main(String A[])
    {
        node newn = null;

        newn = new node();

        newn.data = 11;
        newn.next = null;

        System.err.println(newn.data);
        System.err.println(newn.next);

    }
}