typedef struct pixel Pixel;
typedef struct imagem Imagem;

Imagem *criarImagem(int largura, int altura);
void preencherImagem(Imagem *img);
void imprimirImagem(Imagem *img);
void liberarimagem(Imagem *img);
void setPixelValue(Imagem *img, int y, int x, int valor);
int getPixelValue(Imagem *img, int y, int x);


