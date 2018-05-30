#ifndef NO_AVL
#define NO_AVL

     class NoAVL{
     public:
          NoAVL(int num){
               this->dado=num;
               this->esq = NULL;
               this->dir = NULL;
               this->altura = 0;
          }
          int get_dado(){
               return dado;
          }
          int get_altura(){
               return altura;
          }

          NoAVL* get_esq(){
               return esq;
          }
          NoAVL* get_dir(){
               return dir;
          }
          void set_dado(int x){
               dado = x;
          }
          void set_dir(NoAVL* d){
               dir = d;
          }
          void set_esq(NoAVL* e){
               esq = e;
          }
          void set_altura(int alt){
               altura = alt;
          }
     protected:

     private:
          NoAVL* esq;
          NoAVL* dir;
          int dado;
          int altura;
     };

#endif
