#include <iostream>
#include "arvoreBinariaAVL.h"


int main() {
     arvoreBinariaAVL* arv = new arvoreBinariaAVL();

     //cout << arv->get_altura() << '\n';

     arv->inserir(100);
     arv->inserir(90);
     arv->inserir(110);
     arv->inserir(85);
     arv->inserir(91);
     arv->inserir(83);
     arv->inserir(84);
     arv->inserir(82);
     arv->inserir(81);
     arv->inserir(80);
     arv->inserir(400);
     arv->inserir(410);
     arv->inserir(150);
     arv->inserir(350);
     arv->inserir(320);
     arv->inserir(330);
     arv->inserir(1000);
     arv->inserir(900);
     arv->inserir(800);
     arv->inserir(500);


     arv->inOrder();
     cout << '\n';
     arv->removerAVL(500);
     arv->inOrder();
     cout <<'\n';
     //arv->imprime();
     return 0;
}
