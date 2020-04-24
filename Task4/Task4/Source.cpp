#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include<random>

using namespace std;

struct list {
    int id;
    list* next;
};

bool Equal(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++)
            if (toupper(a[i]) != toupper(b[i]))
                return false;
        return true;
    }
    else return false;
}

  void insert_last_element(list**A)
{
    list* B = new list();
    B = *A;
    while(B->next!=NULL)
    {
        B = B->next;
    }
    cout << "Enter your element\n";
    int t;
    cin >> t;
    list* F = new list();
    F->id = t;
    B->next = F;
}

void insert_after_given_element(list**A)
{
    int x;
    cout << "Insert the id of the element before which we insert the number\n";
    cin >> x;
    list* B = new list();
    list* C = new list();
    B = (*A)->next;
    C = *A;
    int t = 1;
    while (C != NULL)
    {
        if (C->id == x)
        {
            cout << "Enter your element\n";
            int t;
            cin >> t;
            list* F = new list();
            F->id = t;
            C->next = F;
            F->next = B;
            break;
        }
        C = C->next;
        B = B->next;
    }
}

void push_element_in_begin(list** A) {
    int x;
    cout << "Enter element, that you want\n";
    cin >> x;
    list* B = new list();
    B->id = x;
    B->next = *A;
    *A = B;
}


void insert_before_given_element(list** A) {
    int x;
    cout << "Insert the id of the element before which we insert the number\n";
    cin >> x;
    list* B = new list();
    list* C = new list();
    C = *A;
    B = (*A)->next;
    int l = 0;
    while (B != NULL)
    {
      if (l==0 && C->id==x)
        {
      	  push_element_in_begin(A);
          break;
        }
        if (B->id == x)
            {
                cout << "Enter your element\n";
                int t;
                cin >> t;
                list* F = new list();
                F->id = t;
                C->next = F;
                F->next = B;
                break;
            }
        l++;
        C = C->next;
        B = B->next;
    }
}

void writeln(list* A) {
    if (A!= NULL) {
        if (A->next != NULL)
            cout << A->id << "->";
        else
            cout << A->id <<endl;
        writeln(A->next);
    }
}

void delete_first_element(list **A)
{
    list* B = new list();
    B = *A;
	B = B->next;
    *A = B;
}

void delete_last_element(list** A)
{
    list* B = new list();
    B = *A;
    if (B->next==NULL)
    {
        B = NULL;
        *A = B;
    }
    while(B->next->next!=NULL)
	B = B->next;
    B->next = NULL;
}

void delete_given_element(list** A)
{
    int x;
    cout << "Write the id of element, which we delete\n";
    cin>>x;
    list* B = new list();
    list* C = new list();
    B = (*A)->next;
    C = *A;
    int p = 1;
    while (B != NULL)
    {
        if (p==1 && C->id==x)
        {
            delete_first_element(A);
            break;
        }
        if (B->id == x)
        {
            C->next = C->next->next;
        }
        C = C->next;
        B = B->next;
        p++;
    }
}

void push_list_in_begin(list** A) {
    cout << "This is your new list C\n"<<"Enter how elements in your list C\n";
    int c;
	cin >> c;
    list *B = new list();
    list* D = new list();
    for (int i = 0; i < c; i++)
    {
        list* C = new list();
    	C->id = rand()%30;
        if (i == 0)
            B = NULL;
        C->next = B;
        B = C;
    }
    writeln(B);
    cout << "\nIf you want to insert this list in A's begin write Yes\n";
    string a;
    cin >> a;
    D = B;
    if (a=="Yes")
    {
        if (B->next != NULL)
            B = B->next;
        if (c!=1)
        B->next->next= *A;
        else B->next = *A;
        *A = D;
    }
    else cout << "Nothing changed\n";
}

void delete_all_minus_elements(list** A)
{
    list* B = new list();
    B = *A;
    while (B->id < 0)
    {
        delete_first_element(&B);
        *A = B;
    }
    while (B != NULL)
    {
        list* C = new list;
        C = B;
        if (B->next != NULL)
        {
            C = C->next;
            if (C->id < 0)
            {
                B->next = B->next->next;
            }
        }
        C = B;
        C = C->next;
        if (C!=NULL)
          if (C->id>0)
           B = B->next;
        if (C==NULL)
            B = B->next;
    }
}

int main() {
    srand(time(NULL));
    cout << "P.s. In my list five elements(they are random); you can change number and value in code\n";
    list* A = new list();
    for (int i = 0; i < 5; i++)
    {
        list* B = new list();
        B->id = rand() % 20;
        if (i == 0)
            A = NULL;
        B->next = A;
        A = B;
    }
    string a;
    cout << "Choose A.number what you want:\n" << "B task is individual\n" << "A1 push element in begin\n" << "A2 push list in begin\n" << "A3 show all elements\n";
    cout << "A4 insert before given element\n" << "A5 insert after given element\n" << "A6 insert last element\n" << "A7 delete first element\n" << "A8 delete last element\n";
    cout << "A9 delete given element\n" << "B4 delete all minus elements\n" << "\nIf you want end, write Exit\n";
while (1==1)
 {
    cin >> a;
    if (Equal(a, "A1") == 1)
    {
        push_element_in_begin(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A2") == 1)
    {
        push_list_in_begin(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A3") == 1)
    {
        writeln(A);
        cout << "Complete\n";
    }
    if (Equal(a, "A4") == 1)
    {
        insert_before_given_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A5") == 1)
    {
        insert_after_given_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A6") == 1)
    {
        insert_last_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A7") == 1)
    {
        delete_first_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A8") == 1)
    {
        delete_last_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "A9") == 1)
    {
        delete_given_element(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "B4") == 1)
    {
        delete_all_minus_elements(&A);
        cout << "Complete\n";
    }
    if (Equal(a, "Exit") == 1)
        break;     
 }
    delete A;
}