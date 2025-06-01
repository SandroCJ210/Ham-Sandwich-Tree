# Ham Sandwich Problem

## Alumnos:
- [Oscar Torres Minaya](https://github.com/MrElmo3)
- [Sandro Carrillo](https://github.com/SandroCJ210)

## Resumen
Este es un proyecto para ejemplificar el uso del Ham Sandwich Tree, se encuentra dividido en 2 partes;
una parte para el análisis del algoritmo dentro de la carpeta **Profiling** 
y una segunda parte que compete al resto de carpetas para la representación visual usando como base 
el [Motor Gráfico Amaru](https://github.com/MrElmo3/AmaruEngine)

Se escogió el algoritmo principalmente por lo visible que puede llegar a ser al implementarse en un motor gráfico como el selecionado y por su similitud con los K-D trees los cuales son de interés para los involucrados.

## Compilación

### Parte gráfica

**Linux**

Se ejecuta los siguientes comandos

```zsh
$ cmake -S . -B "build" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
$ cmake --build "build"
```

luego de ello el ejecutable se encontrará dentro de la carpeta /build

**Windows**

En el caso de Windows se necesitará ejecutarse desde *Clion* o en su defecto 
instalar *Visual Studio Build Tools* y el plugin de *Cmake* para *Visual Studio Code*

Luego desde el respectivo IDE o editor de texto se podrá ejecutar.

### Profiling

Para ejecutar la parte de profiling solo necesita ejecutar el archivo *HSTProfile.py* tanto desde Windows como desde Linux. Dicho archivo se encuentra en la carpeta /Profiling

Los resultados del Profiling se podrán encontrar dentro de la carpeta /data

## Organización del proyecto

- /Profiling -> archivos de python para realizar el Profiling
- /src -> código de C++ para la parte gráfica
	- Las siguientes rutas son identicas tanto para la carpeta /private como para la carpeta /public
	conteniendo respectivamente implementaciones y declaraciones.
	- /Core -> Lógica fundamental del motor Amaru
	- /Game -> Código de la escena ejecutada
		- /Components -> Componentes específicos usados
		(Aqui se encuentra el código del HSTree dentro de HSTreeComponent.h/cpp)
		- /Objects -> Objetos que usan los componentes de /Components y se instancian en la escena.
		- /Scenes -> Escenas utilizadas en la parte gráfica
	- /Util -> Utilidades usadas dentro del motor

**Notas sobre algunos archivos**

Dentro de los archivos HSTreeComponent.cpp y HamSandwichTreeSceneScene.cpp existen notas sobre datos puntuales que se pueden cambiar para obtener distintos resultados

## API

### HSTNode 

Representa un nodo del Ham Sandwich Tree

**Atributos**

* root: Es una referencia al nodo raíz del árbol.
* height: Es la profundidad del nodo dentro del árbol.
* points: Es una lista de puntos que contiene el nodo.
* medianProj: Es el valor escalar de la proyección del punto mediano en la dirección del corte.
* direction: Es el vector de dirección en el que se basa la línea que bisecta los puntos.
* medianPoint: Es el punto correspondiente a la mediana proyectada.
* parent: Una referencia al nodo padre (si es que existe).
* left: Una referencia al hijo izquierdo (si es que existe).
* right: Una referencia al hijo derecho (si es que existe).

### HamSandwichTree

Es la implementación del árbol en 2D o 3D. Este árbol bisecta recursivamente (en 2D o 3D) puntos.

**Atributos**
* is3D: Booleano que indica si la implementación es en 3D.
* quantity: Esta variable indica la cantidad de puntos en el plano.
* boundary: Esta variable indica un límite espacial sobre el cual se generarán los puntos.
* points: Son los puntos del plano a usar.
* root: Es una referencia a la raíz del árbol.

**Funciones**
* Constructor: Inicializa el árbol con los parámetros dados y ejecuta estar para iniciar la construcción.
	* Parámetros:
		* is3D: Booleano que indica si la implementación es en 3D.
		* quantity: Esta variable indica la cantidad de puntos en el plano.
		* boundary: Esta variable indica un límite espacial sobre el cual se generarán los puntos.
* Start: En este método se inicia la construcción del árbol, primero se generan puntos aleatorios con los parámetros obtenidos y a partir de esto se construye.
* CreateTree: Inicializa el nodo raíz del árbol con todos los puntos generados y llama al proceso para construir el árbol completo.
* CreateTreeAux: 
