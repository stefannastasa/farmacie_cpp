#include "ui.h"

// typedef pair<std::string, void (app_ui::*)()> command;
app_ui::app_ui(){
    /*commands.push_back(pair<std::string, com>("Adaugare\n", &app_ui::adauga) );
    commands.push_back(pair<std::string, com>("Stergere\n", &app_ui::sterge) );
    commands.push_back(pair<std::string, com>("Modificare\n", &app_ui::modifica) );
    commands.push_back(pair<std::string, com>("Afisare\n", &app_ui::afisare) );
    commands.push_back(pair<std::string, com>("Iesire\n", &app_ui::close));*/
}

void app_ui::adauga(){
    std::cout<<"ADAUGARE\n";
    entity result = NULL_ENTITY();
    bool ok = false;
    while(!ok){
        ok = true;
        std::string denumire;
        std::cout<<"Introdu denumirea medicamentului: ";
        std::cin>>denumire;

        std::string pret;
        std::cout<<"Introdu pretul medicamentului: ";
        std::cin>>pret;

        std::string producator;
        std::cout<<"Introdu producatorul medicamentului: ";
        std::cin>>producator;

        std::string substanta_activa;
        std::cout<<"Introdu substanta activa a medicamentului: ";
        std::cin>>substanta_activa;

        result = farmacie.dataConverter(denumire, pret, producator, substanta_activa);
        if(result == NULL_ENTITY()){
            ok = false;
            std::cout<<"Incerci din nou?(da/nu)\n";
            std::string status;
            std::cin>>status;
            if(status == "nu")
                return;
        }
    }

    farmacie.adauga(result);
}

void app_ui::sterge(){
    std::cout<<"STERGERE\n";
    bool ok = false;
    entity result;
    while(!ok){
        ok = true;
        std::string denumire;
        std::cout<<"Introdu denumirea medicamentului: ";
        std::cin>>denumire;

        std::string producator;
        std::cout<<"Introdu producatorul medicamentului: ";
        std::cin>>producator;

        result = farmacie.cauta(denumire, producator);

        if(result == NULL_ENTITY()){
            ok = false;

            std::cout<<"Incerci din nou?(da/nu)\n";
            std::string status;
            std::cin>>status;
            if(status == "nu")
                return;
        }
        
    }

    farmacie.sterge(result);

}

void app_ui::modifica(){
    std::cout<<"MODIFICARE\n";
    entity oldE, newE;

    bool ok = false;
    while(!ok){
        ok = true;
        std::string denumire;
        std::cout<<"Introdu denumirea actuala a medicamentului: ";
        std::cin>>denumire;

        std::string producator;
        std::cout<<"Introdu producatorul actual al medicamentului: ";
        std::cin>>producator;

        oldE = farmacie.cauta(denumire, producator);

        if(oldE == NULL_ENTITY()){
            ok = false;

            std::cout<<"Incerci din nou?(da/nu)\n";
            std::string status;
            std::cin>>status;
            if(status == "nu")
                return;
        }
    }
    ok = false;

    while(!ok){
        ok = true;
        std::string denumire;
        std::cout<<"Introdu denumirea medicamentului: ";
        std::cin>>denumire;

        if(denumire[0] == '*')
            denumire = oldE.denumire;

        std::string pret;
        std::cout<<"Introdu pretul nou al medicamentului(sau * pentru a nu modifica): ";
        std::cin>>pret;

        if(pret[0] == '*')
            pret = std::to_string(oldE.pret);

        std::string producator;
        std::cout<<"Introdu producatorul medicamentului(sau * pentru a nu modifica): ";
        std::cin>>producator;

        if(producator[0] == '*')
            producator = oldE.producator;

        std::string substanta_activa;
        std::cout<<"Introdu substanta activa a medicamentului(sau * pentru a nu modifica): ";
        std::cin>>substanta_activa;

        if(substanta_activa[0] == '*')
            substanta_activa = oldE.substanta_activa;

        newE = farmacie.dataConverter(denumire, pret, producator, substanta_activa);
        if(newE == NULL_ENTITY()){
            ok = false;
            std::cout<<"Incerci din nou?(da/nu)\n";
            std::string status;
            std::cin>>status;
            if(status == "nu")
                return;
        }
    }
    farmacie.modifica(oldE, newE);
}

void app_ui::cauta(){
    std::cout<<"CAUTARE\n";
    bool ok = false;
    entity result;
    while(!ok){
        ok = true;
        std::string denumire;
        std::cout<<"Introdu denumirea medicamentului: ";
        std::cin>>denumire;

        std::string producator;
        std::cout<<"Introdu producatorul medicamentului: ";
        std::cin>>producator;

        result = farmacie.cauta(denumire, producator);

        if(result == NULL_ENTITY()){
            ok = false;

            std::cout<<"Incerci din nou?(da/nu)\n";
            std::string status;
            std::cin>>status;
            if(status == "nu")
                return;
        }
        
    }

    std::cout<<"Denumire: "<<result.denumire<<'\n'<<"Pret: "<<result.pret<<'\n'<<"Producator: "<<result.producator<<'\n'<<"Substanta activa: "<<result.substanta_activa<<'\n';
}

void app_ui::afisare(){
    pair<IT, IT> res = farmacie.all();
    for(;res.first!=res.second;++res.first){
        entity result = *res.first;
        std::cout<<"Denumire: "<<result.denumire<<'\n'<<"Pret: "<<result.pret<<'\n'<<"Producator: "<<result.producator<<'\n'<<"Substanta activa: "<<result.substanta_activa<<'\n';
        std::cout<<'\n';
    }
}

void app_ui::close(){
    exit(0);
}

void app_ui::run()
{

    while(true){
        // int k = 1;
        std::cout<<"1.Adaugare\n"<<"2.Afisare\n"<<"3.Stergere\n"<<"4.Modificare\n"<<"5.Cautare\n"<<"6.Iesire\n";

        std::cout<<"\nAlege o comanda: ";

        int input;
        std::cin>>input;

        switch(input){
            case 1:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                adauga();
                std::cout<<"-----------------------------\n";
                break;
            case 2:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                afisare();
                std::cout<<"-----------------------------\n";
                break;
            case 3:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                sterge();
                std::cout<<"-----------------------------\n";
                break;
            
            case 4:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                modifica();
                std::cout<<"-----------------------------\n";
                break;
            
            case 5:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                cauta();
                std::cout<<"-----------------------------\n";
                break;
            
            case 6:
                std::cout<<'\n';
                std::cout<<"-----------------------------\n";
                close();
                std::cout<<"-----------------------------\n";
                break;
        }
        

    }
}


app_ui::~app_ui(){

}