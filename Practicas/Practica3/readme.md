# **_Practica 3_**: _Monitores._

## **_Consideraciones para resolver los ejercicios:_**

- Los monitores utilizan el protocolo **signal and continue**.
- A una variable **condition** SÓLO pueden aplicársele las operaciones SIGNAL,
  SIGNALALL y WAIT.
- NO puede utilizarse el **wait con prioridades**.
- NO se puede utilizar ninguna operación que determine la cantidad de procesos encolados en una variable **condition** o si está vacía.
- La única forma de comunicar datos entre monitores o entre un proceso y un monitor es por medio de invocaciones al procedimiento del monitor del cual se quieren obtener (o enviar) los datos.
- No existen variables globales.
- En todos los ejercicios debe maximizarse la concurrencia.
- En todos los ejercicios debe aprovecharse al máximo la característica de exclusión mutua que brindan los monitores.
- Debe evitarse hacer **busy waiting**.
- En todos los ejercicios el tiempo debe representarse con la función **delay**.

## **_Ejercicios de la practica_**

**1.** Implementar el acceso a una base de datos de solo lectura que puede atender a lo sumo 5
consultas simultáneas.

**2.** Existen N personas que deben fotocopiar un documento cada una. Resolver cada ítem
usando monitores:

**a)** Implemente una solución suponiendo que existe una única fotocopiadora compartida
por todas las personas, y las mismas la deben usar de a una persona a la vez, sin
importar el orden. Existe una función _Fotocopiar()_ que simula el uso de la fotocopiadora.
Sólo se deben usar los procesos que representan a las _Personas_ (y los monitores que sean
necesarios).

**b)** Modifique la solución de (a) para el caso en que se deba respetar el orden de llegada.

**c)** Modifique la solución de (b) para el caso en que se deba dar prioridad de acuerdo a la
edad de cada persona (cuando la fotocopiadora está libre la debe usar la persona de mayor edad entre las que estén esperando para usarla).

**d)** Modifique la solución de (a) para el caso en que se deba respetar estrictamente el orden
dado por el identificador del proceso (la persona X no puede usar la fotocopiadora hasta que no haya terminado de usarla la persona X-1).

**e)** Modifique la solución de (b) para el caso en que además haya un _Empleado_ que le indica
a cada persona cuando debe usar la fotocopiadora.

**f)** Modificar la solución (e) para el caso en que sean 10 fotocopiadoras. El _empleado_ le
indica a la persona cuando puede usar una fotocopiadora, y cual debe usar.

**3.** En un corralón de materiales hay un empleado que debe atender a N clientes de acuerdo al orden de llegada. Cuando un cliente es llamado por el empleado para ser atendido, le da una
lista con los productos que comprará, y espera a que el empleado le entregue el comprobante de la compra realizada.

**4.** En una mesa de exámenes hay 3 _profesores_ que les deben tomar un examen oral a 30 _alumnos_
de acuerdo al orden de llegada. Cada examen es tomado por un único profesor. Cuando un
alumno llega, espera a que alguno de los profesores (cualquiera) lo llame y se dirige al
escritorio correspondiente a ese profesor, donde le tomará el examen; al terminar el
profesor le da la nota y el alumno se retira. Cuando un profesor está libre llama al siguiente
alumno.

> **Nota:** todos los procesos deben terminar su ejecución.

**5.** Suponga una comisión con 50 alumnos. Cuando los alumnos llegan forman una fila, una
vez que están los 50 en la fila el jefe de trabajos prácticos les entrega el número de grupo
(número aleatorio del 1 al 25) de tal manera que dos alumnos tendrán el mismo número de
grupo (suponga que el jefe posee una función *DarNumero()* que devuelve en forma aleatoria
un número del 1 al 25, el jefe de trabajos prácticos no guarda el número que le asigna a
cada alumno). Cuando un alumno ha recibido su número de grupo comienza a realizar la
práctica. Al terminar de trabajar, el alumno le avisa al jefe de trabajos prácticos y espera la
nota. El jefe de trabajos prácticos, cuando han llegado los dos alumnos de un grupo les
devuelve a ambos la nota del GRUPO (el primer grupo en terminar tendrá como nota 25, el
segundo 24, y así sucesivamente hasta el último que tendrá nota 1).


**6.** En una playa hay 5 equipos de 4 personas cada uno (en total son 20 personas donde cada
una conoce previamente a que equipo pertenece). Cuando las personas van llegando
esperan con los de su equipo hasta que el mismo esté completo (hayan llegado los 4
integrantes), a partir de ese momento el equipo comienza a jugar. El juego consiste en que
cada integrante del grupo junta 15 monedas de a una en una playa (las monedas pueden ser
de 1, 2 o 5 pesos) y se suman los montos de las 60 monedas conseguidas en el grupo. Al
finalizar cada persona debe conocer el monto total juntado por su grupo. 


> **Nota:** maximizar la concurrencia. Suponga que para simular la búsqueda de una moneda por parte de una persona existe una función *Moneda()* que retorna el valor de la moneda encontrada.



**7.** Se debe simular una maratón con C corredores donde en la llegada hay UNA máquinas
expendedoras de agua con capacidad para 20 botellas. Además existe un repositor
encargado de reponer las botellas de la máquina. Cuando los C corredores han llegado al
inicio comienza la carrera. Cuando un corredor termina la carrera se dirigen a la máquina
expendedora, espera su turno (respetando el orden de llegada), saca una botella y se retira. Si
encuentra la máquina sin botellas, le avisa al repositor para que cargue nuevamente la
máquina con 20 botellas; espera a que se haga la recarga; saca una botella y se retira. 


> **Nota:** maximizar la concurrencia; mientras se reponen las botellas se debe permitir que otros corredores se encolen.

---
