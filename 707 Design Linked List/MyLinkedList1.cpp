//单向链表
class MyLinkedList
{
    struct Node
    {
        int val;
        Node *next;
        Node(int val) : val(val), next(nullptr) {}
    };

private:
    Node *head;
    int size;

public:
    MyLinkedList()
    {
        head = new Node(-1);
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
        head->next = newNode;
        ++size;
        return;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *pNode = head;
        while (pNode->next != nullptr)
        {
            pNode = pNode->next;
        }
        pNode->next = newNode;
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