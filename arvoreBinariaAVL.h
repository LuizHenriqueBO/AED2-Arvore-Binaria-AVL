#ifndef AVLTree
#define AVLTree
#include <iostream>
#include "arvoreBinariaAVL.h"
#include "No.h"

using namespace std;
     class arvoreBinariaAVL{

     public:
          arvoreBinariaAVL(){
               raiz = NULL;
               fb = 0;
          }

          ~arvoreBinariaAVL(){
               destrutor(raiz);
          }

          void inOrder(){
               inOrder(raiz);
          }

          void inserir(int valor){

               raiz = inserir(raiz,valor);
          }
          /*void remover(int elem){
               raiz = remove(elem,raiz);
          }*/



          int fatorBalanceamento(int alt_esq, int alt_dir){
               return alt_esq - alt_dir;
          }

          void removerAVL(int valor){
               raiz = removerAVL(raiz, valor);
          }

     protected:
     private:



          NoAVL* rotacionadorRR(NoAVL* node){/*rotação simples para a direita*/

               cout << "...RR" << '\n';
               NoAVL* subArvoreEsquerda = node->get_esq();
               node->set_esq(subArvoreEsquerda->get_dir());
               subArvoreEsquerda->set_dir(node);

               node->set_altura(max(altura(node->get_esq()),altura(node->get_dir())) +1);

               subArvoreEsquerda->set_altura(max(altura(subArvoreEsquerda->get_esq()),
               altura(subArvoreEsquerda->get_dir()))+1);
               return subArvoreEsquerda;
          }

          NoAVL* rotacionadorLL(NoAVL* node){/*rotação simples para a esquerda*/
               cout << "...LL" << '\n';
               NoAVL* subArvoreDireita = node->get_dir();
               node->set_dir(subArvoreDireita->get_esq());
               subArvoreDireita->set_esq(node);

               node->set_altura(max(altura(node->get_esq()),altura(node->get_dir()))+1);
               subArvoreDireita->set_altura(max(altura(subArvoreDireita->get_esq()), altura(subArvoreDireita->get_dir()))+1);

               return subArvoreDireita;
          }

          NoAVL* rotacionadorLR(NoAVL* node){/*ROTAÇÃO COMPLEXA PARA DIREITA E ESQUERDA*/
               cout << "...LR" << '\n';
               node->set_dir(rotacionadorRR(node->get_dir()));
               return rotacionadorLL(node);
          }

          NoAVL* rotacionadorRL(NoAVL* node){/*ROTAÇÃO COMPLEXA PARA ESQUERDA E DIREITA*/
               cout << "...RL" << '\n';
               node->set_esq(rotacionadorLL(node->get_esq()));
               return rotacionadorRR(node);
          }




          NoAVL* raiz;
          int fb;


/*
          int get_altura(NoAVL t){/*funcao para pegar a altura do no*/

     /*          return t == null ? -1 : t.get_height();
          }


*/


          int max(int alturaEsquesda, int alturaDireida){/*funcao para achar o maior da esquerda ou da direita do no*/

               return alturaEsquesda > alturaDireida ? alturaEsquesda : alturaDireida;
          }




          int altura(NoAVL* node){
               return node == NULL ? -1 : node->get_altura();
          }


///////////*********funcao de insersão recursiva*************/////////////

          void inOrder(NoAVL* n){
               if(n != NULL){
                    inOrder(n->get_esq());
                    cout << n->get_dado()<< " ";
                    inOrder(n->get_dir());
               }
          }


          NoAVL* verificadorDeslocamento(NoAVL* node,int valor){/*criar uma variável pra diminuir o processamento*/
               if((altura(node->get_esq()) - altura(node->get_dir())) == -2){
                    if(valor > node->get_dir()->get_dado()){
                         node = rotacionadorLL(node);
                    }else{
                         node = rotacionadorLR(node);
                    }
               }
               else if((altura(node->get_esq()) - altura(node->get_dir())) == 2){
                    if(valor < node->get_esq()->get_dado()){
                         node = rotacionadorRR(node);
                    }else{
                         node = rotacionadorRL(node);
                    }
               }
               node->set_altura(max(altura(node->get_esq()), altura(node->get_dir())) + 1);
               return node;
          }






          NoAVL* inserir(NoAVL* node, int valor){
               if(node == NULL){
                    NoAVL* novo = new NoAVL(valor);/*return new NoAVL(valor)*/
                    return novo;
               }
               /*inserindo o dado na arvore*/
               if(valor < node->get_dado()){
                    node->set_esq(inserir(node->get_esq(),valor));
                    /*verificando o desbalanceamento*/
                    node = verificadorDeslocamento(node,valor);
               }else{
                    /*inserindo o dado na arvore*/
                    if(valor > node->get_dado()){
                         node->set_dir(inserir(node->get_dir(),valor));
                         /*verificando o desbalanceamento*/
                         node = verificadorDeslocamento(node,valor);
                         return node;

                    }
               }
          }

///////////*********funcao de remoção recursiva*************/////////////

          // NoAVL* remove(int elem, NoAVL* n){/*Remover recursivo*/
          //      if(n == NULL){
          //           return NULL;
          //      }
          //
          //      if(n!=NULL){
          //           if(n->get_dado() < elem){
          //                n->set_dir( remove(elem, n->get_dir()) );
          //                return n;
          //           }
          //           else if(n->get_dado() > elem){
          //                n->set_esq( remove(elem, n->get_esq()) );
          //                return n;
          //           }
          //           else{
          //                if (n->get_esq()==NULL && n->get_dir()==NULL){
          //                     free(n);
          //
          //                     return NULL;
          //                }
          //                else if (n->get_esq()==NULL && n->get_dir()!=NULL){
          //                     NoAVL* aux = n->get_dir();
          //                     free(n);
          //
          //                     return aux;
          //                }
          //                else if (n->get_esq()!=NULL && n->get_dir()==NULL){
          //                     NoAVL* aux = n->get_esq();
          //                     free(n);
          //
          //                     return aux;
          //                }
          //                else{
          //                     NoAVL* m = n->get_dir();
          //                     while (m->get_esq()!=NULL){
          //                          m = m->get_esq();
          //                     }
          //                     n->set_dado(m->get_dado());
          //                     m->set_dado(elem);
          //
          //                     n->set_dir(remove(elem, n->get_dir()));
          //                }
          //           }
          //      }
          // }



          void destrutor(NoAVL* n){
               if ( n!=NULL ) {
                    destrutor(n->get_esq());
                    destrutor(n->get_dir());
                    free(n);
               }
          }





          NoAVL* removerAVL(NoAVL* node,int valor){

               if(node == NULL){
                    return NULL;
               }

               NoAVL* aux;

               if(valor > node->get_dado()){
                    node->set_dir(removerAVL(node->get_dir(),valor));
                    node = verificadorDeslocamento(node,valor);
                    return node;
               }else{
                    if(valor < node->get_dado()){
                         node->set_esq(removerAVL(node->get_esq(),valor));
                         node = verificadorDeslocamento(node,valor);
                         return node;
                    }else{

                         /*quando o valor é igual--- nem precisa dessa comparação!!!*/
                         if(valor == node->get_dado()){
                              if ((node->get_esq() == NULL) && (node->get_dir()== NULL)) {
                                   delete node;
                                   return NULL;

                              }else{
                                   NoAVL* aux = NULL;
                                   if(node->get_esq() == NULL){/*se só tem o filho direito*/
                                        aux = node->get_dir();
                                        delete node;
                                        return aux;
                                   }else if (node->get_dir() == NULL) {/*se só tem o filho esquerdo*/
                                        aux = node->get_esq();
                                        delete node;
                                        return aux;

                                   }else {/*se o nó tem os dois filhos*/

                                        aux = node->get_esq();
                                        while(aux->get_dir() != NULL){
                                             aux = aux->get_dir();
                                        }
                                        node->set_dado(aux->get_dado());
                                        node->set_esq(removerAVL(node->get_esq(),aux->get_dado()));
                                        return node;
                                   }
                              }
                         }
                    }
               }
          }
     };
#endif
