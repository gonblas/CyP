# **_Practica 2_**: _Semáforos._

## **_Consideraciones para resolver los ejercicios:_**

- Los semáforos deben estar declarados en todos los ejercicios.

- Los semáforos deben estar inicializados en todos los ejercicios.

- No se puede utilizar ninguna sentencia para setear o ver el valor de un semáforo.

- Debe evitarse hacer busy waiting en todos los ejercicios.

- En todos los ejercicios el tiempo debe representarse con la función delay.

## **_Ejercicios de la practica_**

**1.** Un sistema operativo mantiene 5 instancias de un recurso almacenadas en una cola, cuando
un proceso necesita usar una instancia del recurso la saca de la cola, la usa y cuando termina de usarla la vuelve a depositar.

**2.** A una cerealera van T camiones a descargarse trigo y M camiones a descargar maíz. Sólo hay lugar para que 7 camiones a la vez descarguen pero no pueden ser más de 5 del mismo tipo de cereal.

> **Nota:** sólo se pueden usar procesos que representen a los camiones.

**3.** Se tiene un curso con 40 alumnos, la maestra entrega una tarea distinta a cada alumno, luego cada alumno realiza su tarea y se la entrega a la maestra para que la corrija, esta revisa la tarea y si está bien le avisa al alumno que puede irse, si la tarea está mal le indica los errores, el alumno corregirá esos errores y volverá a entregarle la tarea a la maestra para que realice la corrección nuevamente, esto se repite hasta que la tarea no tenga errores.

**4.** Existen N personas que deben fotocopiar un documento cada una. Resolver cada ítem usando semáforos:

**a)** Implemente una solución suponiendo que existe una única fotocopiadora compartida
por todas las personas, y las mismas la deben usar de a una persona a la vez, sin importar
el orden. Existe una función _Fotocopiar()_ llamada por la persona que simula el uso de la
fotocopiadora. Sólo se deben usar los procesos que representan a las _Personas_.

**b)** Modifique la solución de (a) para el caso en que se deba respetar el orden de llegada.

**c)** Modifique la solución de (b) para el caso en que se deba dar prioridad de acuerdo a la
edad de cada persona (cuando la fotocopiadora está libre la debe usar la persona de mayor
edad entre las que estén esperando para usarla).

**d)** Modifique la solución de (a) para el caso en que se deba respetar estrictamente el orden
dado por el identificador del proceso (la persona X no puede usar la fotocopiadora hasta que no haya terminado de usarla la persona X-1).

**e)** Modifique la solución de (b) para el caso en que además haya un _Empleado_ que le indica
a cada persona cuando debe usar la fotocopiadora.

**f)** Modificar la solución (e) para el caso en que sean 10 fotocopiadoras. El _empleado_ le indica a la persona cuando puede usar una fotocopiadora, y cual debe usar.

**5.** Se debe simular una maratón con **C corredores** donde en la llegada hay UNA máquinas
expendedoras de agua con capacidad para 20 botellas. Además existe **un repositor** encargado
de reponer las botellas de la máquina. Cuando los C corredores han llegado al inicio comienza
la carrera. Cuando un corredor termina la carrera se dirigen a la máquina expendedora, espera
su turno (respetando el orden de llegada), saca una botella y se retira. Si encuentra la máquina
sin botellas, le avisa al repositor para que cargue nuevamente la máquina con 20 botellas; espera a que se haga la recarga; saca una botella y se retira.

> **Nota:** maximizar la concurrencia; mientras se reponen las botellas se debe permitir que otros corredores se encolen.

**6.** Una empresa de turismo posee **4 combis** con capacidad para 25 personas cada una y **UN
vendedor** que vende los pasajes a los clientes de acuerdo al orden de llegada. Hay **C clientes**
que al llegar intentan comprar un pasaje para una combi en particular (el cliente conoce este
dato); si aún hay lugar en la combi seleccionada se le da el pasaje y se dirige hacia la combi;
en caso contrario se retira. Cada combi espera a que suban los 25 pasajeros, luego realiza el
viaje, y cuando llega al destino deja bajar a todos los pasajeros.

> **Nota:** maximizar la concurrencia; suponga que para cada combi al menos 25 clientes intentarán comprar pasaje.

**7.** En una herrería hay 15 **empleados** que forman 5 grupos de 3 personas; los grupos se formande acuerdo al orden de llegada (los 3 primeros pertenecen al grupo 1, los 3 siguientes al grupo 2, y así sucesivamente). Ni bien conoce el grupo al que pertenece el empleado comienza a
trabajar (no debe esperar al resto de grupo para comenzar). Cada grupo debe hacer exactamente P unidades de un producto (cada unidad es hecha por un único empleado). Al terminar de hacer las P unidades de un grupo, sus 3 empleados se retiran. 

> **Nota:** maximizar la concurrencia; ningún grupo puede hacer unidades de más.


---
