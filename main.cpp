#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{

    string blueprint,blueprint1,bg,bg1;

    bg="resources/Sunny-land-files/PNG/environment/layers/back.png";
    blueprint += "bwwwwwwwwwwwwbb------------------------b.";
    blueprint += "bwwwwwwwwwwwwbb------------------------b.";
    blueprint += "bwwwwwwwbbbbbbb-----------f------------b.";
    blueprint += "bbwwwwwwwbbbbbb----o--j------j----sd---b.";
    blueprint += "bwwwwwwwbbbbbbbpEpppppr------lpppppppEpb.";
    blueprint += "bwwwwwwwwbbbbbb-e--------------------e-b.";
    blueprint += "bbbbbbbbbbbbbbb-e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e-------j---j--------e-b.";
    blueprint += "b---------------Eppppppppp^-r-------lEpb.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b---------------e--------------------e-b.";
    blueprint += "b-------j--j----e--------j--o--j--j--e-b.";
    blueprint += "bEppppppr-flppppEr-------ppppppp^-pppEpb.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e----------f---------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--j----j-j-o-je----j--------j-d-s--e-b.";
    blueprint += "bEppr----lppppppEpp^-pr-------lppppppE-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--------------e--------------------e-b.";
    blueprint += "be--j--j--------e----j---j--jj--o--j-e-b.";
    blueprint += "bEppp^-pr----lppEppppp--lp^-pppppppppEpb.";
    blueprint += "b--f---------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b------------------------------------e-b.";
    blueprint += "b--------j--j---j-------j--o--j------E-b.";
    blueprint += "bppppppppp^-pppppppppppppppppppppppppppb.";

    bg1="resources/Sunny-land-files/PNG/environment/layers/back2.png";
    blueprint1 += "bwwwwwwwwwwwwbb------------------------b.";
    blueprint1 += "bwwwwwwwwwwwwbb------------------------b.";
    blueprint1 += "bwwwwwwwbbbbbbb------------------------b.";
    blueprint1 += "bbwwwwwwwbbbbbb------------------------b.";
    blueprint1 += "bwwwwwwwbbbbbbb------------------------b.";
    blueprint1 += "bwwwwwwwwbbbbbb------------------------b.";
    blueprint1 += "bbbbbbbbbbbbbbb------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b------p--l--b--r--e--w--s--j----------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------------------b.";
    blueprint1 += "b--------------------------o-----------b.";
    blueprint1 += "bppppppppppppppppppppppppppppppppppppppb.";

    Game * CSO = new Game(640,480,"C-SO! Remix"); //tiles de 20px -32ancho -22alto
    CSO->newLevel(blueprint,bg,1);
    if(CSO->Gloop()!=0){
    cout<<"-----------"<<endl<<"Has perdido"<<endl<<"-----------------";
     CSO->newLevel(blueprint1,bg1,2);
    if(CSO->Gloop()!=0){
    cout<<"-----------"<<endl<<"Has perdido"<<endl<<"-----------------";
    }else{
    cout<<"-----------"<<endl<<"Has ganado"<<endl<<"-----------------";
    }
    }else{
    cout<<"-----------"<<endl<<"Has ganado"<<endl<<"-----------------";
}

    return 0;
}

