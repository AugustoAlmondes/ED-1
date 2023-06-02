typedef struct cliente Cliente;
typedef struct rota Rota;

Cliente *criarlista();
Cliente *inserir(Cliente *cliente);
Cliente *organizar(Cliente *cliente);
// Rota *organizar(Rota *rota);
void MostrarTodos(Cliente *cliente);