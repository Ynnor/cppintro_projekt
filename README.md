# cppintro_projekt
## Laborationsdata
Robin Jönsson, rojn1700
Laboration 5, Introduktion till programmering i C++
Visual studio code och g++ med -Wall -Wextra -Werror – Wpedantic – Wconversion och 
-std=c++11
## Filer
AddPerson.cpp, clear.cpp, deletePerson.cpp, encrypt.cpp, find.cpp, loadList.cpp, main.cpp, print.cpp, saveList.cpp, sort.cpp och constants.h.Constants.h innehåller förrutom konstanter även Person structen och deklarering av alla funktioner.
## Slutsatser och kommentarer
I uppgiften så stod det att man skulle läsa igenom hela pdf:en först, innan man startade med koden. Jag var lite ivrig, och hade lite svårt att faktiskt läsa igenom alla specifikationer, och kollade istället bara lite snabbt vad programmet skulle göra, och skrev sedan huvudprogrammet direkt. Jag förde också en bättre versionshantering, med 13 commits av projektet, så att jag lätt kunde återgå till en tidigare version om det behövdes men också för att hjälpa mig hålla koll på vad jag gjorde. När jag skrivit huvudprogrammet och gjort program-loopen, så stegade jag därefter igenom alla alternativen, och löste varje funktion en åt gången. Inga halvfärdiga funktioner, utan fungerande funktioner (många blev dock ändrade innan projektet var färdigt, ibland helt och hållet) innan jag begav mig till nästa funktionsimplementering. <br />
Någonstans mot slutet av projektet stötte jag på lite problem. Eftersom jag skriver i visual studio code, och är helt novis på C++, så har jag inte haft någon Makefile. Min main.cpp hade includes till ALLA .cpp filer överst, något som visst inte skulle behövas, och jag började därför läsa på om Makefiles. Jag hade visserligen kunnat gå över och lägga programmet i Visual Studio 2017, och vara nöjd med det, men jag är envis, kommer från en Webb-bakgrund, och gör lite drygt hälften av mitt kodande i Linux, så jag skulle minsann fixa en Makefile och få det att fungera, sista veckan innan inlämning.<br />
I tidiga versioner så var output hemskt formatterad, jag ville bara implementera alla funktioner, och fixa formatteringen senare. Efter varje implementerad funktion, så debuggade jag och kontrollerade att allt fungerade som det skulle. När alla funktioner var implementerade, körde jag åter debugging och kontrollerade att allt samverkade som det skulle. I princip sist av allt fixade jag formattering av output.
