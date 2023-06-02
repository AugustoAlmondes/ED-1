typedef struct conta Conta;
Conta *criarlistaEstatica(int tamanho);
Conta *inserirElementos(Conta *listacontas, int posi, int tamanho);
void removerElemento(Conta *listacontas, int tamanho); //remover pelo numero da conta
int buscarElemento(Conta *listacontas, int tamanho, int numero);
void mostarElemento(Conta elemento);
void mostarTodos(Conta *listacontas, int tamanho);
void liberar(Conta *listacontas);
void mostrarsaldo(Conta *listacontas, int tamanho, int numero);
