//双向链表
class MyLinkedList
{
    struct Node
    {
        int val;
        Node *next;
        Node *prev;
        Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    };

private:
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList()
    {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index)
    {
        if ((index >= size) || (index < 0))
        {
            return -1;
        }
        
        Node *pNode = head;
        for (int i = 0; i <= index; i++)
        {
            pNode = pNode->next;
        }
        return pNode->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        ++size;
        return;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        ++size;
        return;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        
        Node *newNode = new Node(val);
        Node *pNode = head;
        for (int i = 0; i < index; i++)
        {
            pNode = pNode->next;
        }
        newNode->next = pNode->next;
        newNode->prev = pNode;
        pNode->next->prev = newNode;
        pNode->next = newNode;
        ++size;
        return;
    }

    void deleteAtIndex(int index)
    {
        if ((index >= size) || (index < 0))
        {
            return;
        }
        
        Node *deleteNode = nullptr;
        Node *pNode = head;
        for (int i = 0; i < index; i++)
        {
            pNode = pNode->next;
        }
        deleteNode = pNode->next;
        pNode->next = deleteNode->next;
        deleteNode->next->prev = pNode;
        delete deleteNode;
        --size;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */