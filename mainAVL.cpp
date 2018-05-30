#include <iostream>
#include "arvoreBinariaAVL.h"


int main() {
     arvoreBinariaAVL* arv = new arvoreBinariaAVL();

     //cout << arv->get_altura() << '\n';

     arv->inserir(10);
     arv->inserir(55);
     arv->inserir(8);
     arv->inserir(6);
     arv->inserir(9);
     arv->inserir(8);

     arv->inOrder();
     cout <<'\n';
     //arv->inOrder();

     cout <<'\n';
     //arv->imprime();
     return 0;
}
