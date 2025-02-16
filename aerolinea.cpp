#include"aerolinea.h"
bool Avion::EsV(){
    if(g ==0){
        return true;
    }
    else{
        return false;
    }
}

void Avion::LP(){
    k = new Reservacion[capacidad];
    if(g<capacidad){
        cout<<"Solo puedes registrar "<<capacidad-g<<" pasajeros."<<endl;
        k[g].Lr();
        g++;
    }
    else{
        cout<<"Ya no puedes reservar mas personas, haz alcanzado el limite."<<endl;
    }
}

void Avion::IP(){
    for(int i=0;i<g;i++){
    k[i].ImV();
    }
}

bool Aerolinea::Es_vaciO(){
    if(m==0){
        return true;
    }
    return false;
}

void Reservacion::Lr(){
    Pasajero::Lr();
    cout<<"Ingresa el numero de reserva: ";
    cin>>NumeroReserva;
    cout<<"Ingresa el numero de asiento: ";
    cin>>NumeroAsiento;
    cout<<"Ingresa el numero de pasajero: ";
    cin>>NumeroPasa;
}

void Reservacion::ImV(){
    Pasajero::ImV();
    cout<<"Numero de reserva: "<<NumeroReserva<<endl;
    cout<<"Numero de asiento: "<<NumeroAsiento<<endl;
    cout<<"Numero de pasajero: "<<NumeroPasa<<endl;
}

void Aerolinea::HacerReser(int clave){
   z[clave].LP();
}

void Aerolinea::VerPasa(int clave){
        cout<<"Avion "<<FlotaAvion[clave]<<": "<<endl;
        z[clave].ImprimiV();
        cout<<endl;
        cout<<"Vuelo "<<ListaVuelos[clave]<<": "<<endl;
        cout<<"Numero de vuelo: "<<ap[clave].NV()<<endl;
        cout<<"Origen: "<<ap[clave].O()<<endl;
        cout<<"Destino: "<<ap[clave].D()<<endl;
        cout<<"Hora de salida: : "<<ap[clave].Hs()<<endl;
        cout<<"Hora de llegada: "<<ap[clave].Hl()<<endl;
        cout<<"Fecha: "<<ap[clave].d()<<"/"<<ap[clave].m()<<"/"<<ap[clave].y()<<endl;
        cout<<endl;
        z[clave].IP();
}

int Vuelo::NV(){
    return NumVuelo;    
}

void Vuelo::NumVuel(){
    cout<<"Ingresa el numero de vuelo : ";
    cin>>NumVuelo;
}

void Aerolinea::ImprimirAvion(){
    for(int i=0;i<p;i++){
        cout<<"Avion "<<FlotaAvion[i]<<": "<<endl;
        z[i].ImprimiV();
        cout<<endl;
    }
}

void Avion::Leerem(){
        cout<<"Ingresa el modelo del avion: ";
        cin.ignore();
        getline(cin, Model);
        cout<<"Ingresa la capacidad del avion: ";
        cin>>capacidad;
}

void Avion::ImprimiV(){
        cout<<"Modelo: "<<Model<<endl;
        cout<<"Capacidad: "<<capacidad<<" personas"<<endl;
}

void Aerolinea::AgregarVuelo(){
	string clave,ave,wht;
	string d,M,y;
	string r,t;
	cout<<"El numero de aviones que puedes registrar es "<<10-m<<endl;
    if(m<10){
            ListaVuelos[m] = m + 1;
            ap[m].NumVuel();
            cout << "¿Cuál es el destino? ";
            cin.ignore();
            getline(cin, clave); 
            ap[m].Des(clave);
            
            cout << "¿Cuál es el origen? ";
            getline(cin, ave);
            ap[m].Ori(ave);
            
            cout << "Ingresa la fecha con números" << endl;
            cout << "¿Qué día? ";
            getline(cin, d);
            ap[m].Day(d);
            
            cout << "¿Qué mes? ";
            getline(cin, M);
            ap[m].Mont(M);
            
            cout << "¿Qué año? ";
            getline(cin, y);
            ap[m].Year(y);
            
            cout << "Ingresa la hora de salida: ";
            getline(cin, r);
            ap[m].HS(r);
            
            cout << "Ingresa la hora de llegada: ";
            getline(cin, t);
            ap[m].HL(t);
            
            ++m;
    }
}

void Aerolinea::AgregarAvion(){
	cout<<"El numero de aviones que puedes registrar es "<<10-p<<endl;
    if(p<10){
        FlotaAvion[p] = p+1;
        z[p].Leerem();
        ++p;
    }
    else{
    cout<<"Elimina un elemento para poder agregar otro";
    }
}

void Aerolinea::Leer(){
    cout<<"Ingresa nuevamente el nombre de la aerolinea : ";
	getline(cin, NombreAerlinea);
}

void Aerolinea::ImprimirNombre(){
    cout<<NombreAerlinea<<endl;
}

bool Aerolinea::Buscar(string clave){
        if(NombreAerlinea == clave){
           return true;
        }
    return false;
}

bool Aerolinea::Es_vacia(int q){
    if(q==0){
        return true;
    }
    return false;
}

bool Aerolinea::Es_vaciA(){
    if(p==0){
        return true;
    }
    return false;
}

void Vuelo::Day(string d){
    dia = d;
}

void Vuelo::Mont(string z){
    mes = z;
}

void Vuelo::Year(string y){
    anio = y;
}

void Vuelo::Des(string clave){
    Destino = clave;
}

void Vuelo::Ori(string clave){
    Origen  = clave;
}

void Vuelo::HS(string p){
    HoraSalida = p;
}

void Vuelo::HL(string p){
    HoraLlegada = p;
}

string Vuelo::d(){
    return dia;
}

string Vuelo::m(){
    return mes;
}

string Vuelo::y(){
    return anio;
}

string Vuelo::D(){
    return Destino;
}

string Vuelo::O(){
    return Origen;
}

string Vuelo::Hs(){
    return HoraSalida;
}

string Vuelo::Hl(){
    return HoraLlegada;
}

void Aerolinea::ImprimirVuel(){
    for(int i = 0;i<m;i++){
        cout<<"Vuelo "<<ListaVuelos[i]<<": "<<endl;
        cout<<"Numero de vuelo: "<<ap[i].NV()<<endl;
        cout<<"Origen: "<<ap[i].O()<<endl;
        cout<<"Destino: "<<ap[i].D()<<endl;
        cout<<"Hora de salida: : "<<ap[i].Hs()<<endl;
        cout<<"Hora de llegada: "<<ap[i].Hl()<<endl;
        cout<<"Fecha: "<<ap[i].d()<<"/"<<ap[i].m()<<"/"<<ap[i].y()<<endl;
        cout<<endl;
    }
}

void Aerolinea::EliminarAvion(int clave) {
    if (clave >= 0 && clave < p) { 
        for (int i = clave; i < p - 1; ++i) {
            z[i] = z[i+1];
        }
        --p;
    } else {
        cout << "Intenta de nuevo." << endl;
    }
}

void Aerolinea::EliminarVuelo(int clave){
	if (clave >= 0 && clave < m) { 
        for (int i = clave; i < m - 1; ++i) {
            ap[i] = ap[i+1];
        }
        --m;
    } else {
        cout << "Intenta de nuevo." << endl;
    }
}

bool Aerolinea::Sav(int clave){
    bool cn;
    cn = z[clave].EsV();
    return cn;
}

void Aerolinea::Ims(){
    for(int i = 0;i<m;i++){
        cout<<"Avion "<<FlotaAvion[i]<<": "<<endl;
        z[i].ImprimiV();
        cout<<endl;
        cout<<"Vuelo "<<ListaVuelos[i]<<": "<<endl;
        cout<<"Numero de vuelo: "<<ap[i].NV()<<endl;
        cout<<"Origen: "<<ap[i].O()<<endl;
        cout<<"Destino: "<<ap[i].D()<<endl;
        cout<<"Hora de salida: : "<<ap[i].Hs()<<endl;
        cout<<"Hora de llegada: "<<ap[i].Hl()<<endl;
        cout<<"Fecha: "<<ap[i].d()<<"/"<<ap[i].m()<<"/"<<ap[i].y()<<endl;
        cout<<endl;
    }
}