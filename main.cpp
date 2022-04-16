#include "tests/test.h"
#include "ui/ui.h"

int main(){
    cout<<"Run tests? (y/n): ";
    string ans;
    cin>>ans;
    cout<<'\n';
    if(ans == "y")
        run_tests();

    console app;
    app.run();
    
    return 0;
}