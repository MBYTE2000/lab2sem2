#include <iostream>
#include <random>
#include <fstream>
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

void Individual(Stack *begin)
{
    Stack* t = begin, * p = begin->next;
    for (; p; p = p->next)
        if (p->info > t->info)  t = p;
    p = begin;
    if (p != t) {
        while (p->next != t)   p = p->next;
        p->next = t->next;
    }
    else
        begin = t->next;
    delete t;
}

void saveStackToFile(Stack* top, const std::string& filename) {
    ofstream file;
    file.open(filename);

    if (file.is_open()) {
        Stack* current = top;

        while (current != nullptr) {
            file << current->info << std::endl;
            current = current->next;
        }

        file.close();
        std::cout << "Стек успешно сохранен в файл: " << filename << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
    }
}


int main()
{
    int i, in, n, input;

    while (true) {

        cout << "\n\tCreate - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tSort1 - 5\n\tSort2 - 6\n\tIndividual - 7\n\tSave - 8\n\tEXIT - 0. : ";

        cin >> input;

        switch (input) {

        case 1: 

        case 2:

            if (input == 1 && Begin != NULL) {

                // Если создаем новый стек, должны освободить память, занятую предыдущим

                cout << "Clear Memory!" << endl;

                break;

            }

            cout << "Input kol = "; cin >> n;

            for (i = 1; i <= n; i++) {

                in = rand() * 20;

                Begin = InStack(Begin, in);

            }

            if (input == 1) cout << "Create " << n << endl;

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
            Individual(Begin);
            View(Begin);
            break;

        case 8:
            saveStackToFile(Begin, "example");
            break;

        case 0:
            if (Begin != NULL)

                Del_All(&Begin);

            return 0; // Выход – EXIT

        }

    }
}