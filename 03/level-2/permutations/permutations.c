/* ALGORITMO DE STEINHAUS-JOHNSON-TROTTER

Este algoritmo genera todas las permutaciones de n! elementos.

Reglas del algoritmo:

1 - Cada valor de nuestro conjunto recibe una direccion de movilidad.
	Es decir, a medida que intercambiamos el valor, también tiene una direcc en la que se intercambia.

1) Puede intercambiar con el vecino a la izquierda o derecha inmediata (determinado por su movilidad). 
Ahora bien, si un valor está en el extremo izquierdo y tiene movilidad hacia la izquierda, se considera inmóvil.
Lo mismo con si está en el extremo derecho y tiene derecho a la movilidad. 
Para empezar, todos los valores han dejado movilidad.

2) El intercambio solo tendrá lugar si el vecino al lado (en la dirección de su movilidad) es menor que el valor que se intercambia.
De lo contrario, también se considera bloqueado.

Ej: si 3 y 2 están uno al lado del otro y ambos se mueven hacia la izquierda, no se realiza ningún intercambio hacia la izquierda porque 3 es mayor que 2.
Actualmente, 2 está bloqueado en su lugar. Pero si hubiese sido 1 y 4, entonces 4 se intercambiará. 3) Se realiza un intercambio en cada pase. 
Todos los valores en el conjunto que son de un valor más alto que el valor intercambiado tendrán su dirección de movilidad cambiada a la otra dirección.
*/


/* Teoría:
Para un cojunto de n elementos, el numero de permutaciones posibles es de n!
Ejemplo: n = 3 elementos -> 3! = 6 ordenaciones diferentes posibles:
Conjunto = 	{a, b, c}
Permutaciones:
{a, b, c}
{a, c, b}
{b, a, c}
{b, c, a}
{c, a, b}
{c, b, a}
*/

/*
Posible planteamiento:



*/