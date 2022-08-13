## Liste des scènes contenant des erreurs

1. empty file
2. A missing
3. C missing
4. L missing
5. Object missing
6. Newlines only
7. No extension
8. RandomData in Parsing
9. Text in file
10. too much A
11. too much C
12. too much L
13. unknown ID
14. wrong extension
15. wrong order A values
16. wrong order C values
17. wrong order L values
18. wrong order CY values
19. wrong order PL values
20. wrong order SP values

**////////////////////////////////////////////////////////////**

ACLO existing, error cases per value type :

Ratio
1. charset (float)
2. Out of range < 0
3. Out of range > 1
4. Overflow int max
5. Overflow int min
6. Float syntax (double point)
7. Number syntax (multiple -)
8. Number syntax (multiple +)
9. Number syntax (multiple symbols)
10. Number syntax (symbols everywhere)

DIAMETER / HEIGHT
1. charset (float)
2. Out of range < 0
3. Overflow int max
4. Overflow int min
5. Float syntax (double point)
6. Number syntax (multiple -)
7. Number syntax (multiple +)
8. Number syntax (multiple symbols)
9. Number syntax (symbols everywhere)

FOV
1. charset (int)
2. Out of range < 0
3. Out of range > 180
4. Overflow int max
5. Overflow int min
6. Number syntax (multiple -)
7. Number syntax (multiple +)
8. Number syntax (multiple symbols)
9. Number syntax (symbols everywhere)

RGB
0. number of ',' (!= 2)

for each value (x3)
1. missing
2. charset (int)
3. out of range < 0
4. out of range > 255
5. overflow int max
6. overflow int min
7. Number syntax (multiple -)
8. Number syntax (multiple +)
9. Number syntax (multiple symbols)
10. Number syntax (symbols everywhere)

POS
0. number of ',' (!= 2)

for each value (x3)
1. missing
2. charset (float)
3. overflow int max
4. overflow int min
5. Float syntax (double point)
6. Number syntax (multiple -)
7. Number syntax (multiple +)
8. Number syntax (multiple symbols)
9. Number syntax (symbols everywhere)


DIR
0. number of ',' (!= 2)

for each value (x3)
1. missing
2. charset (float)
3. out of range < -1
4. out of range > 1
5. overflow int max
6. overflow int min
7. Float syntax (double point)
8. Number syntax (multiple -)
9. Number syntax (multiple +)
10. Number syntax (multiple symbols)
11. Number syntax (symbols everywhere)

---------------------------------------

Global
	Check charset
	Check Overflow (int max, int min)

Float
	isnan
	isinf

Coords
	Check ','	= 2
	Splitlen	= 3

Colors
	Check ','	= 2
	Splitlen	= 3

ratio
	float	ratio
		range 0.0 / 1.0

rgb
	int		r
		range 0 / 255
	int		g
		range 0 / 255
	int		b
		range 0 / 255

pos
	float	x
	float	y
	float	z

dir
	float	x
		range -1 / 1
	float	y
		range -1 / 1
	float	z
		range -1 / 1

fov
	int		fov
		range 0 / 180
		conversion into float	radian

diameter
	float	diameter
		range positive

height
	float	height
		range positive

-------------------------------

A
	ratio
	rgb

C
	pos
	dir
	fov

L
	pos
	ratio
	rgb

SP
	pos
	diameter
	rgb

PL
	pos
	dir
	rgb

CY
	pos
	dir
	diameter
	height
	rgb

--------------
Fonctions

rt_check_range(float value, float min, float max)
	Check range including values given after atoi / atof

rt_check_charset(char *value, char *charset)
	Check charset of any value before atoi / atof

rt_check_overflow(char *value)
	Check overflow of any value before atoi / atof

rt_check_struct(char *values)
	Check Comma number
	Check Splitlen
