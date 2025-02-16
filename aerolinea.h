#ifndef AEROLINEA_H
#define AEROLINEA_H
#include<iostream>
using namespace std;
class Pasajero{
    protected:
    string NombrePersona;
    int Numpasaporte;
    public: 
    Pasajero():NombrePersona(""),Numpasaporte(0){}
    virtual void Lr(){
        cout<<"Ingresa el nombre de la persona: ";
        cin.ignore();
        getline(cin, NombrePersona);
        cout<<"Ingresa el numero de pasaporte: ";
        cin>>Numpasaporte;
    }
    virtual void ImV(){
        cout<<"Nombre: "<<NombrePersona<<endl;
        cout<<"Numero de pasaporte:"<<Numpasaporte<<endl;
    }
    ~Pasajero(){}
};

class Reservacion:public Pasajero{
    protected:
    int NumeroReserva;
    int NumeroAsiento;
    int NumeroPasa;
    public:
    Reservacion(){NumeroReserva = NumeroPasa = NumeroAsiento = 0;}
    void Lr();
    void ImV();
    ~Reservacion(){}
};

class Avion{
  protected:
  string Model;
  int capacidad;
  Reservacion *k;
  int g;
  public:
  Avion(){capacidad = g = 0;Model = "";}
  void LP();
  void IP();
  bool EsV();
  void Leerem();
  void ImprimiV();
  ~Avion(){}
};

class Vuelo{
    protected:
		int NumVuelo;
		string dia;
		string mes;
		string anio;
		string Origen;
		string Destino;
        string HoraSalida;
		string HoraLlegada;
		public:
		Vuelo(){dia=mes=anio=NumVuelo=0;}
		void Des(string );
		void Ori(string );
		void Day(string);
		void Mont(string);
		void Year(string);
		void HS(string);
		void HL(string);
		string d();
		string m();
		string y();
		string D();
		string O();
		string Hs();
		string Hl();
		void NumVuel();
		int NV();
		~Vuelo(){}
};

class Aerolinea:public Vuelo{
    protected:
    string NombreAerlinea;
    int *ListaVuelos = new int[10];
    int *FlotaAvion = new int[10];
    int m;
    int p;
    int y;
    Vuelo *ap = new Vuelo[10];
    Avion *z = new Avion[10];
    public:
    Aerolinea(){m = p = y = 0;}
    bool Buscar(string);
    bool Es_vacia(int );
    bool Es_vaciA();
    void AgregarVuelo();
    void AgregarAvion();
    void Leer();
    void VerListVuel();
    void ImprimirNombre();
    void ImprimirVuel();
    void ImprimirAvion();
    void EliminarAvion(int);
    void EliminarVuelo(int);
    bool Es_vaciO();
    void HacerReser(int );
    void VerPasa(int );
    bool Sav(int );
    void Ims();
    ~Aerolinea(){
        delete []ap;
        delete []z;
        delete []ListaVuelos;
        delete []FlotaAvion;
    }
};
#include"aerolinea.cpp"
#endif