struct lista{lista * next; int v;};
void sasiedzi(int n, lista *p, lista **A);
void sasiedziKazdegoWierzcholka(int n, lista *p, lista**A);
void stopnieWychodzace(int n, lista *p, lista **A);
void stopnieWchodzace(int n, lista *p, lista**A);
void wierzcholkiIzolowane(int n, lista *p, lista **A);
void petle(int n, lista *p, lista**A);
void krawedzieDwukierunkowe(int n, lista *p, lista **A);
