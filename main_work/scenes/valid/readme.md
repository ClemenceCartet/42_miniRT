## Liste des scènes valides

- Rappel : Les scènes valides doivent respecter plusieurs critères :
	- Avoir :
		- Seulement une Lumière Ambiante `A`
		- Seulement une Camera `C`
		- Seulement une Lumière `L`
		- Au moins un objet `sp` ou `pl` ou `cy`
	- Que chaque élément soit donné sur une ligne différente, qu'importe l'ordre
	- Que les paramètres donnés pour chaque élément soient présents
	- Que les paramètres donnés pour chaque élément soient dans le bon ordre
	- Que les paramètres donnés pour chaque élément soient valides
	- Que les paramètres donnés pour chaque éléments soient séparés par au moins un espace
	- Qu'il n'y ai pas de caractère non demandé

1. A C L sp pl cy
2. A L C sp pl cy
3. C A L sp pl cy
4. C L A sp pl cy
5. L A C sp pl cy
6. L C A sp pl cy

7. A C L sp cy pl
8. A C L cy sp pl
9. A C L cy pl sp
10. A C L pl cy sp
11. A C L pl sp cy

12. A C L sp
13. A C L pl
14. A C L cy

15. A C L sp sp sp
16. A C L pl pl pl
17. A C L cy cy cy

18. sp pl cy A C L
19. sp A pl cy C L
20. sp A pl C cy L