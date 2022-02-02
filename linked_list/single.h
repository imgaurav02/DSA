class SingleLinkedList
{
    Node *start;
    bool isEmpty() const;

    public :
    SingleLinkedList();
    void displayList() const;
    int countNodes() const;
    int find(int data) const;
    void insertAtbeginning(int data );
    void insertAtend(int data)  ;
    void createList();
};