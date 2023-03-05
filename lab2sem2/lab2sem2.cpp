#include <iostream>
#include <random>
using namespace std;

struct Stack {

    int info; // Информационная часть элемента, например int

    Stack* next; // Адресная часть – указатель на следующий элемент

} *Begin; // Указатель вершины стека

Stack* InStack(Stack* p, int in)
{

    Stack* t = new Stack; // Захватываем память для элемента

    t->info = in; // Формируем информационную часть

    t->next = p; // Формируем адресную часть

    return t;

}

void Del_All(Stack** p) {

    Stack* t;

    while (*p != NULL) {

        t = *p;

        *p = (*p)->next;

        delete t;

    }

}

Stack* OutStack(Stack* p, int* out) {

    Stack* t = p; // Устанавливаем указатель t на вершину p

    *out = p->info;

    p = p->next; // Переставляем вершину p на следующий

    delete t; // Удаляем бывшую вершину t

    return p; // Возвращаем новую вершину p

}

void View(Stack* p) {

    Stack* t = p;

    while (t != NULL) {

        // Вывод на экран информационной части, например, 
        cout << t -> info << endl;

        t = t->next;

    }

}

void Sort_p(Stack** p) {

    Stack* t = NULL, * t1, * r;

    if ((*p)->next->next == NULL) return;

    do {

        for (t1 = *p; t1->next->next != t; t1 = t1->next)

            if (t1->next->info > t1->next->next->info) {

                r = t1->next->next;

                t1->next->next = r->next;

                r->next = t1->next;

                t1->next = r;

            }

        t = t1->next;

    } while ((*p)->next->next != t);
}

    void Sort_info(Stack * p)
    {

        Stack* t = NULL, * t1;

        int r;

        do 
        {

            for (t1 = p; t1->next != t; t1 = t1->next)

                if (t1->info > t1->next->info) {

                    r = t1->info;

                    t1->info = t1->next->info;

                    t1->next->info = r;

                }

            t = t1;

        } while (p->next != t);

    }

void Individual(Stack *p)
{
    Stack* t = p;
    int max = 0;
    for(int i = 0;t->next != NULL;i++)
    {
        if (t->info > max) max = t->info;
        t = t->next;
    }

    while (t != NULL) {
        if (t->info == max) {
            p->next = t->next;
            delete t;
            t = p->next;
        }
        else {
            p = t;
            t = t->next;
        }
    }

}


int main()
{
    int i, in, n, kod;

    while (true) {

        cout << "\n\tCreat - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tSort1 - 5\n\tSort2 - 6\n\tIndividual - 7\n\tEXIT - 0. : ";

        cin >> kod;

        switch (kod) {

        case 1:

        case 2:

            if (kod == 1 && Begin != NULL) {

                // Если создаем новый стек, должны освободить память, занятую предыдущим

                cout << "Clear Memory!" << endl;

                break;

            }

            cout << "Input kol = "; cin >> n;

            for (i = 1; i <= n; i++) {

                in = rand() * 20;

                Begin = InStack(Begin, in);

            }

            if (kod == 1) cout << "Create " << n << endl;

            else cout << "Add " << n << endl;

        break;

        case 3: if (!Begin) {

            cout << "Stack Pyst!" << endl;

            break;

        }

              cout << "--- Stack ---" << endl;

              View(Begin);

              break;

        case 4:

            Del_All(&Begin);

            cout << "Memory Free!" << endl;

            break;

        case 5:
            Sort_p(&Begin);
            View(Begin);
            break;
        case 6:
            Sort_info(Begin);
            View(Begin);
            break;
        case 7:

            break;

        case 0:

            if (Begin != NULL)

                Del_All(&Begin);

            return 0; // Выход – EXIT

        }

    }
}