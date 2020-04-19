#include <iostream>

using namespace std;

struct list {
    int degree;
    int coefficient;
    list* next;
};

void final1(list** A, int t)
{
    list* O = new list;
    list* B = new list;
    list* before = new list;
    before = *A;
    O = *A;
    int i = 1;
    int forO = 1;
    while(i<t)
    {
        B = (*A)->next;
        int forB = 2;
        
        while(B!=NULL)
        {
            int f = 0;
            if (B->degree == O->degree && forO<forB)
            {
                O->coefficient = O->coefficient + B->coefficient;
                B = B->next;
                before->next = before->next->next;
                f++;
                forB--;
            }
            if (B != NULL && f == 0)
            {
                B = B->next;
                before = before->next;
            }
            forB++;
        }
        O = O->next;
        if (O == NULL)
            break;
        i++;
        forO++;
        before = *A;
    }
}


void writeln(list* A) {
    list* B = new list;
    B = A->next;
    if (B!= NULL)
    {
        if (B->coefficient >= 0)
        {
            if (A->coefficient!=1 && A->degree!=1)
            cout << A->coefficient << "x^" << A->degree << "+";
            else if (A->coefficient != 1 && A->degree == 1)
                cout << A->coefficient << "x"<< "+";
            else if (A->coefficient == 1 && A->degree != 1)
                cout << "x^" << A->degree << "+";
            else if (A->coefficient == 1 && A->degree == 1)
                cout << "x" << "+";
        }
        if (B->coefficient < 0)
            if (A->coefficient != 1 && A->degree != 1)
                cout << A->coefficient << "x^" << A->degree << "-";
            else if (A->coefficient != 1 && A->degree == 1)
                cout << A->coefficient << "x" << "-";
            else if (A->coefficient == 1 && A->degree != 1)
                cout << "x^" << A->degree << "-";
            else if (A->coefficient == 1 && A->degree == 1)
                cout << "x" << "-";
        writeln(A->next);
    }
    else
    {
        if (A->coefficient != 1 && A->degree != 1)
            cout << A->coefficient << "x^" << A->degree;
        else if (A->coefficient != 1 && A->degree == 1)
            cout << A->coefficient << "x";
        else if (A->coefficient == 1 && A->degree != 1)
            cout << "x^" << A->degree;
        else if (A->coefficient == 1 && A->degree == 1)
            cout << "x";
    }
}

int main() {
    cout << "My programm give similar terms: you enter 3 3  2 2  3 4 (3x^3+2x^2+4x^3) and I write 7x^3+2x^2\n";
    list* A = new list();
    cout << "Write how many terms you enter\n";
    int t,l;
	cin >> t;
    cout << "Write degree then coefficient\n";
	for (int i = 0; i < t; i++)
    {
        list* C = new list();
        cin >> l;
        C->degree = l;
        cin >> l;
        C->coefficient = l;
        if (i == 0)
        {
            A = NULL;
        }
        C->next = A;
        A = C;
    }
    cout << "This what you write\n";
	writeln(A);
    cout << "\nThis what I write\n";
    final1(&A, t);
    writeln(A);
}