typedef struct fila Fila;
Fila* fila_cria (void);
Fila *fila_insere (Fila* f);
Fila *fila_retira (Fila* f);
Fila *fila_libera (Fila* f);
int fila_vazia (Fila* f);
void mostrar_inicio(Fila *f);
void mostrar_fim(Fila *f);
void mostrar_todos_elementos_fila(Fila *f);