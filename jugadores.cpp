#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    public:
    int HP;
    int DP;
    string playerName;
    string ultimo;

    Jugador(); 
    Jugador(int h, int d, string nom); 
    string getUltimo();
    void atacar(Jugador p); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios
    int z =0;
    int g = 0;
    Jugador p1;
    p1.HP=20;
    p1.DP=4;
    p1.playerName = "Juanete";
    Jugador p2= {50,7,"pedrete"};


    while (p1.HP >0 && p2.HP>0){
            p1.atacar(p2);
            p2.atacar(p1);
    }
    if (p2.HP>0){
    cout << "Jugador 1 a muerto," << p2.playerName << " es el ganador :D" << endl;
    } else{
    cout << "Jugador 2 a muerto," << p1.playerName << " es el ganador :D" << endl;
    }
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */

    return 0;
}

Jugador::Jugador(){
    HP = 100;
    DP = 5;
    playerName = "No definido";
}

Jugador::Jugador(int h, int d, string nom){
    playerName = nom;
    if (h>0 and h<200) {
        HP = h;
    }else {HP = 1;}
    if (d>0 and d<20) {
        DP = d;
    }else {DP = 1;}
}

void Jugador::atacar(Jugador p){
    int x = rand() % 1000;
    if (x > 645 and x<845 ){
    cout<< p.playerName << " ataco a  " << playerName << " ,el ataque a fallado vide restante: " << HP << endl;
    } else {
    cout<< playerName << " recibio " << p.DP << " puntos de danio infligido por " << p.playerName <<endl;
    HP = HP - p.DP;
    ultimo = p.playerName;
    }
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}