# Projekt 1 - Ověřování síly hesel (práce s textem)


## Popis projektu
Cílem projektu je vytvořit program, který na vstupu dostane sadu hesel a pro každé z nich ověří, jestli heslo splňuje všechna (pevně zadaná) požadovaná pravidla. Ta hesla, která projdou kontrolou, budou vypisována na výstup, ostatní budou zahozena.

## Detailní specifikace
Program implementujte ve zdrojovém souboru "pwcheck.c". Vstupní data (seznam hesel) budou čtena ze standardního vstupu (stdin), výstup (filtrovaný seznam hesel) bude tisknut na standardní výstup (stdout).

## Překlad zdrojového souboru:

`gcc -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck `

## Syntax spuštění
Program se spouští v následující podobě: (./pwcheck značí umístění a název programu):
`./pwcheck LEVEL PARAM [--stats]`

Program je spouštěn se dvěma pevně zadanými argumenty LEVEL a PARAM a s jedním volitelným argumentem --stats, případně zadaným na třetí pozici:
| Příkaz | Popis |
| --- | --- |
| `LEVEL` | Celé číslo v intervalu [1, 4], které určuje požadovanou úroveň bezpečnosti (viz níže). |
| `PARAM` | Kladné celé číslo, které určuje dodatečný parametr pravidel (viz níže). |
| `--stats` | Pokud je zadané, určuje, zda se na konci programu mají vypsat souhrnné statistiky analyzovaných hesel. |

## Úrovně bezpečnosti (kontrolovaná pravidla)

Jsou definovány celkem 4 úrovně bezpečnosti vyjádřeny pomocí 4 pravidel. Úroveň bezpečnosti určuje, že hesla musí splňovat všechna pravidla na dané a nižší úrovni. Tzn. např. úroveň bezpečnosti 3 specifikuje, že hesla musí splňovat pravidla 1, 2 a 3.

Některá pravidla jsou parametrizovatelná celým číslem zadaným pomocí argumentu programu PARAM. V následujícím seznamu je tento parametr označen jako X.

## Seznam pravidel:

1. Heslo obsahuje alespoň 1 velké a 1 malé písmeno.
2. Heslo obsahuje znaky z alespoň X skupin (v případě, že je číslo X větší než 4, myslí se tím všechny skupiny). Uvažované skupiny jsou:
    - malá písmena (a-z)
    - velká písmena (A-Z)
    - čísla (0-9)
    - speciální znaky (podporované musí být alespoň nealfanumerické znaky z ASCII tabulky na pozicích 32-126, tedy včetně mezery)
3. Heslo neobsahuje sekvenci stejných znaků délky alespoň X.
4. Heslo neobsahuje dva stejné podřetězce délky alespoň X.

## Statistiky

Pokud je zadaný argument programu --stats, program musí na konec výstupu vypsat celkové statistiky ve formátu:
```
Statistika:
Ruznych znaku: NCHARS
Minimalni delka: MIN
Prumerna delka: AVG
```
kde NCHARS je *počet různých znaků* vyskytujících se napříč všemi hesly, MIN je *délka nejkratšího hesla* (resp. hesel) a AVG je *průměrná délka hesla* (aritmetický průměr) zaokrouhlená na 1 desetiné místo. Statistiky zahrňují i hesla, která byla zahozena.

## Implementační detaily

### Vstupní data (seznam hesel)

Seznam hesel je programu předán na standardním vstupu (stdin). Každé heslo je zadáno na samostatném řádku a obsahuje pouze ASCII textová data, kromě znaku nového řádku. Maximální délka hesla je 100 znaků, jinak se jedná o nevalidní data. Program musí podporovat neomezený počet hesel na vstupu.

### Výstup programu

Program na standardní výstup (stdout) vypisuje hesla ze vstupního seznamu, každé na samostatný řádek, která splňují požadovanou úroveň bezpečnosti zadanou jako argument programu LEVEL. Hesla musí být vypsána beze změny a ve stejném pořadí, v jakém se objevila na vstupu.

Za výstupním seznamem hesel pak program volitelně vypisuje statistiku.
