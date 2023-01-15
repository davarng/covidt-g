#include <iostream>

using namespace std;

int main()
{

    int capacity,amountStations,left,gotOn,stay;
                                                                    // skapar variabler och frågar hur många människor som får vara på tåget.
    cout << "Ange vad tågets totala kapacitet är 1-40: ";
    cin >> capacity;                                              // om användaren anger ett antal lägre än 1 eller högre än 40 så kommer ett felmeddelande
    while(capacity < 1 || capacity > 40)                          // och användaren får skriva in ett nummer igen.
    {
        cin.clear();
        cin.ignore(123,'\n');
        cout << "Felaktig inmatning, ange ett nummer mellan 1 och 40: ";   // cinclear tar bort felflaggning om man anger något som inte är ett heltal
        cin >> capacity;                                                   // cinignore ignorerar 123 felaktiga tecken för att se till att man inte råkar
    }                                                                      // skriva in felaktig information och \n för att ignorera allt på den raden.

    cout << "Ange antalet stationer som tåget stannar på 2-10: ";
    cin >> amountStations;                                                // samma som ovan fast med ett nummer mellan 2 och 10 för antalet stationer.
    while(amountStations < 2 || amountStations > 10)
    {
        cin.clear();
        cin.ignore(123,'\n');
        cout << "Felaktig inmatning, ange ett nummer mellan 2 och 10: ";
        cin >> amountStations;
    }

    int currentStation = amountStations;        // jag skapar en variabel för att hålla koll på vilken station tåget är på så att while loopen slutar när
    int passengers = 0;                         // tåget har kommit till sista stationen. jag skapar en variabel för att hålla koll på antalet passagerare
    bool impossible;                            // på tåget och anger värdet 0 för nästa if sats. jag skapar en bool variabel för att en utmatning ska ske
                                                // efter while loopen, utmatningen anger om inmatningarna är möjliga.
    while(currentStation > 0)
    {
        cout << "\nHållplats " << amountStations - currentStation + 1 << "\nHur många stiger av tåget: "; // while loopen avslutas på sista stationen
        cin >> left;
        if(left > passengers && !impossible || currentStation < 2 && left != passengers && !impossible)    // amountstations-currentstation+1 anger nuvarande station.
        {                                                                    // om antalet som lämnar tåget är högre än antalet passagerare eller om
            impossible = true;                                               // tåget är vid den sista stationen och antalet som lämnar tåget inte är lika
            cout << "\nOmöjligt\n\n";                                        // med antalet passagerare så skickas ett meddelande ut och omöjligt flaggas.
        }

        cout << "Hur många stiger på tåget: ";
        cin >> gotOn;
        if(gotOn > capacity && !impossible || passengers - left + gotOn > capacity & !impossible || currentStation < 2 && gotOn != 0 && !impossible)
        {
            impossible = true;                                      // om antalet som stiger på tåget är högre än kapaciteten eller om antalet passagerare
            cout << "\nOmöjligt\n\n";                               // minus antalet som stiger av plus antalet som stiger på är högre än kapaciteten
        }                                                           // eller om det är sista stationen och antalet passagerare som stiger på inte är 0,
                                                                    // så kommer omöjligt meddelande och omöjligt flaggas.
        cout << "Hur många stannar på plattformen: ";
        cin >> stay;
        if(stay > capacity && !impossible || currentStation < 2 && stay != 0 && !impossible)      // om det är mer som stannar på plattformen eller det är slutstation och någon stannar
        {                                                           // på plattformen så kommer ett felmeddelande och omöjligt flaggas.
            impossible = true;
            cout << "\nOmöjligt\n\n";
        }

        passengers = passengers-left+gotOn;                       // passengers får sitt nya värde och -1 på current station så att loopen avslutas
        currentStation--;                                         // när man har åkt förbi alla stationerna.
    }

    if(impossible || passengers != 0 || stay != 0)
    {                                                                           // om impossible har flaggats eller om antalet passagerare inte är 0
        cout << "\nInmatning är omöjlig, covidrestriktionerna har inte följts.\n";  // eller om antalet som stannar på plattformen inte är noll så kommer ett
    }                                                                           // meddelande om att inmatning är omöjlig.
    else
    {
        cout << "\nInmatningen är möjlig, covidrestriktionerna har följts.\n";  // om allt stämmer så kommer ett meddelande om att alla restriktioner
    }                                                                          // har följts.

return 0;
}

// Programmet ska alltså ta in hur många som får platts på tåget och plattformen och hur många stationer som tåget åker förbi. Det ska kolla om användarens
// inmatningar är rimliga och om de inte är det ska ett felmeddelande skickas ut och användaren får möjligheten att ange relevant information.
// Programmet använder sig sedan av en while funktion för att gå igenom antalet passagerare som stiger av, stiger på och som stannar på plattformen på
// varje station. Inom while funktionen finns if funktioner som kontrollerar att användarens inmatningar är rimliga. Om informationen inte är rimlig så
// skickas ett omöjligt meddelande ut och programmet markerar att det är omöjligt för att sedan mata ut när tåget har kommit till sista stationen.
// När tåget har kommit till den sista stationen avslutas while loopen och en utmatning sker för att informera användaren om alla riktlinjer har blivit
// följda eller inte. Programmet avslutas.




