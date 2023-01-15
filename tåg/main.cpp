#include <iostream>

using namespace std;

int main()
{

    int capacity,amountStations,left,gotOn,stay;
                                                                    // skapar variabler och fr�gar hur m�nga m�nniskor som f�r vara p� t�get.
    cout << "Ange vad t�gets totala kapacitet �r 1-40: ";
    cin >> capacity;                                              // om anv�ndaren anger ett antal l�gre �n 1 eller h�gre �n 40 s� kommer ett felmeddelande
    while(capacity < 1 || capacity > 40)                          // och anv�ndaren f�r skriva in ett nummer igen.
    {
        cin.clear();
        cin.ignore(123,'\n');
        cout << "Felaktig inmatning, ange ett nummer mellan 1 och 40: ";   // cinclear tar bort felflaggning om man anger n�got som inte �r ett heltal
        cin >> capacity;                                                   // cinignore ignorerar 123 felaktiga tecken f�r att se till att man inte r�kar
    }                                                                      // skriva in felaktig information och \n f�r att ignorera allt p� den raden.

    cout << "Ange antalet stationer som t�get stannar p� 2-10: ";
    cin >> amountStations;                                                // samma som ovan fast med ett nummer mellan 2 och 10 f�r antalet stationer.
    while(amountStations < 2 || amountStations > 10)
    {
        cin.clear();
        cin.ignore(123,'\n');
        cout << "Felaktig inmatning, ange ett nummer mellan 2 och 10: ";
        cin >> amountStations;
    }

    int currentStation = amountStations;        // jag skapar en variabel f�r att h�lla koll p� vilken station t�get �r p� s� att while loopen slutar n�r
    int passengers = 0;                         // t�get har kommit till sista stationen. jag skapar en variabel f�r att h�lla koll p� antalet passagerare
    bool impossible;                            // p� t�get och anger v�rdet 0 f�r n�sta if sats. jag skapar en bool variabel f�r att en utmatning ska ske
                                                // efter while loopen, utmatningen anger om inmatningarna �r m�jliga.
    while(currentStation > 0)
    {
        cout << "\nH�llplats " << amountStations - currentStation + 1 << "\nHur m�nga stiger av t�get: "; // while loopen avslutas p� sista stationen
        cin >> left;
        if(left > passengers && !impossible || currentStation < 2 && left != passengers && !impossible)    // amountstations-currentstation+1 anger nuvarande station.
        {                                                                    // om antalet som l�mnar t�get �r h�gre �n antalet passagerare eller om
            impossible = true;                                               // t�get �r vid den sista stationen och antalet som l�mnar t�get inte �r lika
            cout << "\nOm�jligt\n\n";                                        // med antalet passagerare s� skickas ett meddelande ut och om�jligt flaggas.
        }

        cout << "Hur m�nga stiger p� t�get: ";
        cin >> gotOn;
        if(gotOn > capacity && !impossible || passengers - left + gotOn > capacity & !impossible || currentStation < 2 && gotOn != 0 && !impossible)
        {
            impossible = true;                                      // om antalet som stiger p� t�get �r h�gre �n kapaciteten eller om antalet passagerare
            cout << "\nOm�jligt\n\n";                               // minus antalet som stiger av plus antalet som stiger p� �r h�gre �n kapaciteten
        }                                                           // eller om det �r sista stationen och antalet passagerare som stiger p� inte �r 0,
                                                                    // s� kommer om�jligt meddelande och om�jligt flaggas.
        cout << "Hur m�nga stannar p� plattformen: ";
        cin >> stay;
        if(stay > capacity && !impossible || currentStation < 2 && stay != 0 && !impossible)      // om det �r mer som stannar p� plattformen eller det �r slutstation och n�gon stannar
        {                                                           // p� plattformen s� kommer ett felmeddelande och om�jligt flaggas.
            impossible = true;
            cout << "\nOm�jligt\n\n";
        }

        passengers = passengers-left+gotOn;                       // passengers f�r sitt nya v�rde och -1 p� current station s� att loopen avslutas
        currentStation--;                                         // n�r man har �kt f�rbi alla stationerna.
    }

    if(impossible || passengers != 0 || stay != 0)
    {                                                                           // om impossible har flaggats eller om antalet passagerare inte �r 0
        cout << "\nInmatning �r om�jlig, covidrestriktionerna har inte f�ljts.\n";  // eller om antalet som stannar p� plattformen inte �r noll s� kommer ett
    }                                                                           // meddelande om att inmatning �r om�jlig.
    else
    {
        cout << "\nInmatningen �r m�jlig, covidrestriktionerna har f�ljts.\n";  // om allt st�mmer s� kommer ett meddelande om att alla restriktioner
    }                                                                          // har f�ljts.

return 0;
}

// Programmet ska allts� ta in hur m�nga som f�r platts p� t�get och plattformen och hur m�nga stationer som t�get �ker f�rbi. Det ska kolla om anv�ndarens
// inmatningar �r rimliga och om de inte �r det ska ett felmeddelande skickas ut och anv�ndaren f�r m�jligheten att ange relevant information.
// Programmet anv�nder sig sedan av en while funktion f�r att g� igenom antalet passagerare som stiger av, stiger p� och som stannar p� plattformen p�
// varje station. Inom while funktionen finns if funktioner som kontrollerar att anv�ndarens inmatningar �r rimliga. Om informationen inte �r rimlig s�
// skickas ett om�jligt meddelande ut och programmet markerar att det �r om�jligt f�r att sedan mata ut n�r t�get har kommit till sista stationen.
// N�r t�get har kommit till den sista stationen avslutas while loopen och en utmatning sker f�r att informera anv�ndaren om alla riktlinjer har blivit
// f�ljda eller inte. Programmet avslutas.




