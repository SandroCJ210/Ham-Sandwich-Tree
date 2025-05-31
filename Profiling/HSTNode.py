from typing import List, Optional
import numpy as np

class HSTNode:
	"""
	Representa un nodo en un Ham Sandwich Tree (HST), que almacena un subconjunto de puntos
	del espacio junto con la información de corte usada para dividirlos.

	Atributos:
	----------
	root : Optional[HSTNode]
		Referencia al nodo raíz del árbol (para acceso global si es necesario).
	
	height : int
		Altura del nodo dentro del árbol (profundidad desde la raíz).
	
	points : List[np.ndarray]
		Lista de puntos asignados a este nodo.
	
	medianProj : float
		Valor de la proyección del punto mediano a lo largo de la dirección de corte.
		(Se debe asignar externamente durante la división).
	
	direction : np.ndarray
		Vector de dirección (2D o 3D) usado para dividir los puntos en este nodo.
	
	medianPoint : np.ndarray
		Punto espacial correspondiente a la mediana proyectada, usado como referencia de corte.
	
	parent : Optional[HSTNode]
		Referencia al nodo padre en el árbol, si existe.
	
	left : Optional[HSTNode]
		Nodo hijo izquierdo (contiene los puntos con proyección menor a la mediana).
	
	right : Optional[HSTNode]
		Nodo hijo derecho (contiene los puntos con proyección mayor o igual a la mediana).
	"""
	
	def __init__(self):
		self.root: Optional['HSTNode'] = None
		self.height: int = 0.0

		self.points: List[np.ndarray] = []  

		self.medianProj: float
		self.direction: np.ndarray = np.zeros(3)  
		self.medianPoint: np.ndarray = np.zeros(3)

		self.parent: Optional['HSTNode'] = None

		self.left: Optional['HSTNode'] = None
		self.right: Optional['HSTNode'] = None

