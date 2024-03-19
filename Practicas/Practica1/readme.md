# **_Practica 1_**: _Variables compartidas._

## **_Ejercicios de la practica_**

**1.** Para el siguiente programa concurrente suponga que todas las variables están inicializadas en 0 antes de empezar. Indique cual/es de las siguientes opciones son verdaderas:

**a)** En algún caso el valor de x al terminar el programa es 56.

**b)** En algún caso el valor de x al terminar el programa es 22.

**c)** En algún caso el valor de x al terminar el programa es 23.

```C
P1::
If (x = 0) then
    y:= 4*2;
    x:= y + 2;
```

```C
P2::
    If (x > 0) then
    x:= x + 1;
```

```C
P3::
x:= (x*3) + (x*2) + 1;
```

**a.**

**2.** Realice una solución concurrente de grano grueso (utilizando `<>` y/o `<await B; S>`) para el siguiente problema. Dado un numero N verifique cuantas veces aparece ese número en un arreglo de longitud M. Escriba las condiciones que considere necesarias.

**3.** Realice una solución concurrente de grano grueso (utilizando `<>` y/o `<await B; S>`) para el
siguiente problema. Un sistema operativo mantiene 5 instancias de un recurso almacenadas en una cola, cuando un proceso necesita usar una instancia del recurso la saca de la cola, la usa y cuando termina de usarla la vuelve a depositar.

**4.** En cada ítem debe realizar una solución concurrente de grano grueso (utilizando `<>` y/o `<await B; S>`) para el siguiente problema, teniendo en cuenta las condiciones indicadas en el item. Existen N personas que deben imprimir un trabajo cada una.

**a)** Implemente una solución suponiendo que existe una única impresora compartida por todas las personas, y las mismas la deben usar de a una persona a la vez, sin importar el
orden. Existe una función Imprimir(documento) llamada por la persona que simula el uso de la impresora. Sólo se deben usar los procesos que representan a las Personas.

**b)** Modifique la solución de (a) para el caso en que se deba respetar el orden de llegada.

**c)** Modifique la solución de (b) para el caso en que se deba respetar el orden de llegada pero dando prioridad de acuerdo a la edad de cada persona (cuando la impresora está libre la debe usar la persona de mayor edad entre las que hayan solicitado su uso).

**d)** Modifique la solución de (a) para el caso en que se deba respetar estrictamente el orden dado por el identificador del proceso (la persona X no puede usar la impresora hasta que no haya terminado de usarla la persona X-1).

**e)** Modifique la solución de (c) para el caso en que además hay un proceso Coordinador que le indica a cada persona cuando puede usar la impresora.

**5.** Resolver con SENTENCIAS AWAIT (utilizando `<>` y/o `<await B; S>`) el siguiente problema. En un examen final hay P alumnos y 3 profesores. Cuando todos los alumnos han llegado comienza el examen. Cada alumno resuelve su examen, lo entrega y espera a que alguno de los profesores lo corrija y le indique la nota. Los profesores corrigen los exámenes respectando el orden en que los alumnos van entregando.

**6.** Dada la siguiente solución para el Problema de la Sección Crítica entre dos procesos (suponiendo que tanto SC como SNC son segmentos de código finitos, es decir que terminan en algún momento), indicar si cumple con las 4 condiciones requeridas:

```C
int turno = 1;
Process SC1::
{   while (true)
    { while (turno == 2) skip;
        SC;
        turno = 2;
        SNC;
    }
}

Process SC2::
{   while (true)
    {  while (turno == 1) skip;
        SC;
        turno = 1;
        SNC;
    }
}
```

**7.** Desarrolle una solución de grano fino usando sólo variables compartidas (no se puede usar las sentencias await ni funciones especiales como `TS` o `FA`). En base a lo visto en la clase 2 de teoría, resuelva el problema de acceso a sección crítica usando un proceso coordinador. En este caso, cuando un proceso SC[i] quiere entrar a su sección crítica le avisa al coordinador, y espera a que éste le dé permiso. Al terminar de ejecutar su sección crítica, el proceso SC[i] le avisa al coordinador.

> **Nota:** puede basarse en la solución para implementar barreras con Flags y Coordinador vista en la teoría 3.

---
