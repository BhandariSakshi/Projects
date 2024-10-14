#include <iostream>
# include <stdbool.h>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
private:
    struct nodeSL<T> *First;
    int iCount;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout << "Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to Display the Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the number of nodes in LinkedList.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst
// Discription  : Used to insert node at first position of Linked List.
// Input        : Integer, float, double, character.
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> *newn = NULL;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast
// Discription  : Used to insert node at last position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> *newn = NULL;
    struct nodeSL<T> *temp = First;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos
// Discription  : Used to insert node at the given position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> *newn = NULL;
    int i = 0;
    struct nodeSL<T> *temp;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst
// Discription  : Used to delete node at first position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast
// Discription  : Used to delete node at last position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos
// Discription  : Used to delete node at the given position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1;
    struct nodeSL<T> *temp2;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
private:
    struct nodeDC<T> *First;
    struct nodeDC<T> *Last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display the Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << First->data << "| <=> ";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the number of nodes of Linked List
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst
// Discription  : Used to insert node at first position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast
// Discription  : Used to insert node at last position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos
// Discription  : Used to insert node at the given position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> *temp = NULL;
    struct nodeDC<T> *newn = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst
// Discription  : Used to delete node at frst position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single nodeQ
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one nodeQ
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast
// Discription  : Used to delete node at last position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single nodeQ
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one nodeQ
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos
// Discription  : Used to delete node at the given position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> *temp = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
private:
    struct nodeDL<T> *First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    cout << "Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display the Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> *temp = First;
    cout << "NULL <=> ";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the number of nodes in the LinkedList
// Input        : NULL
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst
// Discription  : Used to insert node at first position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL; // $

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn; // $

        First = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast
// Discription  : Used to insert node at last position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> *temp = NULL;

    newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL; // $

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp; // $
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertAtPos
// Discription  : Used to insert node at the given position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int iLength = 0;
    int i = 0;

    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> *temp = NULL;

    iLength = Count();

    if ((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iLength + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDL<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL; // $

        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn; // $
        temp->next = newn;
        newn->prev = temp; // $
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst
// Discription  : Used to delete node at first position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL) // Case 1
    {
        printf("Unable to delete the node as LL is empty\n");
        return;
    }
    else if (First->next == NULL) // Case 2
    {
        delete (First);
        First = NULL;
    }
    else // Case 3
    {
        First = First->next;
        delete (First->prev); // $
        First->prev = NULL;   // $
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast
// Discription  : Used to delete node at last position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> *temp = NULL;

    if (First == NULL) // Case 1
    {
        printf("Unable to delte the node as LL is empty\n");
        return;
    }
    else if (First->next == NULL) // Case 2
    {
        delete (First);
        First = NULL;
    }
    else // Case 3
    {
        temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos
// Discription  : Used to delete node at the given position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iLength = 0;
    int i = 0;

    struct nodeDL<T> *temp = NULL;

    iLength = Count();

    if ((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
private:
    struct nodeSC<T> *First;
    struct nodeSC<T> *Last;
    int iCount;

public:
    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display the Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "LinkedList is empty\n";
        return;
    }
    cout << "->";

    do
    {
        cout << "| " << First->data << "| ->";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the number of nodes in the Linked List
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst
// Discription  : Used to insert node at first position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertLast
// Discription  : Used to insert node at last position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn = new nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InserAtPos
// Discription  : Used to insert node at the given position of Linked List
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    int iLength = 0;
    struct nodeSC<T> *temp = NULL;
    struct nodeSC<T> *newn = NULL;

    iLength = Count();

    if ((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iLength + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSC<T>;

        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteFirst
// Discription  : Used to delete node at first position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteLast
// Discription  : Used to delete node at last position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct nodeSC<T> *temp = NULL;

    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }

        delete (Last);
        Last = temp;

        Last->next = First;
    }
    iCount--;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeleteAtPos
// Discription  : Used to insert node at the given position of Linked List
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;
    struct nodeSC<T> *temp1 = NULL;
    struct nodeSC<T> *temp2 = NULL;

    iLength = Count();

    if ((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        free(temp2);
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
private:
    struct nodeS<T> *First;
    int iCount;

public:
    Stack();

    void Display();
    int Count();
    void Push(T No); // insertFirst
    int Pop();       // deleteFirst
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display the stack
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are: \n";

    struct nodeS<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the number of nodes in the stack
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Push
// Discription  : Used to insert new element in the stack
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeS<T> *newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Pop
// Discription  : Used to delete an element from the stack
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeS<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "UNable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
private:
    struct nodeQ<T> *First;
    int iCount;

public:
    Queue();

    void Display();
    int Count();
    void EnQueue(T No); // insertLast
    int DeQueue();      // deleteFirst
};
template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to displa element of the queue
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    cout << "Elements of stack are: \n";

    struct nodeQ<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the element in the stack
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: EnQueue
// Discription  : Used to insert element in the queue
// Input        : Integer, float, double, character
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQ<T> *newn = NULL;
    struct nodeQ<T> *temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DeQueue
// Discription  : Used to remove element from the queue
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQ<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "UNable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Tree
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeBST
{
    T data;
    struct nodeBST *lchild;
    struct nodeBST *rchild;
};

template <class T>
class BST
{
private:
    struct nodeBST<T> *Root;

    void inorderTraversal(nodeBST<T> *root);
    void preorderTraversal(nodeBST<T> *root);
    void postorderTraversal(nodeBST<T> *root);
    int countLeafNodes(nodeBST<T> *root);
    int countParentNodes(nodeBST<T> *root);
    int countAllNodes(nodeBST<T> *root);

public:
    BST();

    void Insert(T No);

    void Inorder();
    void Preorder();
    void Postorder();

    bool Search(T No);
    int CountLeaf();
    int CountParent();
    int CountAll();
};

template <class T>
BST<T>::BST()
{
    Root = NULL;
    cout << "Inside Constructor" << endl;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Insert
// Discription  : Used to insert an element in a tree
// Input        : Integer
// Output       : void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>

void BST<T>::Insert(T No)
{
    struct nodeBST<T> *newn = new nodeBST<T>;
    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (Root == NULL)
    {
        Root = newn;
    }
    else
    {
        struct nodeBST<T> *temp = Root;
        while (true)
        {
            if (temp->data == No)
            {
                cout << "Unable to insert node as element is already present\n";
                delete newn;
                break;
            }
            else if (No > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Inorder
// Discription  : Used to perform inorder traversal
// Input        : Null
// Output       : void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Inorder()
{
    inorderTraversal(Root);
}

template <class T>
void BST<T>::inorderTraversal(nodeBST<T> *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->lchild);
        cout << root->data << endl;
        inorderTraversal(root->rchild);
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Preorder
// Discription  : Used to perform preorder traversal
// Input        : Null
// Output       : void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Preorder()
{
    preorderTraversal(Root);
}

template <class T>
void BST<T>::preorderTraversal(nodeBST<T> *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Postorder
// Discription  : Used to perform postorder traversal
// Input        : NUll
// Output       : void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Postorder()
{
    postorderTraversal(Root);
}

template <class T>
void BST<T>::postorderTraversal(nodeBST<T> *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        cout << root->data << endl;
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Search
// Discription  : Used to search whether an element is present in a tree or not
// Input        : Integer
// Output       : Boolean
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BST<T>::Search(T No)
{
    struct nodeBST<T> *temp = Root;
    while (temp != NULL)
    {
        if (temp->data == No)
        {
            return true;
        }
        else if (No > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return false;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CountLeaf
// Discription  : Used to count all leaf nodes in a tree
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountLeaf()
{
    return countLeafNodes(Root);
}

template <class T>
int BST<T>::countLeafNodes(nodeBST<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CountParent
// Discription  : Used to count all parent nodes in a tree
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountParent()
{
    return countParentNodes(Root);
}

template <class T>
int BST<T>::countParentNodes(nodeBST<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lchild != NULL || root->rchild != NULL)
    {
        return 1 + countParentNodes(root->lchild) + countParentNodes(root->rchild);
    }
    return countParentNodes(root->lchild) + countParentNodes(root->rchild);
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CountAll
// Discription  : Used to count all the nodes in a tree
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountAll()
{
    return countAllNodes(Root);
}

template <class T>
int BST<T>::countAllNodes(nodeBST<T> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countAllNodes(root->lchild) + countAllNodes(root->rchild);
}

/////////////////////////////////////////////////////////////
//
// Codes of Algorithms
//
/////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
public:
    T *Arr;
    int iSize;

    ArrayX(int Value);
    ~ArrayX();

    void Accept();
    void Display();

    bool LinearSearch(T Value);
    bool BiDirectionalSearch(T Value);
    bool Binarysearch(T Value);

    void BubbleSort();
    void BubbleSortEfficient();
    void SelectionSort();
    void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Accept
// Discription  : Used to Accept the element from the user
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout << "Enter the element: " << endl;

    for (i = 0; i < iSize; i++)
    {
        cin >> Arr[i];
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display element 
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: LinearSearch
// Discription  : Used to search an element from the given array linearly
// Input        : Integer, Float, etc
// Output       : boolean
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;

    for (int i = 0; i < iSize; i++)
    {
        if (Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: BiDirectionalSearch
// Discription  : Used to search an element in the array from both the ends i.e bidirrectionaly
// Input        : Integer, Float, etc
// Output       : boolean
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = 0;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: BinarySearch
// Discription  : Used to search an element from the array
// Input        : Integer, float, etc
// Output       : boolean
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::Binarysearch(T Value) // increasing
{
    int iStart = 0, iEnd = 0, iMid = 0;

    bool flag = false;
    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if (Arr[iMid] == Value || Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            flag = true;
            break;
        }
        else if (Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if (Value > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: BubbleSort
// Discription  : Used to sort a given set of n elements provided in the form of array with n numbers of element.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for (i = 0; i < iSize - 1; i++) 
    {
        for (j = 0; j < iSize - 1 - i; j++) 
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1]; 
                Arr[j + 1] = temp;
            }
        }
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: BubbleSortEfficient
// Discription  : Used to sort a given set of n elements provided in the form of array with n numbers of element.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    for (i = 0; i < (iSize - 1) && (flag == true); i++) 
    {
        flag = false;

        for (j = 0; j < iSize - 1 - i; j++) 
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1]; 
                Arr[j + 1] = temp;
                flag = true;
            }
        }
    }
}

 /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SelectionSort
// Discription  : Used to sort a given set of n elements provided in the form of array with n numbers of element.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    


template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for (i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertionSort
// Discription  : Used to sort a given set of n elements provided in the form of array with n numbers of element.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 21/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for (i = 1; i < iSize; i++)
    {
        for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

/////////////////////////////////////////////////////////////
//
// Codes of Additional Functions
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeA
{
    T data;
    struct nodeA *next;
};

template <class T>
class AdditionalFunctions
{
private:
    struct nodeA<T>* First;
    
public:
    AdditionalFunctions();
    void InsertFirst(T No);
    void Display();
    int Count();
    int Addition();
    int EvenCount();
    int OddCount();
    int Frequency(T No);
    bool Search(T No);
    int SearchFirstOccurance(T No);
    int SearchLastOccurance(T No);
    void SumDigits();
    int FactorsAddition(T No);
    bool CheckPerfect(T No);
    void DisplayPerfect();
    void SumFactors();
    int MiddleElement();
    int MiddleElementX();


};

template <class T>
AdditionalFunctions<T> :: AdditionalFunctions()
{
    cout << "Inside constructor" << endl;
    First = NULL;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: InsertFirst
// Discription  : Used to insert an element in the LL.
// Input        : Integer, Float etc
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void AdditionalFunctions<T> :: InsertFirst(T No)
{
    struct nodeA<T>* newn = NULL;

    newn = new nodeA<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}   
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Display
// Discription  : Used to display the LL.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void AdditionalFunctions<T> :: Display()
{
    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First -> next;
    }
    printf("NULL\n");
} 
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Count
// Discription  : Used to count the elements present in LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: Count()
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
} 
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Addition
// Discription  : Used to add all element in the LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: Addition()
{
    int iSum = 0;

    while(First != NULL)
    {
        iSum = iSum + (First->data);
        First = First -> next;
    }

    return iSum;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CountEven
// Discription  : Used to count an even element in the LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: EvenCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First->data)% 2 == 0)
        {
            iCount++;
        }
        First = First -> next;
    }

    return iCount;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: OddCount
// Discription  : Used to count an odd element in the LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: OddCount()
{
    int iCount = 0;

    while(First != NULL)
    {
        if((First->data)% 2 == 1)
        {
            iCount++;
        }
        First = First -> next;
    }

    return iCount;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Frequency
// Discription  : Used to count the frequency of an element in the LL.
// Input        : Integer, Float etc
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: Frequency(T No)
{
    int iCount = 0;

    while(First != NULL)
    {
        if(First -> data == No)
        {
            iCount++;
        }
        First = First -> next;
    }

    return iCount;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Search
// Discription  : Used to search an element in the LL.
// Input        : Integer, Float etc
// Output       : Boolean
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool AdditionalFunctions<T> :: Search(T No)
{
    bool bFlag = false;

    while(First != NULL)
    {
        if(First->data == No)
        {
            bFlag = true;
            break;
        }
        First = First->next;
    }
    return bFlag;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchFirstOccurance
// Discription  : Used to search the first occurance of an element in the LL.
// Input        : Integer, Float etc
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: SearchFirstOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if(First ->data == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        First = First -> next;
    }

   return iPos;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SearchLastOccurance
// Discription  : Used to search the last occurance of an element in the LL.
// Input        : Integer, Float etc
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: SearchLastOccurance(T No)
{
    int iCount = 1;
    int iPos = -1;

    while(First != NULL)
    {
        if(First ->data == No)
        {
            iPos = iCount;
        }
        iCount++;
        First = First -> next;
    }

   return iPos;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SumDigits
// Discription  : Used to perform the addition of digit of element in the LL.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void AdditionalFunctions<T> :: SumDigits()
{
    int iSum = 0;
    int iNo = 0;
    int iDigit = 0;

    while(First != NULL)
    {
        iNo = First -> data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        printf("%d\n",iSum);
        iSum = 0;

        First = First -> next;
    }
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: FactorsAddition
// Discription  : Used to perform the addition of an factors of an element in the LL.
// Input        : Integer, Float etc
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: FactorsAddition(T iNo)
{
    int iSum = 0, i = 0;

    for(i = 1; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CheckPerfect
// Discription  : Used to check whether an element is perfect or not in the LL.
// Input        : Integer, Float etc
// Output       : Boolean
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool AdditionalFunctions<T> :: CheckPerfect(T iNo)
{
    int iSum = 0, i = 0;

    for(i = 1; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: DisplayPerfect
// Discription  : Used to display perfect an element in the LL.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void AdditionalFunctions<T> :: DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
            printf("Perfect number from LL is : %d\n",First->data);
        }
        First = First -> next;
    }
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SumFactors
// Discription  : Used to perform sum of factors of an element in the LL.
// Input        : Null
// Output       : Void
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void AdditionalFunctions<T> :: SumFactors()
{
    while(First != NULL)
    {
        printf("%d\n",FactorsAddition(First->data));
        First = First -> next;
    }
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: MiddleElement
// Discription  : Used to find the middle element in the LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: MiddleElement()
{
    int iCnt = 0;
    struct nodeA<T>* temp = First;
    int iPos = 0, i = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }

    iPos = iCnt / 2;

    for(i = 1;i <= iPos; i++)
    {
        First = First -> next;
    }

    return First->data;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: MiddleElementX
// Discription  : Used to find middle element in the LL.
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 28/07/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int AdditionalFunctions<T> :: MiddleElementX()
{
    struct nodeA<T>* Teacher = First;
    struct nodeA<T>* Student = First;

    while((Teacher != NULL) && (Teacher -> next != NULL))
    {
        Teacher = Teacher -> next->next;
        Student = Student -> next;
    }

    return (Student->data);
}



/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: Main
// Discription  : Entry point function
// Input        : Null
// Output       : Integer
// Author       : Sakshi Bhandari
// Date         : 20/06/2024
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}