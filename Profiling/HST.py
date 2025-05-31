from typing import List, Optional
from HSTNode import HSTNode
import numpy as np
import random
import math


class HamSandwichTree:
	"""
	Representa un árbol de tipo 'Ham Sandwich Tree', que divide recursivamente un conjunto de puntos
	en 2D o 3D usando cortes balanceados en direcciones aleatorias.
	"""

	def __init__(self, is3D: bool, quantity: int = 100, boundary: float = 10):
		"""
		Inicializa el árbol con los parámetros dados.

		Parámetros:
		-----------
		is3D : bool
			Si es True, se generarán puntos en 3D. Si es False, serán en 2D.
		quantity : int
			Número de puntos a generar al iniciar el árbol.
		boundary : float
			Límite máximo (en valor absoluto) para las coordenadas de los puntos.
		"""
		self.is3D = is3D    
		self.quantity = quantity
		self.boundary = boundary
		self.points: List[np.ndarray] = [] 
		self.root: Optional[HSTNode] = None
	#main

	def Start(self):
		"""
		Método principal para iniciar la construcción del árbol.
		Genera puntos aleatorios y crea el árbol a partir de ellos.
		"""
		random.seed()
		self.SpawnRandomPoints(self.quantity, self.boundary)
		self.CreateTree()

	def CreateTree(self):
		"""
		Inicializa el nodo raíz del árbol con todos los puntos generados
		y llama al proceso recursivo para construir el árbol completo.
		"""
		self.root = self.CreateNode()
		self.root.points = self.points
		self.CreateTreeAux(self.root)

	def CreateTreeAux(self, node: HSTNode):
		"""
		Construcción recursiva del árbol. Detiene la recursión si el nodo tiene menos de 5 puntos.

		Parámetros:
		-----------
		node : HSTNode
			Nodo actual a subdividir recursivamente.
		"""
		if len(node.points) < 5:
			return
		self.SplitPoints(node)
		self.CreateTreeAux(node.left)
		self.CreateTreeAux(node.right)

	def CreateNode(self, parent: Optional[HSTNode] = None) -> HSTNode:
		"""
		Crea un nuevo nodo del árbol, conectándolo a su padre si se proporciona.

		Parámetros:
		-----------
		parent : Optional[HSTNode]
			Nodo padre del nuevo nodo (si existe).

		Retorna:
		--------
		HSTNode
			Nodo recién creado.
		"""
		newNode = HSTNode()
		newNode.root = self.root
		newNode.parent = parent
		if parent is not None:
			newNode.height = parent.height + 1
		return newNode

	def SpawnRandomPoints(self, quantity: int, boundary: float):
		"""
		Genera puntos aleatorios dentro de los límites dados. Si `is3D` es False, los puntos serán en 2D.

		Parámetros:
		-----------
		quantity : int
			Número total de puntos a generar.
		boundary : float
			Límite absoluto en cada eje para las coordenadas de los puntos.
		"""
		for i in range(quantity):
			x = random.uniform(-boundary, boundary)
			y = random.uniform(-boundary, boundary)
			z = 0.0
			if self.is3D:
				z = random.uniform(-boundary, boundary)
				
			pos = np.array([x, y, z], dtype=float)
			self.points.append(pos)

	# HAM SANDWICH ALGORITHM 
	def SplitPoints(self, node: HSTNode):
		"""
		Aplica el algoritmo de corte Ham Sandwich para dividir los puntos del nodo en dos subconjuntos,
		usando una dirección aleatoria.

		Parámetros:
		-----------
		node : HSTNode
			Nodo actual cuyos puntos serán divididos en dos mitades.
		"""
		theta = random.uniform(0, math.pi)
		phi = random.uniform(0, math.pi)

		if self.is3D:
			direction = np.array([
				math.cos(theta) * math.sin(phi),
				math.sin(theta) * math.sin(phi),
				math.cos(phi)
			], dtype=float)
		else:
			direction = np.array([
				math.cos(theta),
				math.sin(theta),
				0.0
			], dtype=float)

		projections = [{'point': p, 'projection': np.dot(p, direction)} for p in node.points]
		projections.sort(key=lambda e: e['projection'])

		median_index = len(projections) // 2
		medianPoint = projections[median_index]['point']
		medianProj = projections[median_index]['projection']

		rightPoints: List[np.ndarray] = []
		leftPoints: List[np.ndarray] = []

		for element in projections:
			if element['projection'] >= medianProj:
				rightPoints.append(element['point'])
			else:
				leftPoints.append(element['point'])

		node.left = self.CreateNode(node)
		node.right = self.CreateNode(node)
		node.left.points = leftPoints
		node.right.points = rightPoints
		node.direction = direction
		node.medianPoint = medianPoint
		node.medianProj = medianProj



