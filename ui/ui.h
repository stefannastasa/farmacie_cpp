#pragma once
#include "../service/service.h"

class app_ui{
    private:
        typedef void (app_ui::*com)();
        service farmacie;
        std::vector<pair<std::string, com> > commands;

        void adauga();
        void sterge();
        void modifica();
        void cauta();
        void afisare();
        void close();
    public:
        app_ui();

        void run();

        ~app_ui();

    
};
