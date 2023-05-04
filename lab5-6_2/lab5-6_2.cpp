#include "Header.h"

int main()
{
    Prophylaxis* prophylaxis = new Prophylaxis();
    cout << "Name: " << prophylaxis->GetName() << "\nDuration: " << prophylaxis->GetDuration() << endl;

    cout << "\n";

    DrugTreatment* drugTreatment = new DrugTreatment();
    cout << "Name: " << drugTreatment->GetName() << "\nDuration: " << drugTreatment->GetDuration() << endl;

    cout << "\n";

    //Задекорирование объекта Госпитализация + Медикаментозное лечение
    Hospitalization* hospitalization = new Hospitalization(drugTreatment);
    cout << "Name: " << hospitalization->GetName() << "\nDuration: " << hospitalization->GetDuration() << endl;

    cout << "\n";
    
    //Задекорирование объекта Дневной стационар + Профилактика
    DayHospital* dayHospital = new DayHospital(prophylaxis);
    cout << "Name: " << dayHospital->GetName() << "\nDuration: " << dayHospital->GetDuration() << endl;

    cout << "\n";

    //Задекорирование уже задекорированного объекта Госпитализация + Дневной стационар + Профилактика
    Hospitalization* hospitalization2 = new Hospitalization(dayHospital);
    cout << "Name: " << hospitalization2->GetName() << "\nDuration: " << hospitalization2->GetDuration() << endl;

    delete prophylaxis, drugTreatment;
    delete hospitalization, dayHospital;
    delete hospitalization2;
}
