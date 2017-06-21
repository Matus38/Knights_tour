# Knights_tour
Knight's tour - depth first search solution

Úlohou je prejsť šachovnicu legálnymi ťahmi šachového koňa tak, aby každé políčko
šachovnice bolo prejdené (navštívené) práve raz. 

Algoritmom slepého prehľadávania (do hĺbky) je možné nájsť (všetky) riešenia (v
bežných výpočtových – čas a pamäť – podmienkach PC) iba pri šachovniciach do
veľkosti 6x6, max 7x7. Implementujte tento algoritmus pre šachovnice s rozmermi
5x5 a 6x6 a skúste nájsť prvých 5 riešení pre každú šachovnicu tak, že pre
šachovnicu 5x5 aj 6x6 si vyberte náhodne 5 východzích bodov (spolu teda 10
východzích bodov) s tým, že jeden z týchto bodov je (pre každú šachovnicu) ľavý
dolný roh a pre každý z týchto bodov nájdite (skúste nájsť) prvé riešenie. V prípade,
že ho v stanovenom limite nenájdete, signalizujte neúspešné hľadanie.
