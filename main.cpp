#include "tests/entity_tests.h"
#include "tests/repository_tests.h"
#include "tests/service_tests.h"
#include "ui/ui.h"

int main(){
    
    entity_tests runner1;
    repository_tests runner2;
    service_tests runner3;
    runner1.run();
    runner2.run();
    runner3.run();
    entity a;
    a.denumire = "asdf";
    
    entity b(a);

    std::cout<<b.denumire;
    app_ui app;

    app.run();

    return 0;
}