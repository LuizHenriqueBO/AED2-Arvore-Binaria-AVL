#include <iostream>
#include "arvoreBinariaAVL.h"


int main() {
     arvoreBinariaAVL* arv = new arvoreBinariaAVL();

     //cout << arv->get_altura() << '\n';

     arv->inserir(100);
     arv->inserir(90);
     arv->inserir(80);
     arv->inserir(70);
     arv->inserir(60);
     arv->inserir(50);
     arv->inserir(40);
     arv->inserir(30);
     arv->inserir(20);
     arv->inserir(10);
     arv->inserir(1);
     // arv->inserir(410);
     // arv->inserir(150);
     // arv->inserir(350);
     // arv->inserir(320);
     // arv->inserir(330);
     // arv->inserir(1000);
     // arv->inserir(900);
     // arv->inserir(800);
     // arv->inserir(500);


     arv->inOrder();
     cout << '\n';
     arv->removerAVL(80);
     arv->inOrder();
     cout <<'\n';
     //arv->imprime();
     return 0;
}
